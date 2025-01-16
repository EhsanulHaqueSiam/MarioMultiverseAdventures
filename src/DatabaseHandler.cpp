#include "../include/DatabaseHandler.h"
#include <iostream>
#include <stdexcept>

DatabaseHandler& DatabaseHandler::getInstance() {
    static DatabaseHandler instance;
    return instance;
}

void DatabaseHandler::initialize(const std::string& dbFile) {
    std::lock_guard<std::mutex> lock(mutex);
    int resultCode = sqlite3_open(dbFile.c_str(), &db);
    checkSQLiteError(resultCode, "Can't open database");

    const auto createTableSQL = "CREATE TABLE IF NOT EXISTS HighScores ("
                                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                 "PlayerName TEXT NOT NULL, "
                                 "Score INTEGER NOT NULL);";
    char* errMsg = nullptr;
    resultCode = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg);
    if (resultCode != SQLITE_OK) {
        const std::string error = errMsg;
        sqlite3_free(errMsg);
        throw std::runtime_error("Can't create table: " + error);
    }
}

void DatabaseHandler::insertHighScore(const std::string& playerName, const int score) {
    std::lock_guard<std::mutex> lock(mutex);
    const auto insertSQL = "INSERT INTO HighScores (PlayerName, Score) VALUES (?, ?);";
    sqlite3_stmt* stmt;
    int resultCode = sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr);
    checkSQLiteError(resultCode, "Can't prepare statement");

    sqlite3_bind_text(stmt, 1, playerName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, score);
    resultCode = sqlite3_step(stmt);
    if (resultCode != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw std::runtime_error("Can't execute statement: " + std::string(sqlite3_errmsg(db)));
    }
    sqlite3_finalize(stmt);
}

std::vector<std::pair<std::string, int>> DatabaseHandler::getHighScores() {
    std::lock_guard<std::mutex> lock(mutex);
    std::vector<std::pair<std::string, int>> highScores;
    const auto selectSQL = "SELECT PlayerName, Score FROM HighScores ORDER BY Score DESC;";
    sqlite3_stmt* stmt;
    const int resultCode = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, nullptr);
    checkSQLiteError(resultCode, "Can't prepare statement");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string playerName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        int score = sqlite3_column_int(stmt, 1);
        highScores.emplace_back(playerName, score);
    }
    sqlite3_finalize(stmt);
    return highScores;
}

DatabaseHandler::~DatabaseHandler() {
    if (db) {
        sqlite3_close(db);
    }
}

void DatabaseHandler::checkSQLiteError(const int resultCode, const std::string& errorMessage) const
{
    if (resultCode != SQLITE_OK) {
        throw std::runtime_error(errorMessage + ": " + std::string(sqlite3_errmsg(db)));
    }
}

#include "../include/DatabaseHandler.h"
#include <fstream>

const std::string DatabaseHandler::dbFileName = "highscores.db";

DatabaseHandler& DatabaseHandler::getInstance() {
    static DatabaseHandler instance;
    return instance;
}

void DatabaseHandler::initialize() {
    std::lock_guard<std::mutex> lock(mutex);

    // Check if the database file exists
    std::ifstream dbFile(dbFileName);
    const bool dbExists = dbFile.good();
    dbFile.close();

    int resultCode = sqlite3_open(dbFileName.c_str(), &db);
    checkSQLiteError(resultCode, "Can't open database");

    if (!dbExists) {
        // Create the table if the database file did not exist
        const auto createTableSQL = "CREATE TABLE IF NOT EXISTS HighScores ("
                                    "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                    "Score INTEGER NOT NULL);";
        char* errMsg = nullptr;
        resultCode = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg);
        if (resultCode != SQLITE_OK) {
            const std::string error = errMsg;
            sqlite3_free(errMsg);
            throw std::runtime_error("Can't create table: " + error);
        }
    }
}

void DatabaseHandler::insertHighScore(const int score) {
    std::lock_guard<std::mutex> lock(mutex);
    const auto insertSQL = "INSERT INTO HighScores (Score) VALUES (?);";
    sqlite3_stmt* stmt;
    int resultCode = sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr);
    checkSQLiteError(resultCode, "Can't prepare statement");

    sqlite3_bind_int(stmt, 1, score);
    resultCode = sqlite3_step(stmt);
    if (resultCode != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw std::runtime_error("Can't execute statement: " + std::string(sqlite3_errmsg(db)));
    }
    sqlite3_finalize(stmt);
}

void DatabaseHandler::deleteHighScore(const int id) {
    std::lock_guard<std::mutex> lock(mutex);
    const auto deleteSQL = "DELETE FROM HighScores WHERE ID = ?;";
    sqlite3_stmt* stmt;
    int resultCode = sqlite3_prepare_v2(db, deleteSQL, -1, &stmt, nullptr);
    checkSQLiteError(resultCode, "Can't prepare statement");

    sqlite3_bind_int(stmt, 1, id);
    resultCode = sqlite3_step(stmt);
    if (resultCode != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw std::runtime_error("Can't execute statement: " + std::string(sqlite3_errmsg(db)));
    }
    sqlite3_finalize(stmt);
}

void DatabaseHandler::updateHighScore(const int id, const int score) {
    std::lock_guard<std::mutex> lock(mutex);
    const auto updateSQL = "UPDATE HighScores SET Score = ? WHERE ID = ?;";
    sqlite3_stmt* stmt;
    int resultCode = sqlite3_prepare_v2(db, updateSQL, -1, &stmt, nullptr);
    checkSQLiteError(resultCode, "Can't prepare statement");

    sqlite3_bind_int(stmt, 1, score);
    sqlite3_bind_int(stmt, 2, id);
    resultCode = sqlite3_step(stmt);
    if (resultCode != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw std::runtime_error("Can't execute statement: " + std::string(sqlite3_errmsg(db)));
    }
    sqlite3_finalize(stmt);
}

std::vector<std::pair<int, int>> DatabaseHandler::getHighScores() {
    std::lock_guard<std::mutex> lock(mutex);
    std::vector<std::pair<int, int>> highScores;
    const auto selectSQL = "SELECT ID, Score FROM HighScores ORDER BY Score DESC;";
    sqlite3_stmt* stmt;
    const int resultCode = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, nullptr);
    checkSQLiteError(resultCode, "Can't prepare statement");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        int score = sqlite3_column_int(stmt, 1);
        highScores.emplace_back(id, score);
    }
    sqlite3_finalize(stmt);
    return highScores;
}

DatabaseHandler::~DatabaseHandler() {
    if (db) {
        sqlite3_close(db);
    }
}

void DatabaseHandler::checkSQLiteError(const int resultCode, const std::string& errorMessage) const {
    if (resultCode != SQLITE_OK) {
        throw std::runtime_error(errorMessage + ": " + std::string(sqlite3_errmsg(db)));
    }
}
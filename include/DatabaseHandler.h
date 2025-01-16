// include/DatabaseHandler.h
#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <sqlite3.h>
#include <string>
#include <vector>
#include <mutex>
#include <stdexcept>

class DatabaseHandler {
public:
    static DatabaseHandler& getInstance();
    void initialize(const std::string& dbFile);
    void insertHighScore(const std::string& playerName, int score);
    std::vector<std::pair<std::string, int>> getHighScores();

    DatabaseHandler(const DatabaseHandler&) = delete;
    DatabaseHandler& operator=(const DatabaseHandler&) = delete;

private:
    DatabaseHandler() = default;
    ~DatabaseHandler();

    void checkSQLiteError(int resultCode, const std::string& errorMessage) const;

    sqlite3* db = nullptr;
    std::mutex mutex;
};

#endif // DATABASEHANDLER_H
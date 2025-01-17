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
    void initialize();
    void insertHighScore(const std::string& playerName, int score);
    void deleteHighScore(int id);
    void updateHighScore(int id, const std::string& playerName, int score);
    std::vector<std::pair<int, std::pair<std::string, int>>> getHighScores();

    DatabaseHandler(const DatabaseHandler&) = delete;
    DatabaseHandler& operator=(const DatabaseHandler&) = delete;

private:
    DatabaseHandler() = default;
    ~DatabaseHandler();

    void checkSQLiteError(int resultCode, const std::string& errorMessage) const;

    static const std::string dbFileName;
    sqlite3* db = nullptr;
    std::mutex mutex;
};

#endif // DATABASEHANDLER_H
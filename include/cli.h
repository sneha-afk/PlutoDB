#pragma once

#include <map>
#include <string>
#include <vector>

static constexpr unsigned int QUERY_LIMIT = 10000;

static constexpr int UNKNOWN_CMD = -1;

enum class Keyword {
    SELECT,
    CREATE,
    INSERT,
    DELETE,
    REPLACE,
    DROP,
    UPDATE,
    TRUNCATE,
    ALTER,
    COMMIT,
    ROLLBACK,
};

static std::map<std::string, Keyword> keywordMap { { "SELECT", Keyword::SELECT },
    { "CREATE", Keyword::CREATE }, { "INSERT", Keyword::INSERT },
    { "DELETE", Keyword::DELETE }, { "REPLACE", Keyword::REPLACE },
    { "DROP", Keyword::DROP }, { "UPDATE", Keyword::UPDATE },
    { "TRUNCATE", Keyword::TRUNCATE }, { "ALTER", Keyword::ALTER },
    { "COMMIT", Keyword::COMMIT }, { "ROLLBACK", Keyword::ROLLBACK } };

enum class Shell { QUIT, HELP, ABOUT };

static std::map<std::string, Shell> commandMap {
    { "\\q", Shell::QUIT },
    { "\\h", Shell::HELP },
    { "\\about", Shell::ABOUT },
};

std::vector<std::string> &parseTokens(std::vector<std::string> &, std::string &);
std::vector<std::string> &capitalizeTokens(std::vector<std::string> &);

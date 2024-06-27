#pragma once

#include <set>
#include <string>
#include <vector>

static constexpr unsigned int QUERY_LIMIT = 10000;

static std::set<std::string> KEYWORDS = { "SELECT", "CREATE", "INSERT", "DELETE",
    "REPLACE", "DROP", "UPDATE", "TRUNCATE", "ALTER", "COMMIT", "ROLLBACK" };

std::vector<std::string> &parseTokens(std::vector<std::string> &, std::string &);

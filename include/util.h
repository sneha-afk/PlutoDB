#pragma once

#include "custom_exceptions.h"

#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <vector>

std::string &strToUpper(std::string &);

std::string rightTrim(std::string &s);
std::string rightTrim(std::string &s, char &trim);
std::string rightTrim(std::string &s, std::string &trim);

// Retrieve command from a map of string-to-enum, throws PEInvalidCmd if not found
template <typename T>
T getCommand(const std::map<std::string, T> &cmdMap, const std::string &key) {
    auto pair = cmdMap.find(key);

    if (pair != cmdMap.end()) return pair->second;

    throw PEInvalidCmd(key);
}

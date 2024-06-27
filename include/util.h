#pragma once

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

std::string &strToUpper(std::string &);

std::string rightTrim(std::string &s);
std::string rightTrim(std::string &s, char &trim);
std::string rightTrim(std::string &s, std::string &trim);

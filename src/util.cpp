#include "util.h"

// Sets a string to all uppercase in-place
std::string &strToUpper(std::string &s) {
    // https://stackoverflow.com/a/735215
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

// Trim whitespace off the right
std::string rightTrim(std::string &s) {
    size_t end = s.find_last_not_of(' ');
    return (end != std::string::npos) ? s.substr(0, end + 1) : "";
}

// Trim a character off the end of a string
std::string rightTrim(std::string &s, char &trim) {
    size_t end = s.find_last_not_of(trim);
    return (end != std::string::npos) ? s.substr(0, end + 1) : "";
}

// Trim a sequence off the end of a string
std::string rightTrim(std::string &s, std::string &trim) {
    size_t end = s.find_last_not_of(trim);
    return (end != std::string::npos) ? s.substr(0, end + 1) : "";
}

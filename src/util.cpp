#include "util.h"

#include <functional>
#include <vector>

// Sets a string to all uppercase in-place
std::string &strToUpper(std::string &s) {
    // https://stackoverflow.com/a/735215
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

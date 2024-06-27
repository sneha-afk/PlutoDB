#include "cli.h"

#include <algorithm>

std::string &strToUpper(std::string &s) {
    // https://stackoverflow.com/a/735215
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

std::vector<std::string> &parseTokens(
    std::vector<std::string> &tokens, std::string &str) {
    tokens.clear();

    // Disable checking later if applicable
    bool anyStrings = (str.find('"', 0) != std::string::npos)
                      || (str.find('\'', 0) != std::string::npos);

    int start = 0, end = 1;
    while (start != std::string::npos && start < str.size()) {
        end = str.find(' ', start);
        if (end == std::string::npos) {
            end = str.size();
        }

        if (anyStrings) {
            int quote = end;
            if (((quote = str.find('"', start)) != std::string::npos
                    || (quote = str.find('\'', start)) != std::string::npos)
                && quote <= end) {
                // Handle the token before the string and the string itself (include quotes)
                std::string before = str.substr(start, quote - start);

                int after = str.find('"', quote + 1);
                if (after == std::string::npos) {
                    after = str.find('\'', quote + 1);
                }
                std::string string = str.substr(quote, after - quote + 1);

                if (!before.empty()) {
                    tokens.push_back(strToUpper(before));
                }
                tokens.push_back(string);
                start = after + 2;
                continue;
            }
        }

        std::string token = str.substr(start, end - start);
        tokens.push_back(strToUpper(token));
        start = end + 1;
    }

    return tokens;
}

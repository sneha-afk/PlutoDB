#include "cli.h"

#include "custom_exceptions.h"
#include "util.h"

#include <algorithm>

/*
 * Separate an input line by space delimited tokens, keeping strings
 * that are denoted with "" or '' together.
 */
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

                int after = str.find(str[quote], quote + 1);

                // Unexpected quotation mark was found
                if (after == std::string::npos) {
                    throw PESyntax(str, quote);
                }

                std::string string = str.substr(quote, after - quote + 1);

                if (!before.empty()) {
                    tokens.push_back(before);
                }
                tokens.push_back(string);
                start = after + 2;
                continue;
            }
        }

        std::string token = str.substr(start, end - start);
        tokens.push_back(token);
        start = end + 1;
    }

    return tokens;
}

// Capitalize tokens that are not case-sensitive strings or shell commands.
std::vector<std::string> &capitalizeTokens(std::vector<std::string> &tokens) {
    for (auto &t : tokens) {
        if (t.empty()) continue;
        switch (t[0]) {
            case '"':
            case '\'':
            case '\\': continue;
            default: strToUpper(t);
        }
    }
    return tokens;
}

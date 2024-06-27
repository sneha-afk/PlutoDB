#include "cli.h"
#include "custom_exceptions.h"
#include "util.h"

#include <iostream>

int main(int argc, char const *argv[]) {
    std::string input;
    std::vector<std::string> tokens;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input.empty()) continue;

        try {
            tokens = capitalizeTokens(parseTokens(tokens, input));
        } catch (const Plutoception &e) {
            std::cerr << e.what() << std::endl;
            continue;
        }

        if (tokens[0] == "\\q") break;
    }
    std::cout << "Logging off..." << std::endl;
    return EXIT_SUCCESS;
}

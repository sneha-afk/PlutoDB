#include "cli.h"

#include <iostream>

int main(int argc, char const *argv[]) {
    std::string input;
    std::vector<std::string> tokens;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (!input.empty()) {
            tokens = parseTokens(tokens, input);
        }
    }
    return EXIT_SUCCESS;
}

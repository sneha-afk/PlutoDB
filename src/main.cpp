#include "cli.h"
#include "custom_exceptions.h"
#include "messages.h"
#include "util.h"

#include <iostream>

int main(int argc, char const *argv[]) {
    std::string input;
    std::vector<std::string> tokens;

    std::cout << ASCII_LOGO << "\nWelcome! Type " << TERM_BLUE << "\\h"
              << TERM_RESET " for help!" << std::endl;
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

        std::string &command = tokens[0];

        if (command[0] == '\\') {
            try {
                Shell shell = getCommand(shellMap, command);
                switch (shell) {
                    case Shell::QUIT: goto exit; break;
                    case Shell::KEYWLIST:
                        std::cout << SUPPORTED_KEYW << std::endl;
                    case Shell::HELP:
                    default: std::cout << HELP_MSG << std::endl; break;
                }
            } catch (const Plutoception &e) {
                std::cerr << e.what() << std::endl;
                continue;
            }
        } else {
            try {
                Keyword keyw = getCommand(keywordMap, command);
                switch (keyw) {
                    case Keyword::CREATE:
                    case Keyword::SELECT:
                    case Keyword::UPDATE:
                    case Keyword::INSERT:
                    case Keyword::DELETE:
                    case Keyword::REPLACE:
                    case Keyword::DROP:
                    case Keyword::TRUNCATE:
                    case Keyword::ALTER:
                    case Keyword::BEGIN:
                    case Keyword::COMMIT:
                    case Keyword::ROLLBACK: throw PEUnsupportedKeyw(command); break;
                    default: std::cout << HELP_MSG << std::endl; break;
                }
            } catch (const Plutoception &e) {
                std::cerr << e.what() << std::endl;
                continue;
            }
        }
    }
exit:
    std::cout << "Logging off..." << std::endl;
    return EXIT_SUCCESS;
}

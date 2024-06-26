#pragma once

#include <sstream>
#include <stdexcept>
#include <string>

// https://stackoverflow.com/q/5947742
#define TERM_RED   "\033[1;31m"
#define TERM_BLUE  "\033[0;34m"
#define TERM_RESET "\033[0m"

// https://stackoverflow.com/a/41753612
// https://rollbar.com/blog/cpp-custom-exceptions/

class Plutoception : public std::exception {
protected:
    std::string msg_;

public:
    Plutoception(const std::string &msg)
        : msg_(TERM_RED + std::string("Plutoexception: " + msg) + TERM_RESET) { }

    const char *what() const noexcept override { return msg_.c_str(); }
};

class PESyntax : public Plutoception {
public:
    PESyntax(const std::string &line, const unsigned int &pos)
        : Plutoception("") {
        std::ostringstream fmt;
        fmt << TERM_RED << "Plutoexception: syntax error\n\t" << TERM_RESET << line
            << "\n\t" << std::string(pos, ' ') << "^\n";
        msg_ = fmt.str();
    }
};

class PEInvalidCmd : public Plutoception {
public:
    PEInvalidCmd(const std::string &cmd)
        : Plutoception("") {
        std::ostringstream fmt;
        fmt << TERM_RED << "Plutoexception: invalid command" << TERM_RESET << ": \""
            << cmd << "\" is unknown"
            << "\n\t" << TERM_BLUE << "Enter \\h for help!\n"
            << TERM_RESET;
        msg_ = fmt.str();
    }
};

class PEUnsupportedKeyw : public Plutoception {
public:
    PEUnsupportedKeyw(const std::string &kw)
        : Plutoception("") {
        std::ostringstream fmt;
        fmt << TERM_RED << "Plutoexception: unsupported keyword" << TERM_RESET << ": \""
            << kw << "\" is currently unspported"
            << "\n\t" << TERM_BLUE << "Enter \\keyw for a list of supported keywords!\n"
            << TERM_RESET;
        msg_ = fmt.str();
    }
};

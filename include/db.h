#pragma once

#include <string>

#include "db_memory.h"

class DB {
private:
    DBMemory mem_;

public:
    DB();
    DB(const unsigned int &);

    bool loadFile(const std::string &);
    bool writeFile(const std::string &);
};

#pragma once

#include <vector>
#include "table.h"

static constexpr unsigned int MB_SIZE = 1000000;

class DBMemory {
protected:
    std::vector<Table> tables;

public:
    DBMemory();
    DBMemory(const unsigned int &);

    void clear();
};

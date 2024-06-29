#pragma once

#include <vector>
#include <string>

#include "record.h"

class Table {
protected:
    std::vector<Record> records_;
    std::string name_;
};

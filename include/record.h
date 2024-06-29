#pragma once

#include <string>
#include <map>

#include "field.h"
#include <vector>

class Record {
protected:
    std::map<std::string, Field> fields;

public:
    Record(std::string &, std::vector<Field> &);

    void updateField(const std::string &, Field &);
};

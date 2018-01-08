//
// Created by Shaun Baker on 08.01.18.
//


#include <cstdint>
#include <sstream>
#include <string>

#include "record.h"

util::Record::Record(uint64_t id, std::string value) : id(id),value(value) {}

std::string util::Record::to_string() const
{
    std::ostringstream css;
    css << id << ":" << value;
    return css.str();
}

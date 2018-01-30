//
// Created by Shaun Baker on 11.01.18.
//

#ifndef CODE_CRITIQUE_MEAL_H
#define CODE_CRITIQUE_MEAL_H

#pragma once
#include <iosfwd>
#include <sstream>
#include <string>
enum class meal : int
{
    breakfast, lunch, dinner,
};
// Used for name <=> value conversion
struct
{
    meal value;
    std::string name;
} names[] =
        {
                { meal::breakfast, "breakfast" },
                { meal::lunch, "lunch" },
                { meal::dinner, "dinner" },
        };
std::istream &operator>>(std::istream &is,
                         meal &m)
{
    std::string name;
    if (is >> name)
    {
        for (auto p : names)
        {
            if (p.name == name)
                m = p.value;
        }
    }
    return is;
}
std::ostream &operator<<(std::ostream &os,
                         meal const m)
{
    for (auto p : names)
    {
        if (p.value == m)
            os << p.name;
    }
    return os;
}
// Type-safe operations
constexpr meal operator+(meal a, meal b)
{
    return meal(int(a) + int(b));
}
meal operator+=(meal &a, meal b)
{
    a = a + b;
    return a;
}
constexpr meal operator|(meal a, meal b)
{
    return meal(int(a) | int(b));
}
constexpr meal operator&(meal a, meal b)
{
    return meal(int(a) & int(b));
}
// Check distinctness
static_assert((meal::breakfast | meal::lunch |
               meal::dinner) == (meal::breakfast +
                                 meal::lunch + meal::dinner), "not distinct");

#endif //CODE_CRITIQUE_MEAL_H

//
// Created by Shaun Baker on 24.01.18.
//
#include "date.h"
#include <iostream>
using namespace std;

// Read using YYYY-MM-DD format
void Date::readDate()
{
    cin >> year;
    cin.get();
    cin >> month;
    cin.get();
    cin >> day;
}

// Print using YYYY-MM-DD format
void Date::printDate()
{
    cout << "Date: " << year << '-' << month/10 << month%10 << '-' << day/10 << day%10;
}

void Date::addDate(Date lhs, Date rhs)
{
    year = lhs.year + rhs.year;
    month = lhs.month + rhs.month;
    day = lhs.day + rhs.day;

    //first pass at the day -- no months are over 31 days
}

bool Date::leapYear()
{

}
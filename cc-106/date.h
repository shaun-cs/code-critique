//
// Created by Shaun Baker on 24.01.18.
//

#ifndef CODE_CRITIQUE_DATE_H
#define CODE_CRITIQUE_DATE_H

#pragma once

class Date
{
    int year;
    int month;
    int day;

public:
    void readDate();
    void printDate();
    void addDate(Date lhs, Date rhs);
    bool leapYear();
};

#endif //CODE_CRITIQUE_DATE_H

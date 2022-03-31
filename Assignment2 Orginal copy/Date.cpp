#include "Date.h"
#include <iostream>
#include <string>

Date::Date()
{
    day = 14;
    month = 10;
    year = 2017;
}

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

Date::~Date()
{

}

//setters
void Date::setDay (int d)
{
    day = d;
}
void Date::setMonth (int m)
{
    month = m;
}
void Date::setYear (int y)
{
    year = y;
}
void Date::setDate (int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

//getters
int Date::getDay () const
{
    return day;
}
int Date::getMonth () const
{
    return month;
}
int Date::getYear () const
{
    return year;
}

//printf
void Date::print() const
{
    cout << day << "  " << month << "  " << year << "  "<<endl;
}

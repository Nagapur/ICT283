#include "DATE.H"
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

Date::Date()
{
    day = 0;
    month = 0;
    year =0;
}

Date::Date(int xDay,int xMonth, int xYear)
{
    day = xDay;
    month = xMonth;
    year = xYear;
}

int Date::GettingDay() const
{
    return day;
}

void Date::SetDay(const int &xDay)
{
    day = xDay;
}

int Date::GettingMonth() const
{
    return month;
}

void Date::SetMonth(const int &xMonth)
{
    month = xMonth;
}

int  Date::GettingYear() const
{
    return year;
}

void Date::SetYear(const int &xYear)
{
    year = xYear;
}


ostream & operator <<( ostream & os, const Date & D )
{

    os <<"Date:"<<D.GettingDay()<<"/"<< D.GettingMonth()<<"/"<<D.GettingYear();

    return os;
}

bool Date::operator < (const Date &D) const
{
        if ((year<D.GettingYear())||
            (year==D.GettingYear() && month<D.GettingMonth())||
            (year==D.GettingYear() && month==D.GettingMonth() && day<D.GettingDay()))
                return true;
        else
                return false;
}



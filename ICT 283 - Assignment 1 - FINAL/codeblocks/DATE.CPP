#include "DATE.H"
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

Date::Date()
{
    day = 1;
    month = 1;
    year =1800;
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



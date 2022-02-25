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

void Date::SetDay(const unsigned &xDay)
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

/*istream & operator >>( istream & input, Date & D )
{

  return input;
}*/

ostream & operator <<( ostream & os, const Date & D )
{
    /*int day;
    int month;
    int year;
    D.GetDay(day);
    D.GetMonth(month);
    D.GetYear(year);*/


  os <<"Date:"<<D.GettingDay()<<"/"<< D.GettingMonth()<<"/"<<D.GettingYear();

  return os;
}



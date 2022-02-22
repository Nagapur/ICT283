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

void Date::GetDay(int &xDay) const
{
    xDay = day;
}

 int Date::GettingDay() const
{
    return day;
}

void Date::SetDay(const unsigned &xDay)
{
    day = xDay;
}

void Date::GetMonth(int &xMonth) const
{
    xMonth = month;
}

int Date::GettingMonth() const
{
    return month;
}

void Date::SetMonth(const int &xMonth)
{
    month = xMonth;
}

void Date::GetYear(int &xYear) const
{
    xYear = year;
}

int  Date::GettingYear() const
{
    return year;
}

void Date::SetYear(const int &xYear)
{
    year = xYear;
}

istream & operator >>( istream & input, Date & D )
{


  /*string SaveInput;
  getline(input,SaveInput, '/');
  stringstream container (SaveInput);
  int x;
  container >> x;
  D.SetDay(x);


  getline(input,SaveInput, '/');
  stringstream container2 (SaveInput);
  int y;
  container2 >> y;
  D.SetMonth(y);


  getline(input,SaveInput , ' ');

  stringstream container3 (SaveInput);
  int z;
  container3 >> z;
  D.SetYear(z);*/

  return input;
}

ostream & operator <<( ostream & os, const Date & D )
{
    int day;
    int month;
    int year;
    D.GetDay(day);
    D.GetMonth(month);
    D.GetYear(year);


  os <<"Date:"<< day<<"/"<< month<<"/"<<year;

  return os;
}



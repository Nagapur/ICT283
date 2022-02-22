#include "TIME.H"
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

Time::Time()
{
    hour = 0;
    minute = 0;

}

Time::Time(int hrs, int mins)
{
    hour = hrs;
    minute = mins;
}

int Time::GettingHour()const
{
    return hour;
}

void Time::GetHour(int &xHour) const
{
    xHour = hour;
}

int Time::GettingMin()const
{
    return minute;
}

void Time::GetMin(int &xMin) const
{
    xMin = minute;
}

void Time::SetHour(const int &xHour)
{
    hour = xHour;
}

void Time::SetMin(const int &xMin)
{
    minute = xMin;
}

istream & operator >>( istream & input, Time & T )
{
 /* string SaveInput;
  getline(input,SaveInput, ':');
  stringstream container (SaveInput);
  int x;
  container >> x;
  T.SetHour(x);


  getline(input,SaveInput, ',');
  stringstream container2 (SaveInput);
  int y;
  container2 >> y;
  T.SetMin(y);*/

  return input;
}

ostream & operator <<( ostream & os, const Time & T )
{
    int m_hour;
    int m_min;

    T.GetHour(m_hour);
    T.GetMin(m_min);


  os <<"Time:"<<m_hour<<":"<< m_min;

  return os;
}

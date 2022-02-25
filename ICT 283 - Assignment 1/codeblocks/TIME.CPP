#include "TIME.H"
#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip>

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


  return input;
}

ostream & operator <<( ostream & os, const Time & T )
{
    int m_hour;
    int m_min;

    T.GetHour(m_hour);
    T.GetMin(m_min);
    auto oldfill = os.fill('0');


  os <<"Time:"<<m_hour<<":"<< setw(2)<<m_min<<setfill(oldfill);

  return os;
}

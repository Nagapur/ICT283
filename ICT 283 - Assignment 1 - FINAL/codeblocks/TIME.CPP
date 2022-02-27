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

int Time::GettingMin()const
{
    return minute;
}

void Time::SetHour(const int &xHour)
{
    hour = xHour;
}

void Time::SetMin(const int &xMin)
{
    minute = xMin;
}


ostream & operator <<( ostream & os, const Time & T )
{

    auto oldfill = os.fill('0');

  os <<"Time:"<<T.GettingHour()<<":"<< setw(2)<<T.GettingMin()<<setfill(oldfill);

  return os;
}

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

void Time::SetHour(const int &xHour)
{
    hour = xHour;
}

int Time::GettingMin()const
{
    return minute;
}

void Time::SetMin(const int &xMin)
{
    minute = xMin;
}

string Time::GetTimeString() const
{
    stringstream ss;

    string fullTime;
    ss << "" << hour << ":" << std::setfill('0') << std::setw(2)<< minute << "";
    fullTime=ss.str();
    return fullTime;
}


ostream & operator <<( ostream & os, const Time & T )
{

    //fill the blank space with a 0 to show the time properly with 4 digits in total
    auto oldfill = os.fill('0');

    os <<"Time:"<<T.GettingHour()<<":"<< setw(2)<<T.GettingMin()<<setfill(oldfill);

    return os;
}

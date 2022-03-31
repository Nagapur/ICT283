#include "Time.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

Time::Time()
{
    hour = 12;
    minutes = 12;
}

Time::Time(int hr,int mins)
{
    hour = hr;
    minutes = mins;
}

Time::~Time()
{

}

//setters
void Time::setHr(int hr)
{
    hour = hr;
}

void Time::setMins(int mins)
{
    minutes = mins;
}

void Time::setTime(int hr, int mins)
{
    hour =hr;
    minutes =mins;
}

//getters
int Time::getHr() const
{
    return hour;
}
int Time::getMins()const
{
    return minutes;
}

string Time::getFTime() const
{
    stringstream ss;

    string theFullThing;
    ss << "" << hour << ": " << std::setfill('0') << std::setw(2)<< minutes << "";
    theFullThing=ss.str();
    return theFullThing;
}

//print
void Time::print() const
{
    cout << hour << ": " << std::setfill('0') << std::setw(2)<< minutes << "" << endl;
}

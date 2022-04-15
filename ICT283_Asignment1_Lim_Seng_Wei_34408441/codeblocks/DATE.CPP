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

/*void Date::AddPtr(Vector<Date*> &tempVec, const int day, int month, int year)
{
    int currentInt=-1;
    bool found = false;
    Date* datePtr;
    int indexFound = -1;

    for (int i = 0; i<tempVec.GetSize(); i++)
    {
        currentInt= tempVec.At(i)->GettingDay();
        //currentInt= tempVec.At(i)->GettingMonth();
        //currentInt= tempVec.At(i)->GettingYear();

        if(currentInt == day)
        {
            found = true;
            indexFound = i;
            break;
        }
    }

    if(found)
    {
        datePtr = tempVec.At(indexFound);
    }

    else
    {
        datePtr= new Date (day,month,year);
    }

    tempVec.Add(datePtr);
}*/



#include "WINDLOGTYPE.H"
#include "DATE.H"
#include "TIME.H"
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

WindLogType::WindLogType()
{

    speed = 0;
    solarRadiation =0;
    temperature =0;
}

WindLogType::WindLogType(Date Da,  Time Ti, float xSpeed, float xSolarRadiation, float xTemperature)
{

    d=Da;
    t=Ti;
    speed = xSpeed;
    solarRadiation = xSolarRadiation;
    temperature = xTemperature;
}

void WindLogType::GetDate(Date &da) const
{

    da = d;
}

void WindLogType::GetTime(Time &ti) const
{

    ti=t;
}

void WindLogType::SetDay(const int &xDay)
{

    d.SetDay(xDay);
}

void WindLogType::SetMonth(const int &xMonth)
{

    d.SetMonth(xMonth);
}

void WindLogType::SetYear(const int &xYear)
{

    d.SetYear(xYear);
}

void WindLogType::SetHour(const int &xHour)
{

    t.SetHour(xHour);
}

void WindLogType::SetMin(const int &xMin)
{

    t.SetMin(xMin);

}

int WindLogType::GetDay() const
{

   return d.GettingDay();
}


int WindLogType::GetMonth() const
{

   return d.GettingMonth();
}

int WindLogType::GetYear() const
{
   return d.GettingYear();
}

float WindLogType::GetSpeed() const
{

   return speed;
}

void WindLogType::SetSpeed(const float &xSpeed)
{

   speed = xSpeed;
}

float WindLogType::GetSolarRad() const
{

   return solarRadiation;
}

void WindLogType::SetSolarRad(const float &xSolarR)
{

   solarRadiation = xSolarR;
}

float WindLogType::GetTemp() const
{

   return temperature;
}

void WindLogType::SetTemp(const float &xTemp)
{

   temperature = xTemp;
}



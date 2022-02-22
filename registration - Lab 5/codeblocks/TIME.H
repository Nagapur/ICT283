#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>
#include <string.h>

using namespace std;

class Time

{
    public:
    Time();
    Time(int hrs, int mins);
    int  GettingHour()const;
   void GetHour(int &xHour) const;
    void SetHour( const int &xHour );
    //void GetMonth(int &xMonth )const;
    int GettingMin()const;
    void GetMin(int &xMin) const;
    void SetMin( const int &xMinute );

    private:
    int hour;
    int minute;

};

  istream & operator >>( istream & input, Time & T );
  ostream & operator <<( ostream & os, const Time & T );

#endif // TIME_H_INCLUDED

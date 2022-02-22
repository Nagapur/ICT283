#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
#include <string.h>



using namespace std;

class Date
{
public:
    Date();
    Date(int xDay, int xMonth, int xYear);
    void GetDay(int &xDay )const;
    int  GettingDay()const;
    void SetDay( const unsigned &xDay );
   void GetMonth(int &xMonth )const;
     int GettingMonth()const;
    void SetMonth( const int &xMonth );
  void GetYear(int &xYear )const;
   int  GettingYear()const;
    void SetYear( const int &xYear );

private:
    int day;
    int month;
    int year;
};

  istream & operator >>( istream & input, Date & D );
  ostream & operator <<( ostream & os, const Date & D );


#endif // DATE_H_INCLUDED

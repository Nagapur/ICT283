// MAIN.CPP - Case Study, Student Registration

// Count the number of courses taken by the student, calculate total credits
// author KRI
//

#include <iostream>
#include <fstream>
#include "unit.h"  // Course class declaration
#include "regist.h"  // Registration class declaration
#include "DATE.H"
#include "TIME.H"
#include "VECTOR.H"
#include <string.h>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;



typedef struct {
    Date d;
    Time t;
    float speed;
} WindLogType;

istream &operator >>(istream & input, WindLogType & Te);
ostream & operator <<( ostream & os, const WindLogType & Te );
// Main program:
// Open an input file stream, read a Registration object,
// including its list of courses. Redisplay all information,
// and calculate the total credits taken. Write the results
// to a file stream.


int main()
{
    vectorClass<WindLogType> windlog;
    vectorClass<string> column;
    WindLogType w2;

  //  string xx = "3";
   // int zz = stoi(xx);
  //  string token;



   /*w2.d.SetDay(11);
    w2.d.SetMonth(22);
    w2.d.SetYear(2312);
    cout<<w2.d;

    w2.t.SetHour(11);
    w2.t.SetMin(22);
    cout<<w2.t;*/

    //WindLogType.d.GetDay();

string filename;
ifstream input;
string topline;
filename = "MetData-31-3.csv";

input.open(filename.c_str());
//input.ignore(500,'\n');
getline(input,topline, '\n');
column.push(topline);
column.print();
//cout<<topline<<'\n';

string line,line2, readDay, readMonth, readYear, readHour, readMinute;
float sp;

while(!input.eof())
{

    WindLogType w1;
    input >> w1;
  windlog.push(w1);

   ofstream ofile( "WindSpeedTRIAL.txt" );

   for(int i = 0; i<windlog.getcapacity(); i++)
    ofile << windlog.get(i);

    cout<<w1; // show output

    /*int p =input.peek();
    cout<<p;
    cout<<EOF;
    if(p == EOF)
    {
        if(input.eof())
            windlog.pop();
        break;

    }*/
}
    /*cout<<"TEST DATE" <<w1.d.GettingDay()<< "+"<<w1.d.GettingMonth()<<"+"<<w1.d.GettingYear()<<'\n';
    input >> w1.t;
    cout <<"TEST TIME"<< w1.t.GettingHour()<<":"<<w1.t.GettingMin()<<'\n';*/


    /*w1.t.SetHour(2); //setter from within struct
    w1.t.SetMin(33);

    w1.speed = 10;
    w1.d.SetDay(1);
    w1.d.SetMonth(11);
    w1.d.SetYear(2314);
    windlog.push(w1);

    int size =windlog.getcapacity();
    cout<<size<<endl;*/


/*ifstream data("MetData-31-3.csv");
if (!data.is_open())
    {
       cout<<"CLOSE IT"<<endl;
    }

    string str,date,time,speed;
     getline(data, str); // skip first line

     while (getline(data, str))
{
    WindLogType windtype;

    stringstream iss(str);
    string token;

   getline(iss, windtype.d.SetDay(iss), '/');
   getline(iss, windtype.d.SetMonth(), '/');
   getline(iss, windtype.d.SetYear(), ' ');
   getline(iss, windtype.t.SetHour(), ':');
   getline(iss, speed, ',');

    windtype.speed=speed; // use this kind
    windlog.push(windtype);
}
    for ( int i = 0; i<windlog.size(); i++)
    {
        cout<< windlog;
    }*/

 /*ifstream infile( "MetData-31-3.csv" );
  if( !infile ) return -1;

  WindLogType w1;

  infile >> w1;
  windlog.push(w1);

  ofstream ofile( "WindSpeed.txt" );

// Use a debugger and track down the calls made "behind the scene"
  ofile << w1;*/


  // Declare and initialize a Course, and modify
  // its credits.

 /* int testday;
  int testMonth;
  int testYear;
  Date DateObj (2,3,1321);
  DateObj.SetDay(31);
  DateObj.SetMonth(02);
  DateObj.SetYear(1993);
  DateObj.GetDay(testday);
  DateObj.GetMonth(testMonth);
  DateObj.GetYear(testYear);
  cout << "Date:"<<DateObj<<endl;

  cout <<"TEST:"<<testday<< endl;
  cout <<"TEST:"<<testMonth<<endl;
  cout <<"TEST:"<<testYear<<endl;

  int testHour;
  int testMin;
  Time TimeObj;

   cout<<"TIME:"<<TimeObj<<endl;
  TimeObj.SetHour(03);
  TimeObj.SetMin(20);
  TimeObj.GetHour(testHour);
  TimeObj.GetMin(testMin);
  cout<<"TIME:"<<TimeObj<<endl;
  cout <<"TESTTIME:"<< testHour<<endl;
  cout <<"TESTTIME:"<<testMin<<endl;*/

  return 0;
}

istream &operator >>(istream & input, WindLogType & Te)
{

    //vectorClass<WindLogType> windlog;


/*string SaveInput;
  getline(input,SaveInput, ' ');
  stringstream container (SaveInput);
  int x;
  container >> x;
    Te.speed=x;*/

input>>Te.d>>Te.t>>Te.speed;

/*for(unsigned i = 0; i < 10; i++)
{

    windlog.push(Te);
}*/

return input;
}

ostream & operator <<( ostream & os, const WindLogType & Te )
{
    os<<Te.d<<Te.t<<"Speed: "<<Te.speed<<'\n';

  return os;
}


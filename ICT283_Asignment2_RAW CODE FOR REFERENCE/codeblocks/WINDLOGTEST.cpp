#include <iostream>
#include "WINDLOGTYPE.H"
#include "DATE.H"
#include "TIME.H"


using namespace std;

int main()
{

    Date d;
    Time t;
    WindLogType w1;
    WindLogType w3;

    cout<<"WINDLOGTYPE CLASS TESTING"<<endl;
    cout<<'\n';

    /* Test Default Constructor */
    cout<<"Test Default Constructor"<<endl;
    // setup
    cout<<"All values should be 0"<<endl;
    cout<<"Day: "<<w1.GetDay()<<" Month: "<<w1.GetMonth()<<" Year: "<<w1.GetYear()<<" Hour: "<<w1.GetHour()<<" Minute "<<w1.GetMin()<<" Speed: "
        <<w1.GetSpeed()<<" Solar Radiation: "<<w1.GetSolarRad()<<" Temperature: "<<w1.GetTemp()<<endl;
    cout<<'\n';


    // test Getters
    w1.SetDay(2);
    w1.SetMonth(2);
    w1.SetYear(2022);
    w1.SetHour(23);
    w1.SetMin(59);
    w1.SetSpeed(10);
    w1.SetSolarRad(20);
    w1.SetTemp(30);


    cout<<"Test all Getters"<<endl;
    cout<<"Expected values"<<endl;
    cout<<"Day:2  Month:2 Year:2022 Hour:23 Minute:59 Speed:10 Solar Radiation:20 Temperature:30 "<<endl;
    cout<<"Getter values"<<endl;
    cout<<"Day: "<<w1.GetDay()<<" Month: "<<w1.GetMonth()<<" Year: "<<w1.GetYear()<<" Hour: "<<w1.GetHour()<<" Minute "<<w1.GetMin()<<" Speed: "
        <<w1.GetSpeed()<<" Solar Radiation: "<<w1.GetSolarRad()<<" Temperature: "<<w1.GetTemp()<<endl;

    cout<<'\n';

    /* Test Setters */
    cout<<"Test all Setters"<<endl;
    // setup


    w3.SetDay(11);
    w3.SetMonth(1);
    w3.SetYear(2011);
    w3.SetHour(14);
    w3.SetMin(30);
    int speed = 20;
    int solar = 30;
    int temperature = 40;

    w3.SetSpeed(speed);
    w3.SetSolarRad(solar);
    w3.SetTemp(temperature);
    // test

    cout<<"Setter Value: "<<w3.GetDay()<<" Expected value: "<<"11"<<endl;
    cout<<"Setter Value: "<<w3.GetMonth()<<" Expected value: "<<"1"<<endl;
    cout<<"Setter Value: "<<w3.GetYear()<<" Expected value: "<<"2011"<<endl;
    cout<<"Setter Value: "<<w3.GetHour()<<" Expected value: "<<"14"<<endl;
    cout<<"Setter Value: "<<w3.GetMin()<<" Expected value: "<<"30"<<endl;
    cout<<"Setter Value: "<<w3.GetSpeed()<<" Expected value: "<<speed<<endl;
    cout<<"Setter Value: "<<w3.GetSolarRad()<<" Expected value: "<<solar<<endl;
    cout<<"Setter Value: "<<w3.GetTemp()<<" Expected value: "<<temperature<<endl;

}

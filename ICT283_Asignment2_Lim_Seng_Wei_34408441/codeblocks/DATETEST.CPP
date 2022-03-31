#include <iostream>
#include "DATE.H"


using namespace std;

int main()
{


    Date d1;
    Date d3;


    cout<<"DATE CLASS TESTING"<<endl;
    cout<<'\n';

    /* Test Default Constructor */
    cout<<"Test Default Constructor"<<endl;
    // setup
    cout<<"All values should be 0"<<endl;
    cout<<d1<<endl;

    cout<<'\n';
    // test Getters

    Date d2(3,3,2033);
    cout<<"Test all Getters"<<endl;
    cout<<"Will set date to 3/3/2033 for testing"<<endl;
    cout<<"Getter Value: "<<d2.GettingDay()<<" Expected value: 3 "<<endl;
    cout<<"Getter Value: "<<d2.GettingMonth()<<" Expected value: 3 "<<endl;
    cout<<"Getter Value: "<<d2.GettingYear()<<" Expected value: 2033 "<<endl;
    cout<<'\n';

    /* Test Setters */
    cout<<"Test all Setters"<<endl;
    // setup

    int day = 22;
    int month = 2;
    int year = 2022;

    d3.SetDay(day);
    d3.SetMonth(month);
    d3.SetYear(year);
    // test
    cout<< "Setters will update date to 22/2/2022"<<endl;
    cout<<"Setter Value: "<<d3.GettingDay()<<" Expected value: "<<day<<endl;
    cout<<"Setter Value: "<<d3.GettingMonth()<<" Expected value: "<<month<<endl;
    cout<<"Setter Value: "<<d3.GettingYear()<<" Expected value: "<<year<<endl;

}

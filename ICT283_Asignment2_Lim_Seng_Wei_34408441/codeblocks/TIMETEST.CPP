#include <iostream>
#include "TIME.H"


using namespace std;

int main()
{


    Time t1;
    Time t3;


    cout<<"TIME CLASS TESTING"<<endl;
    cout<<'\n';

    /* Test Default Constructor */
    cout<<"Test Default Constructor"<<endl;
    // setup
    cout<<"All values should be 0"<<endl;
    cout<<t1<<endl;

    cout<<'\n';
    // test Getters

    Time t2(23,59);
    cout<<"Test all Getters"<<endl;
    cout<<"Will set date to 23:59 for testing"<<endl;
    cout<<"Getter Value: "<<t2.GettingHour()<<" Expected value: 23 "<<endl;
    cout<<"Getter Value: "<<t2.GettingMin()<<" Expected value: 59 "<<endl;
    cout<<'\n';

    /* Test Setters */
    cout<<"Test all Setters"<<endl;
    // setup

    int hr = 1;
    int min = 59;

    t3.SetHour(hr);
    t3.SetMin(min);
    // test
    cout<< "Setters will update time to 1:59"<<endl;
    cout<<"Setter Value: "<<t3.GettingHour()<<" Expected value: "<<hr<<endl;
    cout<<"Setter Value: "<<t3.GettingMin()<<" Expected value: "<<min<<endl;

}

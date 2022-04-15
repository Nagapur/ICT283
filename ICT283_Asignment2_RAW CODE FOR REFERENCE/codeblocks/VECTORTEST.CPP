#include <iostream>
#include "VECTOR.H"


using namespace std;

int main()
{


    Vector<int> test1;


    cout<<"VECTOR TEMPLATE CLASS TESTING"<<endl;
    cout<<'\n';

    /* Test Default Constructor */
    cout<<"Test Default Constructor"<<endl;
    // setup
    cout<<"Nothing to output from using print function"<<endl;
    test1.print();

    cout<<'\n';
    // test Add


    cout<<"Test Add/Add Element function"<<endl;
    cout<<"Will add int 100"<<endl;
    test1.Add(100);

    cout<<"Output Value: "<<test1.At(0)<<" Expected value: 100 "<<endl;

    cout<<"Will add int 200 at Index 0"<<endl;
    test1.AddElement(200,0);
    cout<<"Output Value: "<<test1.At(0)<<" Expected value: 200 "<<endl;
    cout<<'\n';

    //Test At()
    cout<<"Test At function"<<endl;

    test1.AddElement(1,0);
    test1.Add(10);
    test1.Add(20);

    // test
    cout<< "At function will extract data from specified index"<<endl;
    cout<<"At (0): "<<test1.At(0)<<"    Expected value:1 "<<endl;
    cout<<"At (1): "<<test1.At(1)<<"   Expected value:10 "<<endl;
    cout<<"At (2): "<<test1.At(2)<<"   Expected value:20 "<<endl;

    cout<<'\n';
    //Test RemoveLast()
    cout<<"Test RemoveLast function"<<endl;
    cout<<"Vector size before function is: "<<test1.GetSize()<<endl;
    test1.RemoveLast();

    cout<<"Vector last element will be removed, size minus 1"<<endl;
    cout<<"Will use the same vector as previous test"<<endl;
    cout<<"Vector size: "<<test1.GetSize()<<"   Expected value:2"<<endl;
    cout<<'\n';

    //Test GetSize() and GetAllocation()
    cout<<"Test Getsize function which will return the number of element in vector"<<endl;
    cout<<"Will test on the same vector which should have a size of 2 now"<<endl;
    cout<<"Current Size: "<<test1.GetSize()<<"   Expected value: 2"<<endl;
    cout<<'\n';

    cout<<"Test GetAllocation, will return the storage size of vector"<<endl;
    cout<<"Allocation should be 5, as this vector is only size 2"<<endl;
    cout<<"Current Allocation: "<<test1.GetAllocation()<<"    Expected value: 5"<<endl;
    cout<<'\n';

    cout<<"Test clear function"<<endl;
    cout<<"Expected value is empty"<<endl;
    cout<<"Current value as below:"<<endl;
    test1.clear();
    cout<<"Get Size will return zero:  "<<test1.GetSize()<<endl;


}

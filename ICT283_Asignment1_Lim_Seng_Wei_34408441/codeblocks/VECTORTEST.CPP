#include <iostream>
#include "VECTOR.H"
#include "DATE.H"

using namespace std;

void AddPtr(Vector<Date*> &tempVec, const int day, int month, int year);

int main()
{


    Vector<int> test1;


    cout<<"VECTOR TEMPLATE CLASS TESTING"<<endl;
    cout<<'\n';

    /* Test Default Constructor */
    cout<<"Test Default Constructor"<<endl;
    // setup
    cout<<"Nothing to output from using print function"<<endl;
    //test1.print();

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

    Vector<int> test2;
    Vector<int> test3;


    test1.Add(1);
    test1.Add(2);
    test1.Add(3);
     test1.Add(4);
     test1.Add(5);
    //test2.Add(1);
    test2.Add(1);
    test2.Add(2);
    test2.Add(3);
    test2.Add(600);
     test2.Add(700);
     test2.Add(800);
        bool dup = false;
        int i= 0;
        int j= 0;



    cout<<"TESTING UNION/INTERSECTION/MINUS/MERGE:"<<endl;
 //cout<<test3.GetSize()<<endl;
 //cout<<test3.GetAllocation()<<endl;


/*   for(int i=0 ; i<test1.GetSize();i++)
    {
           test3.Add(test1.At(i));

        //cout<<test3.At(i)<<endl;

    } */


/*
    for(int x=0 ; x<test2.GetSize();x++)
        {
            int y =1;

        for(int z=0 ; z<test1.GetSize();z++)
            {
        if(test2.At(x)== test1.At(z))
        {
            dup = true;
            cout<<"FLAG1"<<endl;
            test3.Add(test2.At(x));
            //cout<<test2.At(x)<<endl;
            // cout<<test3.At(z)<<endl;


        }



         if (!dup)
        {
            if(test2.At(x)< test1.At(x))
            {
                cout<<"FLAG2"<<endl;
                test3.Add(test2.At(x));
            }

            else
            {
                cout<<"FLAG3"<<endl;
                int temp2;
            temp2 = test1.At(x);
            test3.Add(temp2);
            }

        }

        }



    }


    for(int i=0 ; i<test3.GetSize();i++)
    {

        //cout<<"FINAL TEST3"<<endl;
       cout<<test3.At(i)<<" ";

    } */

    ///WORKING UNION

   /* while(i<test1.GetSize() && j<test2.GetSize())
    {
        while((i<test1.GetSize() -1) && (test1.At(i) == test1.At(i+1)))
        {
            i++;
        }

        while((j<test2.GetSize() -1) && (test2.At(j) == test2.At(j+1)))
        {
            j++;
        }

        if(test1.At(i)< test2.At(j))
        {
            test3.Add(test1.At(i++));
            //i++;
        }

        else if (test1.At(i)> test2.At(j))
        {
            test3.Add(test2.At(j++));
            //j++;
        }

        else
        {
            test3.Add(test1.At(i));
            i++;
            j++;
        }
    }

    while(i<test1.GetSize())
    {
        if((i<test1.GetSize() -1) && (test1.At(i) == test1.At(i+1)))
        {
            i++;
        }
        else
        {
            test3.Add(test1.At(i++));
            //i++;
        }
    }


    while(j<test2.GetSize())
    {
        if((j<test1.GetSize() -1) && (test1.At(j) == test1.At(j+1)))
        {
            j++;
        }
        else
        {
            test3.Add(test2.At(j++));
            //j++;
        }
    }
 cout<<"FINAL UNION"<<endl;
     for(int i=0 ; i<test3.GetSize();i++)
    {


       cout<<test3.At(i)<<" ";



    }  */

///WORKING UNION END

///MERGE START

    while(i<test1.GetSize() && j<test2.GetSize())
    {
        while((i<test1.GetSize() -1) && (test1.At(i) == test1.At(i+1)))
        {
            i++;
        }

        while((j<test2.GetSize() -1) && (test2.At(j) == test2.At(j+1)))
        {
            j++;
        }

        if(test1.At(i)< test2.At(j))
        {
            test3.Add(test1.At(i++));
            //i++;
        }

        else if (test1.At(i)> test2.At(j))
        {
            test3.Add(test2.At(j++));
            //j++;
        }

        else
        {
            test3.Add(test1.At(i));
            test3.Add(test2.At(j));
            i++;
            j++;
        }
    }

    while(i<test1.GetSize())
    {
        if((i<test1.GetSize() -1) && (test1.At(i) == test1.At(i+1)))
        {
            i++;
        }
        else
        {
            test3.Add(test1.At(i++));
            //i++;
        }
    }


    while(j<test2.GetSize())
    {
        if((j<test1.GetSize() -1) && (test1.At(j) == test1.At(j+1)))
        {
            j++;
        }
        else
        {
            test3.Add(test2.At(j++));
            //j++;
        }
    }
 cout<<"FINAL MERGE"<<endl;
     for(int i=0 ; i<test3.GetSize();i++)
    {


       cout<<test3.At(i)<<" ";



    }

///MERGE END

///INTERSECTION START

 /*   while(i<test1.GetSize() && j<test2.GetSize())
    {
        while((i<test1.GetSize() -1) && (test1.At(i) == test1.At(i+1)))
        {
            i++;
        }

        while((j<test2.GetSize() -1) && (test2.At(j) == test2.At(j+1)))
        {
            j++;
        }

        if(test1.At(i)< test2.At(j))
        {

            i++;
        }

        else if (test1.At(i)> test2.At(j))
        {

            j++;
        }

        else
        {
            test3.Add(test1.At(i));
            i++;
            j++;
        }
    }
cout<<"FINAL INTERSECTION"<<endl;
     for(int i=0 ; i<test3.GetSize();i++) //test output
    {


       cout<<test3.At(i)<<" ";



    } */

    ///INTERSECTION END


    ///MINUS START

/*    while(i<test1.GetSize() && j<test2.GetSize())
    {
        while((i<test1.GetSize() -1) && (test1.At(i) == test1.At(i+1)))
        {
            i++;
        }

        while((j<test2.GetSize() -1) && (test2.At(j) == test2.At(j+1)))
        {
            j++;
        }

        if(test1.At(i)< test2.At(j))
        {
            test3.Add(test1.At(i++));
            //i++;
        }

        else if (test1.At(i)> test2.At(j))
        {
            test3.Add(test1.At(i++));
            //j++;
        }

        else
        {

            i++;
            j++;
        }
    }

     while(i<test1.GetSize())
    {
        if((i<test1.GetSize() -1) && (test1.At(i) == test1.At(i+1)))
        {
            i++;
        }
        else
        {
            test3.Add(test1.At(i++));
            //i++;
        }
    }
cout<<"FINAL MINUS"<<endl;
       for(int i=0 ; i<test3.GetSize();i++) //test output
    {


       cout<<test3.At(i)<<" ";



    } */

///MINUS END

///EFFICIENT VECTOR USING POINTER FOR DUPLICATE DATA, EXACT SAME DATE OBJECT WILL HAVE SAME POINTER

cout<<'\n'<<endl;

Vector<Date*> ptrVector;

AddPtr(ptrVector,1,2,2001);
AddPtr(ptrVector,2,2,2001);
AddPtr(ptrVector,1,2,2001);
AddPtr(ptrVector,3,2,2001);
AddPtr(ptrVector,1,2,2001);

Date * testPtr;

 for (int i = 0; i<ptrVector.GetSize(); i++)
    {
        //cout<<"DATA NUMBER : "<< i<<endl;
        testPtr = ptrVector.At(i);
        cout<<"Address: "<< testPtr<<endl;
        cout<<"Date: "<< *testPtr<<endl;
        //cout<<"Day: "<< testPtr->GettingDay()<<endl; // dereference
        //cout<<"Month: "<< testPtr->GettingMonth()<<endl; // dereference
        //cout<<"Year: "<< testPtr->GettingYear()<<endl; // dereference
    }



} // end of main is here

void AddPtr(Vector<Date*> &tempVec, const int day, int month, int year)
{
    int currentInt=-1;
    int currentMonth=-1;
    int currentYear =-1;
    bool found = false;
    Date* datePtr;
    //Date* monthPtr;
    //Date* yearPtr;
    int indexFound = -1;

    for (int i = 0; i<tempVec.GetSize(); i++)
    {
        currentInt= tempVec.At(i)->GettingDay();
        currentMonth= tempVec.At(i)->GettingMonth();
        currentYear= tempVec.At(i)->GettingYear();

        if(currentInt == day && currentMonth == month && currentYear == year ) // if all in the date is same as existing date
        {
            found = true;
            indexFound = i;
            break;
        }

     /*    if(currentMonth == month )
        {
            found = true;
            indexFound = i;
            break;
        }

         if(currentYear == year )
        {
            found = true;
            indexFound = i;
            break;
        }*/
    }

    if(found)  // then use pointers to point to the index of the previous index that holds the same date
    {
        datePtr = tempVec.At(indexFound); //assign pointer too the previous same date
    }

    else
    {
        datePtr= new Date (day,month,year); // if not found, create new Date object
    }

    tempVec.Add(datePtr); // add pointer to the vector
}

///EFFICIENT VECTOR USING POINTER FOR DUPLICATE DATA


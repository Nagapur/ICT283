
#include "BINARYSEARCHTREE.H"
#include "DATE.H"
#include "WINDLOGTYPE.H"
#include "VECTOR.H"
#include "TIME.H"
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>

void takeSolarRad(multiWindMap &tempMap);
int retrieveSolarRad(multiWindMap &tempMap);

int main()
{

     WindLogType windlogTest;
    WindLogType windlogTest2;
    WindLogType windlogTest3;

    windlogTest.SetDay(1);
    windlogTest.SetMonth(2);
    windlogTest.SetYear(1993);
    windlogTest.SetHour(22);
    windlogTest.SetMin(55);
    windlogTest.SetSolarRad(23);
    windlogTest.SetSpeed(90);
    windlogTest.SetTemp(100);

    windlogTest2.SetDay(3);
    windlogTest2.SetMonth(4);
    windlogTest2.SetYear(1965);
    windlogTest2.SetHour(9);
    windlogTest2.SetMin(34);
    windlogTest2.SetSolarRad(100);
    windlogTest2.SetSpeed(200);
    windlogTest2.SetTemp(300);


 map <int,int> testMap;
 BinarySearchTree<map<int,int>> myBstMap;

    testMap.insert(pair<int,int>(1,2));
    testMap.insert(pair<int,int>(2,4));
    testMap.insert(pair<int,int>(3,6));

        for(auto i:testMap)
        {
            cout<<i.first<<endl;
        }


//myBstMap.Insert(testMap);


BinarySearchTree<int> intBST;

intBST.ItrInsert(1);
intBST.ItrInsert(3);
intBST.ItrInsert(5);
intBST.ItrInsert(2);
intBST.ItrInsert(4);
cout<<"ITERATIVE BST TESTING"<<endl;
intBST.InOrderTraversal();
cout<<'\n';


//////////MAP INSERTED INTO BST WORKING!!/////////////////////////

     typeMap tempMap;
    typeMap dataMap;
    dataMap.insert(pair<int,int>(11,22));
    dataMap.insert(pair<int,int>(222,444));
     dataMap.insert(pair<int,int>(333,666));
    BinarySearchTree<typeMap> tree;
    for (typeMap::const_iterator it = dataMap.begin(); it != dataMap.end(); ++it)
    {
       tempMap[it->first] = it->second;
       tree.Insert(tempMap);
       cout<<it->first<<" "<<it->second<<endl;
       tempMap.clear();
    }

    //////////MAP INSERTED INTO BST WORKING END/////////////////////////


///////////////////////multimap of winglog inserted/////////////////////

     windMap tMap;
    windMap dMap;
    dMap.insert({1,windlogTest});
   dMap.insert({2,windlogTest2});

    BinarySearchTree<windMap> tree1;
    for (windMap::const_iterator it = dMap.begin(); it != dMap.end(); ++it)
    {
       //tMap[it->first] = it->second;
       tree1.Insert(dMap);
       cout<<it->first<<" "<<it->second<<endl;
       tMap.clear();
    }

    ///////////////////////multimap of winglog inserted/////////////////////


    ////////////MULTIMAP PAIR OF WINDLOG START////////////////////////////

    multiWindMap zMap;
    zMap.insert(make_pair(make_pair(windlogTest.GetYear(),windlogTest.GetMonth()),windlogTest));
    zMap.insert(make_pair(make_pair(windlogTest2.GetYear(),windlogTest2.GetMonth()),windlogTest2));

    BinarySearchTree<multiWindMap> tree2;

    for (multiWindMap::const_iterator it = zMap.begin(); it != zMap.end(); ++it)
    {
       //tMap[it->first] = it->second;
       tree2.Insert(zMap); // insert multimap to BST!!

       if (it->second.GetYear() == 1965) // search criteria
       cout<<it->second<<endl;  // output just the value of the map

       else
        cout<<"not found"<<endl;
    }

    ////////////MULTIMAP PAIR OF WINDLOG END////////////////////////////

    multiWindMap map19651;
   for (multiWindMap::const_iterator it = zMap.begin(); it != zMap.end(); ++it)
    {


       if (it->second.GetYear() == 1965) // search criteria
{
      map19651 = zMap;

       tree2.Insert(map19651); // INSERT MULTIMAP NAMES BY YEAR AND MONTH TO BST
       int maxSR = 0;

//       maxSR= tree2.InOrderTraversalInt(retrieveSolarRad);

        cout<<"maxSR is: " <<maxSR<<endl;


}
               //tree2.InOrderTraversal(takeSolarRad);

    }

   /* for (multiWindMap::const_iterator it = map19651.begin(); it != map19651.end(); ++it)
    {

        cout<<"MAP1965"<<endl;
       cout<<it->second<<endl;


    }*/





    ////////////BORDER////////////////////////////////////////////////////////////


}


void takeSolarRad(multiWindMap &tempMap)  // FUNC PTR TO RETRIEVE SOLAR RAD
{
    int maxRad=0;
    int tempRad;

    for (multiWindMap::const_iterator it = tempMap.begin(); it != tempMap.end(); ++it)
    {

        tempRad= it->second.GetSolarRad();

        if(tempRad > maxRad)
        {
            maxRad= tempRad;
        }
       //cout <<"Solar Radiation: " <<it->second.GetSolarRad()<<endl;

    }

cout<<"Highest Solar Radiation: " << maxRad<<endl;




}

int retrieveSolarRad(multiWindMap &tempMap)  // FUNC PTR TO RETRIEVE SOLAR RAD
{
    int maxRad=0;
    int tempRad;
    int day;
    int month;
    int year;

    for (multiWindMap::const_iterator it = tempMap.begin(); it != tempMap.end(); ++it)
    {

        tempRad= it->second.GetSolarRad();

        if(tempRad > maxRad)
        {
            maxRad= tempRad;
            day= it->second.GetDay();
            month = it->second.GetMonth();
            year= it->second.GetYear();

        }
       //cout <<"Solar Radiation: " <<it->second.GetSolarRad()<<endl;

    }

    cout <<"maxRad in function: " <<day<<"/"<<month<<"/"<<year<<" "<<maxRad<<endl;


return maxRad;




}

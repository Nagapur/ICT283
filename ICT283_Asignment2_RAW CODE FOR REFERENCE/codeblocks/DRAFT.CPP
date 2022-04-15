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

using namespace std;

//typedef map<int, map<int, vector<WindLogType>>> windLogMap;

void PrintBrackets (int &text);
void Increment (int &num);
void ReadFileName();
void LoadCSV(string token, vector<string> &winglog);
//void LoadCSV(string token, BinarySearchTree<string> bst);

int main33()
{





    map<pair<int, int>, Vector<WindLogType> > monthMap;
    map<pair<int, int>, Vector<WindLogType> >::iterator itr6;
    multimap<pair<int,int>,WindLogType> pairMap;
    multimap<pair<int,int>,WindLogType> :: iterator itr22;

    Vector<WindLogType> w1;
    vector <WindLogType> w2;
    Vector<WindLogType> w3;

    Date d,e,f;
    d.SetDay(1);
    d.SetMonth(12);
    d.SetYear(2022);
    e.SetDay(3);
    e.SetMonth(10);
    e.SetYear(2022);
    f.SetDay(2);
    f.SetMonth(11);
    f.SetYear(2022);

    //cout<< e<< endl;

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

    w1.Add(windlogTest);
    w1.Add(windlogTest2);
    w2.push_back(windlogTest);
    w2.push_back(windlogTest2);
    w3.Add(windlogTest);
    w3.Add(windlogTest2);

    pairMap.insert(make_pair(make_pair(windlogTest.GetYear(),windlogTest.GetMonth()),windlogTest));
    pairMap.insert(make_pair(make_pair(windlogTest2.GetYear(),windlogTest2.GetMonth()),windlogTest2));

    //cout<<windlogTest.GetDay()<<endl;

    cout<< "COUT VECTOR NORMALLY"<< endl;
    cout<<w3.At(0).GetHour()<<endl;

      for(int i = 0; i<w1.GetSize(); i++)
    {
        cout<<w1.At(i)<<endl;
    }

    cout<<windlogTest<<endl;


    BinarySearchTree<string> stringBst;
    map <int,int> testMap;
    map <int,int>::iterator itr;

     map <Date,Date> dateMap;
    map <Date,Date>::iterator itr2;
//////////////////////WINDLOG MAP TEST///////////////////////////////////////
    string name;
    map <int,WindLogType> logMap;
    map <int,WindLogType>::iterator itr3;

    int testKey = windlogTest.GetDay() + windlogTest.GetYear() + windlogTest.GetMonth();
    logMap.insert(pair<int,WindLogType>(testKey,windlogTest));

    for(itr3 = logMap.begin(); itr3!= logMap.end(); itr3++)
    {
        cout<<"WINDLOG MAP TEST"<<endl;
        cout<<itr3->first << " " <<itr3->second<<endl;
        int testYear = itr3->second.GetYear();

        if(testYear == 1993)
        {
            cout<<testYear<<endl;
            cout<<"YEAR CAN BE FOUND !!!!"<<endl;
        }

        else

        {
            cout<<"YEAR CANNOT BE FOUND!!!!"<<endl;
        }
    }

////////////////WINDLOGMAP END//////////////////////////////////////////////
////////////////VECTOR MAP WORKING//////////////////////////////////////////

    map<int,vector<WindLogType>> vectorMap;
    map<int,vector<WindLogType>> ::iterator vecItr;

    int goodKey = w2.at(0).GetDay(); // find element from index

    vectorMap.insert(pair<int,vector<WindLogType>>(1001 +goodKey, w2));

     for(vecItr = vectorMap.begin(); vecItr != vectorMap.end(); vecItr ++)
    {
        cout<<"VECTOR MAP TEST IS HERE"<<endl;
        cout<<vecItr->first <<endl;

        for (auto vec_itr = vecItr->second.begin(); vec_itr!= vecItr->second.end(); vec_itr++)
        {
            cout<<*vec_itr<<endl;
        }
    }
////////////////VECTOR MAP END//////////////////////////////////////////////////

////////////////VECTOR MAP TEMPLATE//////////////////////////////////////////

    map<int,Vector<WindLogType>> vectorMap2;
    map<int,Vector<WindLogType>> ::iterator vecItr2;

    int goodKey2 = w2.at(0).GetDay(); // find element from index

    vectorMap2.insert(pair<int,Vector<WindLogType>>(1001 +goodKey, w1));

    cout<<"OUTPUT TEMPLATE VECTOR NORMALLY!"<<endl;
    cout<<w1.At(0).GetDay()<<endl;

     for(vecItr2 = vectorMap2.begin(); vecItr2 != vectorMap2.end(); vecItr2 ++)
    {
        cout<<"VECTOR MAP TEMPLATE TEST IS HERE"<<endl;
        cout<<vecItr->first <<endl;

        for (auto vec_itr2 = vecItr2->second.begin(); vec_itr2!= vecItr2->second.end(); vec_itr2++)
        {
            cout<<*vec_itr2<<endl;
        }
    }
////////////////VECTOR MAP END//////////////////////////////////////////////////

    vector <string> windlog;
//////////////////////////INT BST TEST///////////////////////////////////////////////

    cout<<"INT BST HERE"<<endl;
    BinarySearchTree<int> intBst;
    intBst.Insert(1);
    intBst.Insert(2);
    intBst.Insert(3);
    intBst.Insert(4);
    intBst.Insert(5);

    intBst.InOrderTraversal(Increment); // function pointer
    intBst.InOrderTraversal(PrintBrackets); // function pointer
    intBst.FindNode(7);

//////////////////////////INT BST END////////////////////////////////////

/////////WINDLOG BST HERE///////////////////////////////////////////

    BinarySearchTree<WindLogType> windLogBst;
    windLogBst.Insert(windlogTest);
    windLogBst.Insert(windlogTest2);

    cout<<"WINDLOG BST IS HERE!!"<<endl;
    windLogBst.InOrderTraversal();

//////////////MAP BST HERE////////////////////////////////////////

    BinarySearchTree<map<int,int>> myBstMap;

    testMap.insert(pair<int,int>(1,2));
    testMap.insert(pair<int,int>(2,4));
    testMap.insert(pair<int,int>(3,6));


myBstMap.Insert(testMap);

myBstMap.InOrderTraversal();
//////////////////////////////////////////////////////////////////

    testMap.insert(pair<int,int>(1,2));
    testMap.insert(pair<int,int>(2,4));
    testMap.insert(pair<int,int>(3,6));

    for(itr = testMap.begin(); itr!= testMap.end(); itr++)
    {
        cout<<itr->first << " " <<itr->second<<endl;
    }

    dateMap.insert(pair<Date,Date>(e,d));
    dateMap.insert(pair<Date,Date>(d,e));
    dateMap.insert(pair<Date,Date>(f,f));

    for(itr2 = dateMap.begin(); itr2!= dateMap.end(); itr2++)
    {
        cout<<itr2->first << " " <<itr2->second<<endl;
    }

    windLogMap tempMap;
    windLogMap dataMap;
    // map<string, map<int, int> >::iterator itr;
        map<int, map<int, vector<WindLogType>>> ::iterator itr4;
        map <int, vector<WindLogType>> ::iterator itr5;
     //windLogMap :: iterator itr4
    BinarySearchTree<windLogMap> windBst;
     //map <int,WindLogType> tempMap;

    //windlogMap.insert(pair<int,WindLogType>(windlogTest.GetDay() + windlogTest.GetYear(),windlogTest));
    //dataMap.insert(make_pair(1,map<int,windLogMap>()));
    //dataMap[1].insert(make_pair(1001,windlogTest));
    //dataMap[1][2] = w2;

  //      itr6= monthMap.find(make_pair(windlogTest.GetMonth(), windlogTest.GetYear()));

 //       if (itr6!= monthMap.end())

 //       {
 //           monthMap[{windlogTest.GetMonth(), windlogTest.GetYear()}].Add(windlogTest);
//        }



  for(windLogMap::const_iterator itr4 = dataMap.begin(); itr4!= dataMap.end(); itr4++)
    //for (itr4 = dataMap.begin(); itr!= dataMap.end(); itr4++){
        //for(itr5 = itr4->second.begin(); itr5!= itr4 ->second.end();itr5++)
       {


         cout<<"OVER HERE !!!"<<endl;
        tempMap[itr4->first] = itr4->second;
        cout<<"OVER HERE !!!"<<endl;

        //cout<<itr4->first << " " <<itr4->second<<endl;
        windBst.Insert(tempMap);
       // tempMap.clear();
       }







    ///////////////DATE BST///////////////////
   /* BinarySearchTree<Date> dateBst;
    dateBst.Insert(d);
     dateBst.Insert(e);
      dateBst.Insert(f);
    dateBst.PreOrderTraversal();
    cout<<'\n';
     dateBst.InOrderTraversal();
     cout<<'\n';
      dateBst.PostOrderTraversal(); */






 ////////////////////////////////////////////////////////////////////////////////////

   /* string filename;
    ifstream inputFile;
    string topline;
    string token;
    string rows;


    filename = "/Users/sengw/Desktop/ICT 283/ICT283_Asignment2_Lim_Seng_Wei_34408441/codeblocks/data/met_index.txt";
    inputFile.open(filename.c_str());

    //* TO PROCESS FIRST ROW FOR HEADER NAME */

    /* getline(inputFile,topline, '\n');
    stringstream firstrow ;
    firstrow<<topline; */

  /* while(!inputFile.eof())
         {
              inputFile >> token;
              cout<<"File:" << token << endl;
              LoadCSV(token,windlog);
              cout<<"Size:" << windlog.size()<<endl;
              //stringBst.Insert("WTF");
              //stringBst.Insert("ZZZ");
              //stringBst.InOrderTraversal();
         }*/





}

void PrintBrackets(int &text)
{
    cout<< "[" << text << "]"<<endl;
}

void PrintBrackets(WindLogType &text)
{
    cout<< "[" << text << "]"<<endl;
}

void PrintBrackets(map<int, int> &tempMap)
{

     for( auto itr = tempMap.begin(); itr!= tempMap.end(); ++itr)
    {

            cout<<itr->first << " " << itr->second<<endl;

    }


}

void Increment(int &num)
{
    num++;
}


void LoadCSV(string token, vector<string> &windlogZ)
{
    string filename;
    ifstream inputFile;
    string topline;
    string rows;


    filename = "/Users/sengw/Desktop/ICT 283/ICT283_Asignment2_Lim_Seng_Wei_34408441/codeblocks/data/" + token;
    inputFile.open(filename.c_str());

    //* TO PROCESS FIRST ROW FOR HEADER NAME */

    /*getline(inputFile,topline, '\n');
    stringstream firstrow ;
    firstrow<<topline;*/



  /*while(getline(inputFile,rows))
         {
             inputFile >> rows;
             windlogZ.push_back(rows);
             // bst.Insert(rows);
              //bst.InOrderTraversal();


              //cout<<rows<<endl;


         }*/


         //WORKING FIND FOR PAIR MULTIMAP, BUT CANNOT SHOW MULTIPLE VALUE OF SAME KEY///
    itr = logMap.find(make_pair(2010,1));

     if(itr == logMap.end())
  {
      cout<<"NOT FOUND"<<endl;
  }

  else

  {
      cout<<"FIND FUNCTION OUTPUT HERE! "<<  itr->second<<endl;
  }
/////////////////////////////WORKING FIND END///////////////////////////////////////////

///////////////////////////FULL WORKING FIND, SHOW ALL VALUES OF SAME KEY//////////////////
  typedef multimap<pair<int,int>,WindLogType> :: iterator itr22; // working iterator for search that display all values of same key
  int year;
  int month;
   pair<int,int> keyPair ;

   cout<<"Please enter year"<<'\n';
    cin>>year;

    cout<<"Please enter month"<<'\n';
    cin>>month;

   keyPair.first = year;
   keyPair.second = month;

    pair<itr22, itr22> result = logMap.equal_range(keyPair); // returns a pair representing the range of elements with key equal to 'keyPair'
    int count = distance(result.first, result.second); // find the number of time the key appears in the range

    if(count ==0) // count = 0 means key not found in the range
    {
        cout<<"KEY NOT FOUND"<<endl;
    }

    else // key found, proceed to output
    {
         for(itr22 it=result.first; it!=result.second; it++)
    {

            //cout<<"Total Count: " << count<<endl;

            cout<< it->second<<endl; // output all data with the key


    }

    }



///////////////////////////FULL WORKING FIND, SHOW ALL VALUES OF SAME KEY END//////////////////

 /* auto it = logMap.find (1);

  if(it == logMap.end())
  {
      cout<<"NOT FOUND"<<endl;
  }

  else
  {
      cout<<"FOUND THIS: "<< it->first<<" "<<it->second<<endl;
  }

*/

// OUTPUT ALL VALUE WITH THE MATCHING KEY
 /* for( auto itr = logMap.begin(); itr!= logMap.end(); ++itr)
  {
      if(itr->first == 999999)
      {
          cout<<"FOUND THIS: "<< itr->first<<" "<<itr->second<<endl;
      }


  }*/


    //ReadCSVToVector(windlog);


}

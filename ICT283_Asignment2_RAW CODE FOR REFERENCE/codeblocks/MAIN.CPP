// MAIN.CPP

#include <iostream>
#include <fstream>
#include "DATE.H"
#include "TIME.H"
#include "VECTOR.H"
#include "WINDLOGTYPE.H"
#include "BINARYSEARCHTREE.H"
#include <string.h>
#include <sstream>
#include <limits>
#include <iomanip>
#include <map>
#include <string>


using namespace std;

//void takeSolarRad(multiWindMap &tempMap); // function pointer declaration
//int retrieveSolarRad(multiWindMap &tempMap);

istream &operator >>(istream & input, WindLogType & Te);
ostream & operator <<( ostream & os, const WindLogType & Te );

string month[13] = {" ", "January","February","March","April","May","June",
                    "July","August","September","October","November","December"
                   }; // Array to store the month accordingly to their number

//Functions:

void print(multimap<pair<int, int>,WindLogType>& myContainer) // print function for multimap pairs
{
    for (auto pr : myContainer)
    {
        pair<int, int> myPair = pr.first;

        // pr points to current pair of myContainer
        cout << '[' << myPair.first << "," << myPair.second << ']' << " " << pr.second << '\n';
    }

}


void ReadCSVToVector(string token , Vector<WindLogType> & windlog)
{


    Vector<string> column;

    WindLogType w1;

    string filename;
    ifstream inputFile;
    string topline;
    string throwaway;
    string rows;

    //Read the multiple CSV file using a variable with their filename
    filename = "/Users/sengw/Desktop/ICT 283/ICT283_Asignment2_Lim_Seng_Wei_34408441/codeblocks/data/" + token;
    cout<<"READING NOW "<< filename<<endl;
    inputFile.open(filename.c_str());

    getline(inputFile,topline, '\n');
    stringstream firstrow ;
    firstrow<<topline;

    while(getline(firstrow,throwaway, ',')) //reading the first line of header information and save into another Vector
    {

        column.Add(throwaway);
        //cout<<"READING FIRST LINE "<<throwaway<<endl;
    }


    while(getline(inputFile,rows,'/')) //reading the rest of the CSV from second line onwards


    {
        try{

        //read the required data line by line and use appropriate setters

        //cout<<"READING FIRST DATE "<<rows<<endl;
        int day1 = stoi(rows);
        w1.SetDay(day1);


        getline(inputFile,rows, '/');
       //cout<<"READING FIRST MONTH "<<rows<<endl;
        int month1 = stoi(rows);
        w1.SetMonth(month1);

        getline(inputFile,rows, ' ');
        int year1 = stoi(rows);
        w1.SetYear(year1);

        getline(inputFile,rows, ':');
        int hour1 = stoi(rows);
        w1.SetHour(hour1);

        getline(inputFile,rows, ',');
        int min1 = stoi(rows);
        w1.SetMin(min1);



        for(int k = 0; k < 9; k++) //skip data columns that not required
        {
            getline(inputFile,rows, ',');

        }

        getline(inputFile,rows, ','); //read speed column
        float tempSpeed = stoi(rows);
        w1.SetSpeed(tempSpeed);

        getline(inputFile,rows, ','); //read SR column
        float tempSR = stoi(rows);
        w1.SetSolarRad(tempSR);

        for(int p = 0; p < 5; p++) // skip unwanted columns
        {

            getline(inputFile,rows, ',');

        }

        getline(inputFile,rows);   // read temperature column
        float temperature1 = stof(rows);
        w1.SetTemp(temperature1);

        inputFile >> w1;

        windlog.Add(w1); // add everything to Vector
        //cout<<w1<<endl;

        }

        catch (std::invalid_argument &e)
        {

        }

    }



}



void ReadCSVToMap(string token , multiStringMap &tempMap)
{

     multimap <int,WindLogType>::iterator itr;
    Vector<string> column;

    WindLogType w1;

    string filename;
    ifstream inputFile;
    string topline;
    string throwaway;
    string rows;
    string testKeyYear;
    string testKeyMonth;

    //Read the multiple CSV file using a variable with their filename
    filename = "/Users/sengw/Desktop/ICT 283/ICT283_Asignment2_Lim_Seng_Wei_34408441/codeblocks/data/" + token;
    cout<<"READING NOW "<< filename<<endl;
    inputFile.open(filename.c_str());

    if(!inputFile.is_open())
    {
        cout<<"FILE CANNOT OPEN BRO"<<endl;
    }

    getline(inputFile,topline, '\n');
    stringstream firstrow ;
    firstrow<<topline;

    while(getline(firstrow,throwaway, ',')) //reading the first line of header information and save into another Vector
    {

        column.Add(throwaway);
        //cout<<"READING FIRST LINE "<<throwaway<<endl;
    }


    while(getline(inputFile,rows,'/')) //reading the rest of the CSV from second line onwards


    {
        try{

        //read the required data line by line and use appropriate setters

        //cout<<"READING FIRST DATE "<<rows<<endl;

        int day1 = stoi(rows);
        w1.SetDay(day1);


        getline(inputFile,rows, '/');
       //cout<<"READING FIRST MONTH "<<rows<<endl;
        testKeyMonth = rows;
        int month1 = stoi(rows);
        w1.SetMonth(month1);

        getline(inputFile,rows, ' ');
        testKeyYear= rows;
        int year1 = stoi(rows);
        w1.SetYear(year1);

        getline(inputFile,rows, ':');
        int hour1 = stoi(rows);
        w1.SetHour(hour1);

        getline(inputFile,rows, ',');
        int min1 = stoi(rows);
        w1.SetMin(min1);



        for(int k = 0; k < 9; k++) //skip data columns that not required
        {
            getline(inputFile,rows, ',');

        }

        getline(inputFile,rows, ','); //read speed column
        float tempSpeed = stoi(rows);
        w1.SetSpeed(tempSpeed);

        getline(inputFile,rows, ','); //read SR column
        float tempSR = stoi(rows);
        w1.SetSolarRad(tempSR);

        for(int p = 0; p < 5; p++) // skip unwanted columns
        {

            getline(inputFile,rows, ',');

        }

        getline(inputFile,rows);   // read temperature column
        float temperature1 = stof(rows);
        w1.SetTemp(temperature1);

        inputFile >> w1;
       //cout<< w1 <<endl;

        //windlog.Add(w1); // add everything to Vector

            //cout<<"KEY"<<testKeyYear+testKeyMonth<<endl;
        if(testKeyYear+testKeyMonth == "201001")
        {
             tempMap.insert(pair<string,WindLogType>(testKeyYear+testKeyMonth, w1));
        }
        //auto newKey = w1.GetDay() + "/" + w1.GetMonth() + "/" + w1.GetYear() + " " + w1.GetHour() + ":" + w1.GetMin();

        //cout<<testKey<<endl;

        //tempMap[testKey] = w1;

       // logMap.insert(pair<int,WindLogType>(testKey,windlogTest));

   /*    for(itr = tempMap.begin(); itr!= tempMap.end(); itr++)
    {
        cout<<"WINDLOG MAP TEST"<<endl;
        cout<<itr->first << " " << itr->second<<endl;

    }*/

        }

        catch (std::invalid_argument &e)
        {

        }


    }


}

void ReadCSVToPairMap(string token , /*multimap<pair<int,int>, WindLogType>*/ multiWindMap &tempMap)
{

    multimap <pair<int,int>,WindLogType>::iterator itr;
    Vector<string> column;

    WindLogType w1;

    string filename;
    ifstream inputFile;
    string topline;
    string throwaway;
    string rows;


    //Read the multiple CSV file using a variable with their filename
    filename = "/Users/sengw/Desktop/ICT 283/ICT283_Asignment2_Lim_Seng_Wei_34408441/codeblocks/data/" + token;
   // cout<<"READING NOW "<< filename<<endl;  // Test output for all file name reading
    inputFile.open(filename.c_str());

    if(!inputFile.is_open())
    {
        cout<<"FILE CANNOT OPEN BRO"<<endl;
    }

    getline(inputFile,topline, '\n');
    stringstream firstrow ;
    firstrow<<topline;

    while(getline(firstrow,throwaway, ',')) //reading the first line of header information and save into another Vector
    {

        column.Add(throwaway);
        //cout<<"READING FIRST LINE "<<throwaway<<endl;
    }


    while(getline(inputFile,rows,'/')) //reading the rest of the CSV from second line onwards


    {
        try{

        //read the required data line by line and use appropriate setters


        int day1 = stoi(rows);
        w1.SetDay(day1);

        getline(inputFile,rows, '/');
        int month1 = stoi(rows);
        w1.SetMonth(month1);

        getline(inputFile,rows, ' ');
        int year1 = stoi(rows);
        w1.SetYear(year1);

        getline(inputFile,rows, ':');
        int hour1 = stoi(rows);
        w1.SetHour(hour1);

        getline(inputFile,rows, ',');
        int min1 = stoi(rows);
        w1.SetMin(min1);



        for(int k = 0; k < 9; k++) //skip data columns that not required
        {
            getline(inputFile,rows, ',');

        }

        getline(inputFile,rows, ','); //read speed column
        float tempSpeed = stoi(rows);
        w1.SetSpeed(tempSpeed);

        getline(inputFile,rows, ','); //read SR column
        float tempSR = stoi(rows);
        w1.SetSolarRad(tempSR);

        for(int p = 0; p < 5; p++) // skip unwanted columns
        {

            getline(inputFile,rows, ',');

        }

        getline(inputFile,rows);   // read temperature column
        float temperature1 = stof(rows);
        w1.SetTemp(temperature1);

        inputFile >> w1;
       //cout<< w1 <<endl;


       tempMap.insert(make_pair(make_pair(w1.GetYear(),w1.GetMonth()),w1));


        }

        catch (std::invalid_argument &e) // catch invalid readings that are N/A
        {

        }


    }


}

void AvgSpeedAndTemp(Vector<WindLogType> & windlog)
{
    int inputMonth;
    int inputYear;
    int totalSpeed=0;
    float totalTemp=0;
    int totalDataCount=0;
    double avgSpeed = 0;
    double avgTemp = 0;


    cout<<"Please input month first"<<'\n';
    cin>>inputMonth;
    cout<<"Please input year, press ENTER once done"<<'\n';
    cin>>inputYear;


    for (int x =0; x<windlog.GetSize(); x++)
    {


        if(inputYear == windlog.At(x).GetYear() && inputMonth == windlog.At(x).GetMonth()) // loop through vector to check year and month
        {

            totalSpeed=windlog.At(x).GetSpeed() + totalSpeed;
            totalTemp=windlog.At(x).GetTemp() + totalTemp;
            totalDataCount++;
        }


    }

    cout<<totalDataCount<<endl;

    if (totalSpeed ==0 || totalTemp == 0)

    {
        cout<<"No Data"<<endl;
    }

    totalSpeed = totalSpeed *3.6; // Convert to KM/H
    avgSpeed = totalSpeed/totalDataCount;
    avgTemp = totalTemp/totalDataCount;


    if (avgSpeed !=0 || avgTemp != 0) // check whether data is valid
    {

        cout<<month[inputMonth]<<" "<<inputYear<<" : "<<fixed<<setprecision(1)<< avgSpeed<<" km/h, "<<avgTemp<<" degrees C"<<'\n';
    }


}

void AvgSpeedAndTempMap(multimap<int, WindLogType> &tempMap)
{
    int inputMonth;
    int inputYear;
    int totalSpeed=0;
    float totalTemp=0;
    int totalDataCount=0;
    double avgSpeed = 0;
    double avgTemp = 0;


    cout<<"Please input month first"<<'\n';
    cin>>inputMonth;
    cout<<"Please input year, press ENTER once done"<<'\n';
    cin>>inputYear;

     for( auto itr = tempMap.begin(); itr!= tempMap.end(); ++itr)
    {
        if(inputYear == itr->second.GetYear() && inputMonth == itr->second.GetMonth())
        {
            totalSpeed = itr->second.GetSpeed() + totalSpeed;
            totalTemp = itr->second.GetTemp() + totalTemp;
            totalDataCount++;
        }

    }



    cout<<totalDataCount<<endl;

    if (totalSpeed ==0 || totalTemp == 0)

    {
        cout<<"No Data"<<endl;
    }

    totalSpeed = totalSpeed *3.6; // Convert to KM/H
    avgSpeed = totalSpeed/totalDataCount;
    avgTemp = totalTemp/totalDataCount;


    if (avgSpeed !=0 || avgTemp != 0) // check whether data is valid
    {

        cout<<month[inputMonth]<<" "<<inputYear<<" : "<<fixed<<setprecision(1)<< avgSpeed<<" km/h, "<<avgTemp<<" degrees C"<<'\n';
    }


}

void AvgSpeedAndTempMapPair(multiWindMap &tempMap)
{
    int inputMonth;
    int inputYear;
    int totalSpeed=0;
    float totalTemp=0;
    int totalDataCount=0;
    double avgSpeed = 0;
    double avgTemp = 0;


    cout<<"Please input month first"<<'\n';
    cin>>inputMonth;
    cout<<"Please input year, press ENTER once done"<<'\n';
    cin>>inputYear;

     for( auto itr = tempMap.begin(); itr!= tempMap.end(); ++itr)
    {

        if(inputYear == itr->second.GetYear() && inputMonth == itr->second.GetMonth())
        {
            totalSpeed = itr->second.GetSpeed() + totalSpeed;
            totalTemp = itr->second.GetTemp() + totalTemp;
            totalDataCount++;
        }

    }



    //cout<<totalDataCount<<endl;

    if (totalSpeed ==0 || totalTemp == 0)

    {
        cout<<"No Data"<<endl;
    }

    totalSpeed = totalSpeed *3.6; // Convert to KM/H
    avgSpeed = totalSpeed/totalDataCount;
    avgTemp = totalTemp/totalDataCount;


    if (avgSpeed !=0 || avgTemp != 0) // check whether data is valid
    {

        cout<<month[inputMonth]<<" "<<inputYear<<" : "<<fixed<<setprecision(1)<< avgSpeed<<" km/h, "<<avgTemp<<" degrees C"<<'\n';
    }


}

void MonthlyAvgSpeedAndTemp(Vector<WindLogType> & windlog)
{
    double totalSpeedArr [13] = {0},totalTempArr[13] = {0},avgSpeedArr[13]= {0},avgTempArr[13]= {0}; // arrays to store the data by month, month = index
    int totalDataCount[13]= {0}; // array to store the total line count                           // array is size 13 because index 0 will be unused
    int monthCount=0; // variable to represent the month in the arrays
    int inputYear;

    cout<<"Please enter year"<<'\n';
    cin>>inputYear;
    cout<<'\n';
    cout<<inputYear<<'\n';


    for (int x =0; x<windlog.GetSize(); x++)
    {

        if(inputYear == windlog.At(x).GetYear())  // check for same year as per input and extract the month value
        {
            monthCount = windlog.At(x).GetMonth();
            totalSpeedArr[monthCount]= windlog.At(x).GetSpeed() + totalSpeedArr[monthCount]; // use the month as the index of the arrays
            totalTempArr[monthCount] = windlog.At(x).GetTemp() + totalTempArr[monthCount];
            totalDataCount[monthCount]++; // keep track of total line items so can calculate average later


        }

    }

    for(int x=1 ; x<13; x++) // X start from 1 to skip index 0 of month array
    {
        if(totalSpeedArr[x]!= 0 && totalTempArr[x]!= 0 ) // loop through arrays and check for valid data

        {
            totalSpeedArr[x] = totalSpeedArr[x] * 3.6; // convert to KM/H
            avgSpeedArr[x] = totalSpeedArr[x] /totalDataCount[x];
            avgTempArr[x] = totalTempArr[x] / totalDataCount[x];
            cout<<month[x]<<": "<<fixed<<setprecision(1)<<avgSpeedArr[x]<<" km/h "<<avgTempArr[x]<<" Degrees C"<<endl;

        }


        if(totalSpeedArr[x]== 0 || totalTempArr[x]== 0 ) // if data is 0, output message
        {
            cout<<month[x]<<" : No Data"<<endl;
        }
    }

}

void MonthlyAvgSpeedAndTempMap(/*multimap<pair<int,int>, WindLogType>*/ multiWindMap &tempMap)
{
    double totalSpeedArr [13] = {0},totalTempArr[13] = {0},avgSpeedArr[13]= {0},avgTempArr[13]= {0}; // arrays to store the data by month, month = index
    int totalDataCount[13]= {0}; // array to store the total line count                           // array is size 13 because index 0 will be unused
    int monthCount=0; // variable to represent the month in the arrays
    int inputYear;

    cout<<"Please enter year"<<'\n';
    cin>>inputYear;
    cout<<'\n';
    cout<<inputYear<<'\n';

     for( auto itr = tempMap.begin(); itr!= tempMap.end(); ++itr)
    {

        if(inputYear == itr->second.GetYear())
        {
            monthCount = itr->second.GetMonth();
            totalSpeedArr[monthCount]= itr->second.GetSpeed() + totalSpeedArr[monthCount]; // use the month as the index of the arrays
            totalTempArr[monthCount] = itr->second.GetTemp() + totalTempArr[monthCount];
            totalDataCount[monthCount]++; // keep track of total line items so can calculate average later
        }

    }


    for(int x=1 ; x<13; x++) // X start from 1 to skip index 0 of month array
    {
        if(totalSpeedArr[x]!= 0 && totalTempArr[x]!= 0 ) // loop through arrays and check for valid data

        {
            totalSpeedArr[x] = totalSpeedArr[x] * 3.6; // convert to KM/H
            avgSpeedArr[x] = totalSpeedArr[x] /totalDataCount[x];
            avgTempArr[x] = totalTempArr[x] / totalDataCount[x];
            cout<<month[x]<<": "<<fixed<<setprecision(1)<<avgSpeedArr[x]<<" km/h "<<avgTempArr[x]<<" Degrees C"<<endl;

        }


        if(totalSpeedArr[x]== 0 || totalTempArr[x]== 0 ) // if data is 0, output message
        {
            cout<<month[x]<<" : No Data"<<endl;
        }
    }

}


void MonthySolarRad(Vector<WindLogType> & windlog)
{
    // arrays to store the data by month, month = index
    // array is size 13 because index 0 will be unused
    double totalSolarArr[13] = {0};
    int monthCount=0;
    int inputYear;
    float wH = (1.0/6.0); // multiply w/m2 by 1/6 to get Wh



    cout<<"Please enter year"<<'\n';
    cin>>inputYear;

    cout<<'\n';
    cout<<inputYear<<'\n';


    for (int x =0; x<windlog.GetSize(); x++)
    {

        if(inputYear == windlog.At(x).GetYear()) // loop through vector to find the required year
        {
            monthCount = windlog.At(x).GetMonth();


            if(windlog.At(x).GetSolarRad()>=100) // only accept SR>=100 for calculation
            {

                totalSolarArr[monthCount]= windlog.At(x).GetSolarRad() + totalSolarArr[monthCount];

            }


        }

    }


    for(int x=1 ; x<13; x++) // X start from 1 to skip index 0 of month array
    {
        if(totalSolarArr[x]!= 0) // check for valid data

        {
            totalSolarArr[x] = totalSolarArr[x] * wH /(1000); // Converting to kWh/m2
            cout<<month[x]<<": "<<fixed<<setprecision(1)<<totalSolarArr[x]<<" kWh/m2 "<<endl;

        }

        if(totalSolarArr[x]== 0)
        {


            cout<<month[x]<<" : No Data"<<endl;
        }

    }

}

void MonthySolarRadMap(/*multimap<pair<int,int>, WindLogType>*/ multiWindMap &tempMap)
{
    // arrays to store the data by month, month = index
    // array is size 13 because index 0 will be unused
    double totalSolarArr[13] = {0};
    int monthCount=0;
    int inputYear;
    float wH = (1.0/6.0); // multiply w/m2 by 1/6 to get Wh



    cout<<"Please enter year"<<'\n';
    cin>>inputYear;

    cout<<'\n';
    cout<<inputYear<<'\n';


    for( auto itr = tempMap.begin(); itr!= tempMap.end(); ++itr)
    {

        if(inputYear == itr->second.GetYear())
        {
            monthCount = itr->second.GetMonth();

             if(itr->second.GetSolarRad()>=100) // only accept SR>=100 for calculation
            {

                    totalSolarArr[monthCount]= itr->second.GetSolarRad() + totalSolarArr[monthCount];
        }

    }

    }



    for(int x=1 ; x<13; x++) // X start from 1 to skip index 0 of month array
    {
        if(totalSolarArr[x]!= 0) // check for valid data

        {
            totalSolarArr[x] = totalSolarArr[x] * wH /(1000); // Converting to kWh/m2
            cout<<month[x]<<": "<<fixed<<setprecision(1)<<totalSolarArr[x]<<" kWh/m2 "<<endl;

        }

        if(totalSolarArr[x]== 0)
        {


            cout<<month[x]<<" : No Data"<<endl;
        }

    }

}

void WriteToCSV(Vector<WindLogType> & windlog)
{
    // arrays to store the data by month, month = index
    // array is size 13 because index 0 will be unused
    double totalSpeedArr [13] = {0},totalTempArr[13] = {0},totalSolarArr[13]= {0},avgSpeedArr[13]= {0},avgTempArr[13]= {0};
    int totalDataCount[13]= {0};
    int monthCount=0;
    int inputYear;
    float wH = (1.0/6.0); // multiply w/m2 by 1/6 to get Wh
    bool fileWritten = false; // boolean to check for file written status

    ofstream ofile( "WindTempSolar.csv" ); // open file for writing

    cout<<"Please enter year"<<'\n';
    cin>>inputYear;

    ofile<<inputYear<<'\n'; // write year to CSV first as first row


    for (int x =0; x<windlog.GetSize(); x++)
    {

        if(inputYear == windlog.At(x).GetYear()) // loop through vector to find year and extract monthly data
        {

            monthCount = windlog.At(x).GetMonth();
            totalSpeedArr[monthCount]= windlog.At(x).GetSpeed() + totalSpeedArr[monthCount];
            totalTempArr[monthCount] = windlog.At(x).GetTemp() + totalTempArr[monthCount];
            totalDataCount[monthCount]++;


            if(windlog.At(x).GetSolarRad()>=100) // only accept SR>+100 for calculation
            {

                totalSolarArr[monthCount]= windlog.At(x).GetSolarRad() + totalSolarArr[monthCount];

            }

        }

    }

    for(int x=1 ; x<13; x++) // X start from 1 to skip index 0 of month array
    {
        if(totalSpeedArr[x]!= 0 && totalTempArr[x]!= 0 && totalSolarArr[x]!= 0 ) // Check whether got data inside the arrays
        {

            totalSpeedArr[x] = totalSpeedArr[x] * 3.6; // convert to KM/H
            avgSpeedArr[x] = totalSpeedArr[x] /totalDataCount[x];
            avgTempArr[x] = totalTempArr[x] / totalDataCount[x];
            totalSolarArr[x] = totalSolarArr[x] * wH /(1000); // converting to kWh/m2

            ofile<<month[x]<<fixed<<setprecision(1)<<","<<avgSpeedArr[x]<<","<<avgTempArr[x]<<","<<totalSolarArr[x]<<'\n'; //++++

            fileWritten = true; // valid data extracted and will be written, boolean change to true


        }


    }

    if (fileWritten == true) // if true, output file written message
    {
        cout<<"Data written to WindTempSolar.csv"<<endl;
    }

    if (fileWritten == false) // if false, output no data available
    {
        cout<<"No data at year specified"<<endl;
        cout<<"Please try again!"<<endl;
        ofile<<"No Data"<<'\n';
    }


    ofile.close(); // close file
}

void WriteToCSVMap(/*multimap<pair<int,int>, WindLogType>*/ multiWindMap &tempMap)
{
    // arrays to store the data by month, month = index
    // array is size 13 because index 0 will be unused
    double totalSpeedArr [13] = {0},totalTempArr[13] = {0},totalSolarArr[13]= {0},avgSpeedArr[13]= {0},avgTempArr[13]= {0};
    int totalDataCount[13]= {0};
    int monthCount=0;
    int inputYear;
    float wH = (1.0/6.0); // multiply w/m2 by 1/6 to get Wh
    bool fileWritten = false; // boolean to check for file written status

    ofstream ofile( "WindTempSolar.csv" ); // open file for writing

    cout<<"Please enter year"<<'\n';
    cin>>inputYear;

    ofile<<inputYear<<'\n'; // write year to CSV first as first row

     for( auto itr = tempMap.begin(); itr!= tempMap.end(); ++itr)
    {

        if(inputYear == itr->second.GetYear())
        {
            monthCount = itr->second.GetMonth();
            totalSpeedArr[monthCount]= itr->second.GetSpeed() + totalSpeedArr[monthCount];
            totalTempArr[monthCount] = itr->second.GetTemp() + totalTempArr[monthCount];
            totalDataCount[monthCount]++;

             if(itr->second.GetSolarRad()>=100) // only accept SR>=100 for calculation
            {

                    totalSolarArr[monthCount]= itr->second.GetSolarRad() + totalSolarArr[monthCount];
        }

    }

    }



    for(int x=1 ; x<13; x++) // X start from 1 to skip index 0 of month array
    {
        if(totalSpeedArr[x]!= 0 && totalTempArr[x]!= 0 && totalSolarArr[x]!= 0 ) // Check whether got data inside the arrays
        {

            totalSpeedArr[x] = totalSpeedArr[x] * 3.6; // convert to KM/H
            avgSpeedArr[x] = totalSpeedArr[x] /totalDataCount[x];
            avgTempArr[x] = totalTempArr[x] / totalDataCount[x];
            totalSolarArr[x] = totalSolarArr[x] * wH /(1000); // converting to kWh/m2

            ofile<<month[x]<<fixed<<setprecision(1)<<","<<avgSpeedArr[x]<<","<<avgTempArr[x]<<","<<totalSolarArr[x]<<'\n'; //++++

            fileWritten = true; // valid data extracted and will be written, boolean change to true


        }


    }

    if (fileWritten == true) // if true, output file written message
    {
        cout<<"Data written to WindTempSolar.csv"<<endl;
    }

    if (fileWritten == false) // if false, output no data available
    {
        cout<<"No data at year specified"<<endl;
        cout<<"Please try again!"<<endl;
        ofile<<"No Data"<<'\n';
    }


    ofile.close(); // close file
}


void GetMaxSolarRad(multiWindMap &tempMap)
{
    BinarySearchTree<float> floatTree;

     int inputDay;
     int inputMonth;
     int inputYear;
     Time tempTime;

    cout<<"Please input day first"<<'\n';
    cin>>inputDay;
    cout<<"Please input month"<<'\n';
    cin>>inputMonth;
    cout<<"Please input year, press ENTER once done"<<'\n';
    cin>>inputYear;

     for( auto itr = tempMap.begin(); itr!= tempMap.end(); ++itr)
    {

        if(inputYear == itr->second.GetYear() && inputMonth == itr->second.GetMonth() && inputMonth == itr->second.GetDay())
        {


         floatTree.InsertTimeKey(itr->second.GetSolarRad(),itr->second.GetTime(tempTime)); //Insert all solarRadiation and time that meets the criteria into a BST


        }


}

  //floatTree.InOrderTraversal(); // Test output
  cout<<endl;
   cout<<"Date: " <<inputDay<<"/"<<inputMonth<<"/"<<inputYear<<endl;
  cout<<"High solar radiation for the day: "<<floatTree.GetMax()<<endl;
  cout<<"Time:"<<endl;
  cout<<floatTree.GetMaxKey()<<endl;

}
// Main program:
int main()
{


     //multimap <int,WindLogType> logMap;
    //multimap <int,WindLogType>::iterator itr;
    //multimap<pair<int,int>,WindLogType> multiLog;
    //multimap<pair<int,int>,WindLogType> logMap;
    //multimap<pair<int,int>,WindLogType> :: iterator itr;


    multiWindMap logMap;
    multiStringMap stringMap;

    string filename;
    ifstream inputFile;
    string topline;
    string token;
    string rows;


    filename = "/Users/sengw/Desktop/ICT 283/ICT283_Asignment2_Lim_Seng_Wei_34408441/codeblocks/data/met_index.txt";
    inputFile.open(filename.c_str());

 while(!inputFile.eof())
         {
              inputFile >> token;
              //cout<<"File:" << token << endl;
              //ReadCSVToMap(token,logMap);
             //ReadCSVToVector(token,windlog);
             ReadCSVToMap(token,stringMap);

         }

        cout<<"MAP SIZE "<<stringMap.size()<<endl;
        //print(logMap);


         //cout<<"Size:" << windlog.GetSize()<<endl;


         //TEST OUTPUT
   // for( auto itr = logMap.begin(); itr!= logMap.end(); ++itr)
   //     {cout<<"WINDLOG MAP TEST"<<endl;
  //  cout<<itr->first << " " << itr->second<<endl;}





   int inputChoice =0;



   while(inputChoice!=5) // exit menu loop when 5 is input
    {


        cout<<'\n'; // Formatting
        cout<<"Please choose an option from below Menu"<<endl;
        cout<<"___________________________________________________________________________________________________________________"<<endl;
        cout<<"Menu:"<<endl;
        cout<<"1. The average wind speed and average ambient air temperature for a specified month and year. (print on screen only)"<<endl;
        cout<<"2. Average wind speed and average ambient air temperature for each month of a specified year. (print on screen only)"<<endl;
        cout<<"3. Total solar radiation in kWh/m2 for each month of a specified year. (print on screen only)"<<endl;
        cout<<"4. Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m2 for each month of a specified year."<<endl;
        cout<<"5. Highest Solar radiation of a given day."<<endl;
        cout<<"6. Exit the program."<<endl;
        cout<<"___________________________________________________________________________________________________________________"<<endl;


        cin>>inputChoice;


        switch(inputChoice)
        {

        case 1:

            //AvgSpeedAndTempMap(logMap);
            //AvgSpeedAndTemp(windlog);
            AvgSpeedAndTempMapPair(logMap);
            break;

        case 2:
            //MonthlyAvgSpeedAndTemp(windlog);
            MonthlyAvgSpeedAndTempMap(logMap);
            break;

        case 3:
            //MonthySolarRad(windlog);
            MonthySolarRadMap(logMap);
            break;

        case 4:
            //WriteToCSV(windlog);
            WriteToCSVMap(logMap);
            break;

        case 5:

            GetMaxSolarRad(logMap);
            break;

        case 6:
            cout<<"Exiting program!"<<endl;
            break;

        default:

            cout<<"Invalid input!"<<endl;
            break;



        }
    }



    return 0;


}


istream &operator >>(istream & input, WindLogType & Te)
{

    return input;
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

    cout<<"Date: " <<day<<"/"<<month<<"/"<<year<<endl;
    cout <<"High Solar Radiation for the day: " <<maxRad<<endl;


return maxRad;

}

//////////////////PUT BACK IF GOT ERROR??///////////////////////////
/*ostream& operator<<(ostream &out, const pair<int, int> &p) // Overloading operator for map pair output
{
    return out << p.first << " " << p.second;
}*/

/*bool operator<(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first < b.first) return true;
    else if ((a.first == b.first) && (a.second > b.second)) return true;
    return false;
}*/

/*ostream & operator <<( ostream & os, const WindLogType & Te )
{
    Date date;
    Time time;
    Te.GetDate(date);
    Te.GetTime(time);

    os<<date<<" "<<time<<" "<<"Speed: "<<Te.GetSpeed()<<" Solar Radiation: "<<Te.GetSolarRad()
      <<" Temperature: "<<Te.GetTemp()<<'\n';

    return os;
}*/


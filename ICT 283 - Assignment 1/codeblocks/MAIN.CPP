// MAIN.CPP

//
//
//

#include <iostream>
#include <fstream>
#include "DATE.H"
#include "TIME.H"
#include "VECTOR.H"
#include <string.h>
#include <sstream>
#include <bits/stdc++.h>
#include <unordered_set>
#include <iomanip>

using namespace std;



typedef struct
{
    Date d;
    Time t;
    float speed;
    float solarRadiation;
    float temperature;
} WindLogType;

istream &operator >>(istream & input, WindLogType & Te);
ostream & operator <<( ostream & os, const WindLogType & Te );

 string month[13] ={" ", "January","February","March","April","May","June",
                       "July","August","September","October","November","December"}; // Array to store the month accordingly to their number

//Functions:

void Option1(vectorClass<WindLogType> & windlog)
{
        int inputMonth;
        int inputYear;
        int totalSpeed=0;
        float totalTemp=0;
        int totalDataCount=0;
        double avgSpeed = 0;
        double avgTemp = 0;

      cout<<"Please enter month and year"<<'\n';
        cin>>inputMonth>>inputYear;
        cout<<"input received "<<inputMonth<<" "<<inputYear<<'\n';


       /* for (int x =0; x<windlog.GetSize(); x++)  /////////// NOT IN USE //////////////
    {

        if(inputMonth!=windlog.At(x).d.GettingMonth() && inputYear!=windlog.At(x).d.GettingYear()) // check if input is valid to begin search
        {
            cout<<"No corresponding month and year found!"<<endl;
            break;
        }

    }
    //above not in use*/

        for (int x =0; x<windlog.GetSize(); x++)
    {

        if(inputYear == windlog.At(x).d.GettingYear() && inputMonth == windlog.At(x).d.GettingMonth())
        {

                totalSpeed=windlog.At(x).speed + totalSpeed;
                totalTemp=windlog.At(x).temperature + totalTemp;
                totalDataCount++;
        }


        }

        cout<<"TOTAL LINE ITEM "<<totalDataCount<<endl;
        cout<<"TOTAL SPEED "<<totalSpeed<<'\n';
        cout<<"Total Temperature "<<totalTemp<<'\n';
        totalSpeed = totalSpeed *3.6; // Convert to KM/H

         avgSpeed = totalSpeed/totalDataCount;
         avgTemp = totalTemp/totalDataCount;

        if (avgSpeed !=0 || avgTemp != 0) // check whether data is valid
        {
            cout<<month[inputMonth]<<" "<<inputYear<<" : "<<fixed<<setprecision(1)<< avgSpeed<<" km/h, "<<avgTemp<<" degrees C"<<'\n';
        }

        else

        {
            cout<<month[inputMonth]<<" "<<inputYear<<" : No Data"<<endl;
        }
}



// Main program:
int main()
{
    vectorClass<WindLogType> windlog;
    vectorClass<string> column;

    WindLogType w1;


    string filename;
    ifstream inputFile;
    string topline;
    string token;
    string rows;
    string temp;
    int IndexOfS=0;
    int IndexOfWAST=0;

    //filename = "/Users/sengw/Desktop/ICT 283/ICT 283 - Assignment 1/codeblocks/data/MetData_Mar01-2015-Mar01-2016-ALL.csv";
    filename = "MetData-31-3.csv";
    inputFile.open(filename.c_str());

    getline(inputFile,topline, '\n');
    stringstream firstrow ;
    firstrow<<topline;

    while(getline(firstrow,token, ','))
    {

        column.Add(token);
    }


    for(int z=0; z<column.GetSize(); z++) // Finding columns that is required
    {
        if(column.At(z) == "WAST")
        {
            cout<<column.At(z)<<" ";
            IndexOfWAST = z; // finding the index of column WAST

        }

        if (column.At(z) == "S")
        {
            cout<<column.At(z)<<'\n';
            IndexOfS = z; // finding the index of column S

        }

    }

    while(getline(inputFile,rows,'/'))
    //while(!inputFile.eof())

    {

        WindLogType w1;

        //getline(inputFile,rows, '/');
        int day1 = stoi(rows);
        w1.d.SetDay(day1);

        getline(inputFile,rows, '/');
        int month1 = stoi(rows);
        w1.d.SetMonth(month1);

        getline(inputFile,rows, ' ');
        int year1 = stoi(rows);
        w1.d.SetYear(year1);

        getline(inputFile,rows, ':');
        int hour1 = stoi(rows);
        w1.t.SetHour(hour1);

        getline(inputFile,rows, ',');
        int min1 = stoi(rows);
        w1.t.SetMin(min1);


        for(int k = 0; k < 9; k++) //need 9 time
        {
            getline(inputFile,rows, ',');


        }

        getline(inputFile,rows, ',');
        float tempSpeed = stoi(rows);
        w1.speed = tempSpeed;


        getline(inputFile,rows, ',');
        float tempSR = stoi(rows);
        w1.solarRadiation = tempSR;

        for(int p = 0; p < 5; p++)
        {
            getline(inputFile,rows, ',');

        }

        /*getline(inputFile,rows, ',');
        getline(inputFile,rows, ',');
        getline(inputFile,rows, ',');
        getline(inputFile,rows, ',');
        getline(inputFile,rows, ',');*/

        getline(inputFile,rows);
        float temperature1 = stof(rows);
        w1.temperature = temperature1;

        inputFile >> w1;
        windlog.Add(w1);
        //getline(inputFile,rows); // SKIP ALL REMAINING COLUMNS


        cout<<w1;  // CHECK OUTPUT, but too MANY

     /* ofstream ofile( "WindSpeed.txt" );
       ofile<<column.At(IndexOfWAST)<<" "<<column.At(IndexOfS)<<'\n';


        for(int i = 0; i<windlog.GetSize(); i++)
        {

            ofile << windlog.At(i);
        }*/


    }

    int inputChoice =0;

        while(inputChoice!=5) // exit loop when 5 is input
    {



    cout<<"Please choose an option from below Menu"<<endl;
    cout<<"___________________________________________________________________________________________________________________"<<endl;
    cout<<"Menu:"<<endl;
    cout<<"1. The average wind speed and average ambient air temperature for a specified month and year. (print on screen only)"<<endl;
    cout<<"2. Average wind speed and average ambient air temperature for each month of a specified year. (print on screen only)"<<endl;
    cout<<"3. Total solar radiation in kWh/m2 for each month of a specified year. (print on screen only)"<<endl;
    cout<<"4. Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m2 for each month of a specified year."<<endl;
    cout<<"5. Exit the program."<<endl;
    cout<<"___________________________________________________________________________________________________________________"<<endl;


    cin>>inputChoice;




    switch(inputChoice){

case 1:

Option1(windlog);
break;

case 2:

break;

case 3:

break;

case 4:

break;

case 5:
cout<<"Exiting program!"<<endl;
break;

default:

cout<<"Invalid input!"<<endl;
break;



    }
    }



//////////////////////OPTION 1/////////////////////////////////////////////
/*      int inputMonth;
        int inputYear;
        int totalSpeed=0;
        float totalTemp=0;
        int totalDataCount=0;
        double avgSpeed = 0;
        double avgTemp = 0;

      cout<<"Please enter month and year"<<'\n';
        cin>>inputMonth>>inputYear;
        cout<<"input received "<<inputMonth<<" "<<inputYear<<'\n';


/*         for (int x =0; x<windlog.GetSize(); x++)  /////////// NOT IN USE //////////////
    {

        if(inputMonth!=windlog.At(x).d.GettingMonth() && inputYear!=windlog.At(x).d.GettingYear()) // check if input is valid to begin search
        {
            cout<<"No corresponding month and year found!"<<endl;
            break;
        }

    }
    //above not in use

        for (int x =0; x<windlog.GetSize(); x++)
    {

        if(inputYear == windlog.At(x).d.GettingYear() && inputMonth == windlog.At(x).d.GettingMonth())
        {

                totalSpeed=windlog.At(x).speed + totalSpeed;
                totalTemp=windlog.At(x).temperature + totalTemp;
                totalDataCount++;
        }


        }

        cout<<"TOTAL LINE ITEM "<<totalDataCount<<endl;
        cout<<"TOTAL SPEED "<<totalSpeed<<'\n';
        cout<<"Total Temperature "<<totalTemp<<'\n';
        totalSpeed = totalSpeed *3.6; // Convert to KM/H

         avgSpeed = totalSpeed/totalDataCount;
         avgTemp = totalTemp/totalDataCount;

        if (avgSpeed !=0 || avgTemp != 0) // check whether data is valid
        {
            cout<<month[inputMonth-1]<<" "<<inputYear<<" : "<<fixed<<setprecision(1)<< avgSpeed<<" km/h, "<<avgTemp<<" degrees C"<<'\n';
        }

        else

        {
            cout<<month[inputMonth-1]<<" "<<inputYear<<" : No Data"<<endl;
        }

        */
/////////////////////OPTION 1 END////////////////////////////////////////
////////////////////OPTION 2 START//////////////////////////////////////

/*      double totalSpeedArr [13] ={0},totalTempArr[13] ={0},avgSpeedArr[13]={0},avgTempArr[13]={0};
        int totalDataCount[13]={0};
        int monthCount=0;
        int inputYear;

        cout<<"Please enter year"<<'\n';
        cin>>inputYear;
        cout<<inputYear<<'\n';


         for (int x =0; x<windlog.GetSize(); x++)
    {

        if(inputYear == windlog.At(x).d.GettingYear())
        {
            monthCount = windlog.At(x).d.GettingMonth();
            totalSpeedArr[monthCount]= windlog.At(x).speed + totalSpeedArr[monthCount];
            totalTempArr[monthCount] = windlog.At(x).temperature + totalTempArr[monthCount];
            totalDataCount[monthCount]++;



        }

    }
/*    int currentIndex=0;  /// TESTING COUNT
    for (int x=0;x<13;x++)
    {

            cout<<"SPEED COUNTER "<<totalSpeedArr[x]<<endl;
            cout<<"TEMP COUNTER "<<totalTempArr[x]<<endl;
            cout<<"TOTAL LINE COUNTER "<<totalDataCount[x]<<endl;
            currentIndex++;

    }
 cout<<currentIndex<<endl;

        for(int x=1 ; x<13; x++)
        {
            if(totalSpeedArr[x]!= 0 && totalTempArr[x]!= 0 )

            {
                totalSpeedArr[x] = totalSpeedArr[x] * 3.6; // convert to KM/H
                avgSpeedArr[x] = totalSpeedArr[x] /totalDataCount[x];
                avgTempArr[x] = totalTempArr[x] / totalDataCount[x];
                cout<<month[x-1]<<": "<<fixed<<setprecision(1)<<avgSpeedArr[x]<<" km/h "<<avgTempArr[x]<<" Degrees C"<<endl;

            }



            if(totalSpeedArr[x]== 0 || totalTempArr[x]== 0 )
            {
                cout<<month[x-1]<<" : No Data"<<endl;
            }
        }  */

///////////////////OPTION 2 END/////////////////////////////////////
//////////////////OPTION 3 START///////////////////////////////////


/*        double totalSolarArr[13] ={0}; //,avgSolarArr[13]={0};
          //int totalDataCount[13]={0};

        int monthCount=0;
        int inputYear;
        float wH = (1.0/6.0); // multiply w/m2 by 1/6 to get Wh



        cout<<"Please enter year"<<'\n';
        cin>>inputYear;
        cout<<inputYear<<'\n';


         for (int x =0; x<windlog.GetSize(); x++)
    {

        if(inputYear == windlog.At(x).d.GettingYear())
        {
            //monthCount = windlog.At(x).d.GettingMonth();
            //totalSolarArr[monthCount]= windlog.At(x).solarRadiation + totalSolarArr[monthCount];
            //totalDataCount[monthCount]++;

               if(windlog.At(x).solarRadiation>=100) // only accept SR>+100 for calculation
            {
                monthCount = windlog.At(x).d.GettingMonth();
                totalSolarArr[monthCount] = windlog.At(x).solarRadiation * wH /(1000); // converting it to kWh, multiply by (1/6) then divide by 1000
                totalSolarArr[monthCount]= windlog.At(x).solarRadiation + totalSolarArr[monthCount];
                //totalDataCount[monthCount]++;
            }



        }
    }

        int currentIndex=0;  /// TESTING COUNT
    for (int x=0;x<13;x++)
    {

            cout<<"SOLAR COUNTER "<<totalSolarArr[x]<<endl;
            cout<<"TOTAL LINE COUNTER "<<totalDataCount[x]<<endl;
            currentIndex++;

    }
 cout<<currentIndex<<endl;


            for(int x=1 ; x<13; x++)
        {
            if(totalSolarArr[x]!= 0)

            {
                totalSolarArr[x] = totalSolarArr[x] /1000; // convert to kWh/m2
                //avgSolarArr[x] = totalSolarArr[x] /totalDataCount[x];
                cout<<month[x]<<": "<<fixed<<setprecision(1)<<totalSolarArr[x]<<" kWh/m2 "<<endl;

            }

             if(totalSolarArr[x]== 0)
            {


                 cout<<month[x]<<" : No Data"<<endl;
             }

        }*/



//////////////////OPTION 3 END///////////////////////////////////
//////////////////OPTION 4 START///////////////////////////////////

 /*       double totalSpeedArr [13] ={0},totalTempArr[13] ={0},totalSolarArr[13]={0},avgSpeedArr[13]={0},avgTempArr[13]={0};
        int totalDataCount[13]={0};
        int monthCount=0;
        int inputYear;
        float wH = (1.0/6.0); // multiply w/m2 by 1/6 to get Wh
        bool fileWritten = false;
        ofstream ofile( "WindTempSolar.csv" );


        cout<<"Please enter year"<<'\n';
        cin>>inputYear;
        cout<<inputYear<<'\n';



         for (int x =0; x<windlog.GetSize(); x++)
    {

        if(inputYear == windlog.At(x).d.GettingYear())
        {

            monthCount = windlog.At(x).d.GettingMonth();
            totalSpeedArr[monthCount]= windlog.At(x).speed + totalSpeedArr[monthCount];
            totalTempArr[monthCount] = windlog.At(x).temperature + totalTempArr[monthCount];

            totalDataCount[monthCount]++;


            if(windlog.At(x).solarRadiation>=100) // only accept SR>+100 for calculation
            {
                totalSolarArr[monthCount] = windlog.At(x).solarRadiation * wH /(1000); // converting it to kWh, multiply by (1/6) then divide by 1000
                totalSolarArr[monthCount]= windlog.At(x).solarRadiation + totalSolarArr[monthCount];

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
                fileWritten = true;
            }



            if(totalSpeedArr[x]== 0 || totalTempArr[x]== 0 || totalSolarArr[x]== 0 )

            {
                // DO NOTHING
            }

        }

         if (fileWritten == true)
        {
            ofile<<inputYear<<'\n';
            cout<<"Data written to WindTempSolar.csv"<<endl;
        }

        if (fileWritten == false)
        {
            cout<<"No data at year specified"<<endl;
            ofile<<inputYear<<'\n'<<"No Data";
        }


        for (int x=1 ; x<13; x++)
        {
            if(avgSpeedArr[x]!= 0 && avgTempArr[x]!= 0 && totalSolarArr[x]!= 0 )
            {

                ofile<<month[x]<<fixed<<setprecision(1)
                <<","<<avgSpeedArr[x]<<","<<avgTempArr[x]<<","<<totalSolarArr[x]<<'\n';
                fileWritten = true;

            }

        }


        ofile.close();  */

//////////////////OPTION 4 END///////////////////////////////////

return 0;


}





istream &operator >>(istream & input, WindLogType & Te)
{



   // input>>Te.d>>Te.t>>Te.speed>>Te.solarRadiation>>Te.temperature;



    return input;
}

ostream & operator <<( ostream & os, const WindLogType & Te )
{


    os<<Te.d<<" "<<Te.t<<" "<<"Speed: "<<Te.speed<<" Solar Radiation: "<<Te.solarRadiation
    <<" Temperature: "<<Te.temperature<<'\n';

    return os;
}


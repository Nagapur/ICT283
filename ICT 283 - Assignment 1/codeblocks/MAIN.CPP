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
#include <iomanip>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits

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

bool checkNumber(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}
void Option1(vectorClass<WindLogType> & windlog)
{
        int inputMonth;
        int inputYear;
        int totalSpeed=0;
        float totalTemp=0;
        int totalDataCount=0;
        double avgSpeed = 0;
        double avgTemp = 0;

        cout<<"Please input month first and then year, press ENTER after each input"<<'\n';
        cin>>inputMonth;
        cin>>inputYear;



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

        if(inputYear == windlog.At(x).d.GettingYear() && inputMonth == windlog.At(x).d.GettingMonth()) // loop through vector to check year and month
        {

                totalSpeed=windlog.At(x).speed + totalSpeed;
                totalTemp=windlog.At(x).temperature + totalTemp;
                totalDataCount++;
        }


        }

      //  cout<<"TOTAL LINE ITEM "<<totalDataCount<<endl;
       // cout<<"TOTAL SPEED "<<totalSpeed<<'\n';
       // cout<<"Total Temperature "<<totalTemp<<'\n';

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

void Option2(vectorClass<WindLogType> & windlog)
{
        double totalSpeedArr [13] ={0},totalTempArr[13] ={0},avgSpeedArr[13]={0},avgTempArr[13]={0}; // arrays to store the data by month, month = index
        int totalDataCount[13]={0}; // array to store the total line count                           // array is size 13 because index 0 will be unused
        int monthCount=0; // variable to represent the month in the arrays
        int inputYear;

        cout<<"Please enter year"<<'\n';
        cin>>inputYear;
        cout<<'\n';
        cout<<inputYear<<'\n';


         for (int x =0; x<windlog.GetSize(); x++)
    {

        if(inputYear == windlog.At(x).d.GettingYear())  // check for same year as per input and extract the month value
        {
            monthCount = windlog.At(x).d.GettingMonth();
            totalSpeedArr[monthCount]= windlog.At(x).speed + totalSpeedArr[monthCount]; // use the month as the index of the arrays
            totalTempArr[monthCount] = windlog.At(x).temperature + totalTempArr[monthCount];
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

void Option3(vectorClass<WindLogType> & windlog)
{
        // arrays to store the data by month, month = index
        // array is size 13 because index 0 will be unused
        double totalSolarArr[13] ={0};
        int monthCount=0;
        int inputYear;
        double temp;
        float wH = (1.0/6.0); // multiply w/m2 by 1/6 to get Wh



        cout<<"Please enter year"<<'\n';
        cin>>inputYear;

        cout<<'\n';
        cout<<inputYear<<'\n';


         for (int x =0; x<windlog.GetSize(); x++)
    {

        if(inputYear == windlog.At(x).d.GettingYear()) // loop through vector to find the required year
        {
            monthCount = windlog.At(x).d.GettingMonth();
            //totalSolarArr[monthCount]= windlog.At(x).solarRadiation + totalSolarArr[monthCount];
            //totalDataCount[monthCount]++;

              if(windlog.At(x).solarRadiation>=100) // only accept SR>=100 for calculation
            {

               // totalSolarArr[monthCount] = windlog.At(x).solarRadiation; // converting it to kWh, multiply by (1/6) then divide by 1000
                totalSolarArr[monthCount]= windlog.At(x).solarRadiation + totalSolarArr[monthCount];
                //totalDataCount[monthCount]++;
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

void Option4(vectorClass<WindLogType> & windlog)
{
        // arrays to store the data by month, month = index
        // array is size 13 because index 0 will be unused
        double totalSpeedArr [13] ={0},totalTempArr[13] ={0},totalSolarArr[13]={0},avgSpeedArr[13]={0},avgTempArr[13]={0};
        int totalDataCount[13]={0};
        int monthCount=0;
        int inputYear;
        float wH = (1.0/6.0); // multiply w/m2 by 1/6 to get Wh
        bool fileWritten = false; // boolean to check for file written status

        ofstream ofile( "WindTempSolar.csv" ); // open file for writing

        cout<<"Please enter year"<<'\n';
        cin>>inputYear;
        cout<<inputYear<<'\n';
        ofile<<inputYear<<'\n'; // write year to CSV first as first row


         for (int x =0; x<windlog.GetSize(); x++)
    {

        if(inputYear == windlog.At(x).d.GettingYear()) // loop through vector to find year and extract monthly data
        {

            monthCount = windlog.At(x).d.GettingMonth();
            totalSpeedArr[monthCount]= windlog.At(x).speed + totalSpeedArr[monthCount];
            totalTempArr[monthCount] = windlog.At(x).temperature + totalTempArr[monthCount];
            totalDataCount[monthCount]++;


            if(windlog.At(x).solarRadiation>=100) // only accept SR>+100 for calculation
            {

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
                totalSolarArr[x] = totalSolarArr[x] * wH /(1000); // converting to kWh/m2

                ofile<<month[x]<<fixed<<setprecision(1)<<","<<avgSpeedArr[x]<<","<<avgTempArr[x]<<","<<totalSolarArr[x]<<'\n'; //++++

                fileWritten = true; // valid data extracted and will be written, boolean change to true


            }



           /* if(totalSpeedArr[x]== 0 || totalTempArr[x]== 0 || totalSolarArr[x]== 0 )

            {

            }*/

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


     /*   for (int x=1 ; x<13; x++) // X start from 1 to skip index 0 of month array
        {
            if(avgSpeedArr[x]!= 0 && avgTempArr[x]!= 0 && totalSolarArr[x]!= 0 )
            {

                totalSolarArr[x] = totalSolarArr[x] * wH /(1000);
                ofile<<month[x]<<fixed<<setprecision(1)
                <<","<<avgSpeedArr[x]<<","<<avgTempArr[x]<<","<<totalSolarArr[x]<<'\n';
                fileWritten = true;

            }

        }*/


        ofile.close();
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


    //filename = "/Users/sengw/Desktop/ICT 283/ICT 283 - Assignment 1/codeblocks/data/MetData_Mar01-2015-Mar01-2016-ALL.csv";
    filename = "MetData-31-3.csv";
    inputFile.open(filename.c_str());

    getline(inputFile,topline, '\n');
    stringstream firstrow ;
    firstrow<<topline;

    while(getline(firstrow,token, ',')) //reading the first line of header information
    {

        column.Add(token);
    }


    while(getline(inputFile,rows,'/')) //reading the rest of the CSV from second line onwards


    {

        WindLogType w1;


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


        for(int k = 0; k < 9; k++) //skip data columns that not required
        {
            getline(inputFile,rows, ',');


        }

        getline(inputFile,rows, ','); //read speed column
        float tempSpeed = stoi(rows);
        w1.speed = tempSpeed;


        getline(inputFile,rows, ','); //read SR column
        float tempSR = stoi(rows);
        w1.solarRadiation = tempSR;

        for(int p = 0; p < 5; p++) // skip unwanted columns
        {
            getline(inputFile,rows, ',');

        }


        getline(inputFile,rows);   // read temperature column
        float temperature1 = stof(rows);
        w1.temperature = temperature1;

        inputFile >> w1;
        windlog.Add(w1);


        cout<<w1;  // CHECK OUTPUT, but too MANY


    }

    int inputChoice =0;
    int checkerChoice=0;
    string checker;





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
    cout<<"5. Exit the program."<<endl;
    cout<<"___________________________________________________________________________________________________________________"<<endl;


    cin>>inputChoice;




   /* cout<<"type number la"<<endl;
    getline(cin,checker);
    cout<<"CHECKER IS HERE"<<checker<<endl;

    if (checkNumber(checker))
    {
        checkerChoice = stoi(checker);
        inputChoice = checkerChoice;
    }

    else
    {
        cout<<"ENTER A NUMBER FKER!!"<<endl;
        break;
    }*/




    switch(inputChoice){

case 1:

Option1(windlog);
break;

case 2:
Option2(windlog);
break;

case 3:
Option3(windlog);
break;

case 4:
Option4(windlog);
break;

case 5:
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

ostream & operator <<( ostream & os, const WindLogType & Te )
{


    os<<Te.d<<" "<<Te.t<<" "<<"Speed: "<<Te.speed<<" Solar Radiation: "<<Te.solarRadiation
    <<" Temperature: "<<Te.temperature<<'\n';

    return os;
}


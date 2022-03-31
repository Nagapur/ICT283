#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Vector.h"
#include "Date.h"
#include "Time.h"
#include "BST.h"
#include <iomanip>
#include <map>

typedef struct  ///Type definition of struct type
{
    Date d;
    Time t;
    float speed;
    float solar;
}
WindLogType; ///creating new type

using namespace std;

///Input/Output overloading operator
ostream &operator <<(ostream &osObject , const WindLogType & T1);
istream & operator >> (istream &inFile, WindLogType &T1);


float * func2(Vector<WindLogType> wl, int yr) ///function that take in windlog and year.
    {
        ///Declare variables
        float sum[12];
        int num[12];
        static float r[12];

        for(int i=0; i<12;i++) ///Set array to 0 using for loop
        {
            sum[i]=0;
            num[i]=0;
            r[i]=0;
        }
        for(int i=0; i<wl.size(); i++) ///loop all data in windlog
        {
            if(wl.at(i).d.getYear()==yr)  ///if year = specified year
            {
                sum[wl.at(i).d.getMonth()-1]+=wl.at(i).speed; ///array of sum for month -1, +speed into array.
                num[wl.at(i).d.getMonth()-1]+=1;  ///array of count for month -1 , +count
            }
        }
        for(int i=0; i<12; i++)  ///loop array and store average to r
        {
            if(sum[i]!=0)
            {
                r[i]=sum[i]/num[i];
            }
        }
        return r;
    }

float * func3(Vector<WindLogType> wl2, int yr2) ///function to take in windlog and year
    {
        ///Declare variables
        float sum3[12];
        static float r3[12];

        for(int i=0; i<12;i++) ///Set all array to 0 using for loop
        {
            sum3[i]=0;
            r3[i]=0;
        }
        for(int i=0; i<wl2.size(); i++) ///loop all data in windlog
            {
                if(wl2.at(i).d.getYear()==yr2) ///if year = specified year
                {
                    sum3[(wl2.at(i).d.getMonth()-1)]+=wl2.at(i).solar; ///array of sum for month -1, +solar into array
                }
            }
        for(int i=0; i<12; i++) ///loop array and store sum of solar to r3
            {
                r3[i]=sum3[i];
            }
        return r3;
    }

    void func5(Vector<WindLogType> wl5, int d5, int m5, int y5){

        BST myBst;

        for(int i=0; i<wl5.size(); i++) ///loop all data in windlog
            {
                if(wl5.at(i).d.getYear()==y5 && wl5.at(i).d.getMonth()==m5 && wl5.at(i).d.getDay()==d5 ) ///if year = specified year
                {

                    if(wl5.at(i).solar != 0)
                    {
                       myBst.insert((float) wl5.at(i).solar, wl5.at(i).t.getFTime());
                    }
                }
            }
            float maxRad=myBst.getMax();
            multimap <string, float>  maxMap = myBst.search(maxRad);

            multimap<string,float>::iterator it;

            cout << "Date "<<d5<<"/"<<m5<<"/"<<y5<< endl;
             cout << "Highest solar radition for the day :" << maxRad<< "kWh/m2" <<endl;
              cout << endl;
               cout << "Time" << endl;

            for (it=maxMap.begin(); it != maxMap.end(); ++it)
            {
                cout << it -> first << '\n';
            }
    }

string wMth(int a)          ///array in a function for month int = month string
{
    string myArray[12];
        myArray[0] = "Janurary";
		myArray[1] = "Feburary";
		myArray[2] = "March";
		myArray[3] = "April";
		myArray[4] = "May";
		myArray[5] = "June";
		myArray[6] = "July";
		myArray[7] = "August";
		myArray[8] = "September";
		myArray[9] = "October";
		myArray[10] = "November";
		myArray[11] = "December";

    return myArray[a];
}
int main()
{
    string userinputfilename;
    cout<<"Welcome! Please input the directory you have stored the file at:"<<endl;
    cout<<"(ie. mac--> /Users/jkwj/Desktop/Assignment2/)"<<endl;
    cin>>userinputfilename;

    string filename;
    string outputFile;
   ifstream inFile;   ///input file
   ofstream outFile; ///output file
   Vector<WindLogType> windlog; ///vector holding the logs
   filename =userinputfilename+"/MetData_Mar01-2015-Mar01-2016-ALL.txt"; //change into an array of files



   //do{
   inFile.open(filename.c_str());//change the file name accordingly (using the array file names

   if (inFile.is_open())
   {
       ///Declare variables
       string line,day,month,year,hour,minutes,amonth,ayear;
       int speed;
       float solarRad;

       while (getline (inFile, line))
       {
           ///Get Date using "/", '," delimiter
           getline(inFile, day,'/');
           getline(inFile, month,'/');
           getline(inFile, year,' ');

           ///Get Time using ":" , "," delimiter
           getline(inFile,hour,':');
           getline(inFile,minutes,',');

           ///convert string to int
           int day1 = atoi (day.c_str());
           int month1 = atoi (month.c_str());
           int year1 = atoi (year.c_str());
           int hour1 = atoi (hour.c_str());
           int minutes1 = atoi (minutes.c_str());

            /// Get speed
           int s1;
           for (int i =0; i<10; i++)
           {
               inFile >> s1;
               inFile.ignore(44,',');
           }
           speed = s1;

           /// Get Solar Rad
           float sr1;
           for (int i =0; i<1;i++)
           {
               inFile >> sr1;
               inFile.ignore(1,',');
           }
           solarRad = sr1;
           if(solarRad < 100)
           {
               solarRad = 0;
           }
           else
           {
               solarRad = (solarRad * 1/6) / 1000; ///convert m^2 to kwh/m^2
           }

           ///Create a record
           WindLogType T1;
           T1.d.setDate(day1,month1,year1);
           T1.t.setTime(hour1,minutes1);
           T1.speed = s1;
           T1.solar = solarRad;

           ///Push inside vector
           windlog.push_back(T1);

/*         cout << "Date is:" << day << "/" << month << "/" << year << " "
                << "Time is:" << hour << "." << minutes << " "
                    << "Speed is:" << speed << " "
                        << "Solar Radiation is:" << solarRad << endl;
*/
       }
       inFile.close();
//while (still have file);





    ///Menu
    int choice;
    bool Exit = false;
    cout << "********************************************************************************\n";
    cout << "1 - Max Speed and for specified month & year.\n";
    cout << "2 - Average Wind Speed for each month of a specified year.\n";
    cout << "3 - Total Solar Radiation in kWh/m^2 for each month of a specified year.\n";
    cout << "4 - Average Wind Speed Km/h and total Solar Radiation in kWh/m^2 for each month of a specified year.\n";
    cout << "5 - Time of highest Solar Radiation for a specific date.\n";
    cout << "6 - Exit.\n";
    cout << "********************************************************************************\n";
    cout << "Enter your choice.\n";
    cin >> choice;

    do
    {
    switch (choice)
        {
        case 1:
            cout << "Max Wind Speed for specified month & year."<<endl;
            cout << "Enter the month. (in MM format)" <<endl;
            cin >> amonth;
            cout << "Enter the year. (in YYYY format)" <<endl;
            cin >> ayear;

            float maxSpeed;
            maxSpeed=0;
            for(int i=0; i<windlog.size(); i++)
            {
                    if(windlog.at(i).d.getMonth()== atoi (amonth.c_str())
                        && windlog.at(i).d.getYear()==atoi (ayear.c_str())
                        && windlog.at(i).speed>maxSpeed )
                {
                    maxSpeed = windlog.at(i).speed;
                }
            }
            cout << "Max Speed for " <<amonth << "/" <<ayear <<" is:" << " "<<maxSpeed <<endl;
            cout << "Enter your choice."<<endl;
            cin >> choice;
            break;

        case 2:
            cout << "Average Wind Speed for each month of a specified year."<<endl;
            cout << "Enter the year. (in YYYY format)" <<endl;
            cin >> year;

            float *averages;

            averages=func2(windlog,atoi (year.c_str()));

            cout<< "For the year "<<year<<",the average speed for each month is:" <<endl;
            cout << "Jan: " << averages[0] <<"\t Feb: " << averages[1] << "\t Mar: "<< averages[2]  << "\t Apr: " << averages[3]
            << "\t May: " <<averages[4]  << "\t Jun: " << averages[5]  << "\t Jul: " << averages[6]  << "\t Aug: " << (averages[7] )
            << "\t Sep: " << (averages[8] ) << "\t Oct: " << averages[9] << "\t Nov: " << averages[10]  << "\t Dec: " << averages[11]  << endl;

            cout << "Enter your choice." <<endl;
            cin >> choice;
            break;

        case 3:
            cout << "Total Solar Radiation in kWh/m^2 for each month of a specified year."<<endl;;
            cout << "Enter the year. (in YYYY format)"<<endl;
            cin >> year;

            float *solar;

            solar=func3(windlog,atoi (year.c_str()));

            cout<< "For the year "<<year<<",the solar radiation for each month in kWh/m^2 is:" <<endl;
            cout << "Jan: " << solar[0] <<"\t Feb: " << solar[1]  << "\t Mar: "<< solar[2]  << "\t Apr: " << solar[3]
            << "\t May: " << solar[4]  << "\t Jun: " << solar[5]  << "\t Jul: " << solar[6]  << "\t Aug: " << solar[7]
            << "\t Sep: " << solar[8]  << "\t Oct: " << solar[9]  << "\t Nov: " << solar[10]  << "\t Dec: " << solar[11]  << endl;

            cout << "Enter your choice."<<endl;
            cin >> choice;
            break;

        case 4:
            cout << "Average Wind Speed Km/h and total Solar Radiation in kWh/m^2 for each month of a specified year."<<endl;
            cout << "Enter the year. (in YYYY format)"<<endl;
            cin >> year;
            int yr;
            yr=atoi (year.c_str());

            float count4[12];
            float sum4[12];
            float solar4[12];

            for(int i=0; i<12;i++) ///Set all array to 0 using for loop
            {
                sum4[i]=0;
                count4[i]=0;
                solar4[i]=0;
            }
            for(int i=0; i<windlog.size(); i++)
            {
                if(windlog.at(i).d.getYear()==yr)
                {
                    solar4[(windlog.at(i).d.getMonth()-1)]+=windlog.at(i).solar;
                    count4[(windlog.at(i).d.getMonth()-1)]+=1;
                    sum4[(windlog.at(i).d.getMonth()-1)]+=windlog.at(i).speed;
                }
            }
            outputFile= userinputfilename+ "WindandSolar.csv";
            outFile.open(outputFile,ios::out | ios::app);
            outFile<< yr <<"\n";
            for(int k=0; k<12; k++)
            {
                outFile<< wMth(k)<<",";
                if(count4[k]!=0)
                {
                    outFile << (sum4[k]/count4[k]);
                }else
                {
                    outFile << 0;
                }
                outFile<< "," << solar4[k]<<"\n";
            }
            outFile.close();
            cout << "Printed to file : WindandSolar.csv" << endl;
            cout << "Enter your choice."<<endl;
            cin >> choice;
            break;

        case 5:
            int d05,m05,y05;
            cout << "Enter the Year (in YYYY format)" <<endl;
            cin >> y05;
            cout <<"Enter the Month (in MM format)" << endl;
            cin >>m05;
            cout << "Enter the Day (in DD format)" <<endl;
            cin >>d05;

            func5(windlog,d05,m05,y05);

            cout << "Enter your choice."<<endl;
            cin >> choice;
            break;

        case 6:
            cout << "Exit."<<endl;
            Exit = true;
            break;

        default:
            cout << "Choice not vaild."<<endl;
            cout << "Please choose option from the menu."<<endl;
            cin >> choice;
            break;
        }
    }
    while(!Exit);
   }
   else
    cout <<"Error opening file"<< endl;
   return 0;
}

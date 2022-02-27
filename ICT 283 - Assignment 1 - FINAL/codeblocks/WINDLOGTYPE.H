#ifndef WINDLOGTYPE_H_INCLUDED
#define WINDLOGTYPE_H_INCLUDED
#include "DATE.H"
#include "TIME.H"
#include <iostream>
#include <string.h>

/**
 * @class WindLogType
 * @brief  WindLogType consisting of data read from CSV
 *
 * WindLogType class that is used to manage objects of WindLogType class
 * has appropriate Getters and Setters to access the information in this class and also from Date and Time
 * Variables are private
 *
 *
 *
 * @author Lim Seng Wei
 * @version 01
 * @date 25/02/2022
 *
 */

using namespace std;

class WindLogType
{
public:

    /**
    * @brief  Default constructor
    *
    * This function will be automatically called to initialize an object of this class
    *
    */
    WindLogType();

    /**
    * @brief  Constructor with parameters
    *
    * This function can set initial values for the attributes
    *
    *
    * @param  d,t,speed,solarRadiation,temperature - date object, time object, and the 3 data that will be read from CSV
    */
    WindLogType(Date d, Time t, float speed, float solarRadiation, float temperature);

    /**
      * @brief  Getter for Date object
      *
      * retrieve Date object
      *
      *
      *
      * @param  Date &da
      * @return void
      */
    void GetDate(Date &da)const;

    /**
    * @brief  Getter for Time object
    *
    * retrieve Time object
    *
    *
    *
    * @param  Time &ti
    * @return void
    */
    void GetTime(Time &ti)const;

    /**
    * @brief  Setter for day
    *
    * Set the value of day into Date object
    *
    *
    *
    * @param  xDay, value to become day
    * @return void
    */
    void SetDay(const int &xDay);

    /**
    * @brief  Setter for month
    *
    * Set the value of month into Date object
    *
    *
    *
    * @param  xMonth, value to become day
    * @return void
    */
    void SetMonth(const int &xMonth);

    /**
     * @brief  Setter for year
     *
     * Set the value of year into Date object
     *
     *
     *
     * @param  xYear, value to become year
     * @return void
     */
    void SetYear(const int &xYear);

    /**
    * @brief  Setter for hour
    *
    * Set the value of hour into Time object
    *
    *
    *
    * @param  xHour, value to become hour
    * @return void
    */
    void SetHour(const int &xHour);

    /**
    * @brief  Setter for minute
    *
    * Set the value of minute into Time object
    *
    *
    *
    * @param  xMin, value to become minute
    * @return void
    */
    void SetMin(const int &xMin);

    /**
    * @brief  Getter for value of day
    *
    * return day from Date object
    *
    *
    *
    * @param NIL
    * @return int
    */

    int GetDay()const;

    /**
    * @brief  Getter for value of month
    *
    * return month from Date object
    *
    *
    *
    * @param NIL
    * @return int
    */
    int GetMonth()const;

    /**
    * @brief  Getter for value of year
    *
    * return year from Date object
    *
    *
    *
    * @param NIL
    * @return int
    */
    int GetYear()const;

    /**
    * @brief  Getter for hour of time
    *
    * return hour from time object
    *
    *
    *
    * @param NIL
    * @return int
    */
    int GetHour()const;

    /**
    * @brief  Getter for minute of time
    *
    * return minute from time object
    *
    *
    *
    * @param NIL
    * @return int
    */
    int GetMin()const;

    /**
    * @brief  Getter for value of speed
    *
    * return speed
    *
    *
    *
    * @param NIL
    * @return float
    */

    float GetSpeed()const;

    /**
    * @brief  Setter for speed
    *
    * Set the value of speed
    *
    *
    *
    * @param  xSpeed, value to become speed
    * @return void
    */
    void SetSpeed( const float &xSpeed );

    /**
    * @brief  Getter for value of solar radiation
    *
    * return solarRadiation
    *
    *
    *
    * @param NIL
    * @return float
    */
    float GetSolarRad()const;

    /**
    * @brief  Setter for solar radiation
    *
    * Set the value of solarRadiation
    *
    *
    *
    * @param  xSolarR, value to become solarRadiation
    * @return void
    */
    void SetSolarRad( const float &xSolarR );

    /**
    * @brief  Getter for value of temperature
    *
    * return temperature
    *
    *
    *
    * @param NIL
    * @return float
    */
    float GetTemp()const;

    /**
    * @brief  Setter for temperature
    *
    * Set the value of temperature
    *
    *
    *
    * @param  xTemp, value to become temperature
    * @return void
    */
    void SetTemp( const float &xTemp );



private:

    Date d;
    Time t;
    float speed;
    float solarRadiation;
    float temperature;
};


#endif // WINDLOGTYPE_H_INCLUDED

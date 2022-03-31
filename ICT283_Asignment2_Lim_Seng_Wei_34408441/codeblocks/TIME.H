#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>
#include <string.h>

/**
 * @class Time
 * @brief  Manages all time information
 *
 * Time class that is used to manage objects of Time class
 * has appropriate Getters and Setters to access the information in this class
 * Variables are private
 *
 *
 *
 * @author Lim Seng Wei
 * @version 01
 * @date 3/03/2022
 *
 */

using namespace std;

//---------------------------------------------------------------------------------

class Time

{
public:

    /**
     * @brief  Default constructor
     *
     * This function will be automatically called to initialize an object of this class
     *
     */
    Time();

    /**
    * @brief  Constructor with parameters
    *
    * This function can set initial values for the attributes
    *
    *
    * @param  hrs,mins - hours and minutes of a particular time
    */
    Time(int hrs, int mins);

    /**
    * @brief  Getter for hour
    *
    * returns the value of hour
    *
    *
    *
    * @param  NIL
    * @return int
    */
    int  GettingHour()const;

    /**
     * @brief  Setter for hour
     *
     * Set a value into hour
     *
     *
     *
     * @param  xHour , value to become hour
     * @return void
     */
    void SetHour( const int &xHour );

    /**
     * @brief  Getter for minute
     *
     * returns the value of minute
     *
     *
     *
     * @param  NIL
     * @return int
     */
    int GettingMin()const;

    /**
     * @brief  Setter for minute
     *
     * Set a value into minute
     *
     *
     *
     * @param  xMinute , value to become minute
     * @return void
     */
    void SetMin( const int &xMinute );

private:
    int hour;
    int minute;

};

istream & operator >>( istream & input, Time & T );
ostream & operator <<( ostream & os, const Time & T );

#endif // TIME_H_INCLUDED


#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
#include <string.h>

/**
 * @class Date
 * @brief  Manages all date information
 *
 * Date class that is used to manage objects of Date class
 * has appropriate Getters and Setters to access the information in this class
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

//---------------------------------------------------------------------------------

class Date
{
public:

    /**
    * @brief  Default constructor
    *
    * This function will be automatically called to initialize an object of this class
    *
    */
    Date();

    /**
     * @brief  Constructor with parameters
     *
     * This function can set initial values for the attributes
     *
     *
     * @param  xDay,xMonth,xYear - day,month and year of a particular date
     */
    Date(int xDay, int xMonth, int xYear);


    /**
     * @brief  Getter for day
     *
     * returns the value of day
     *
     *
     *
     * @param  NIL
     * @return int
     */
    int  GettingDay()const;


    /**
     * @brief  Setter for day
     *
     * Set a value into day
     *
     *
     *
     * @param  xDay , value to become day
     * @return void
     */
    void SetDay( const int &xDay );

    /**
     * @brief  Getter for month
     *
     * returns the value of month
     *
     *
     *
     * @param  NIL
     * @return int
     */
    int GettingMonth()const;

    /**
     * @brief  Setter for month
     *
     * Set the value of month
     *
     *
     *
     * @param  xMonth, value to become month
     * @return int
     */
    void SetMonth( const int &xMonth );

    /**
     * @brief  Getter for year
     *
     * returns the value of year
     *
     *
     *
     * @param  NIL
     * @return void
     */
    int  GettingYear()const;

    /**
     * @brief  Setter for year
     *
     * Set the value of year
     *
     *
     *
     * @param  xYear, value to become year
     * @return void
     */
    void SetYear( const int &xYear );

private:
    int day;
    int month;
    int year;
};

istream & operator >>( istream & input, Date & D );
ostream & operator <<( ostream & os, const Date & D );


#endif // DATE_H_INCLUDED

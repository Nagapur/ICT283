#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <string>

using namespace std;

class Time
{
    friend ostream& operator << (ostream&,const Time&);
    friend istream& operator >> (istream&,Time&);

    public:
        /** \brief Constructor for Time
         *
         * \return void
         *
         */
        Time();

        /** \brief Specific constructor for Time with values
         *
         * \param hr hour
         * \param min minutes
         * \return void
         *
         */
        Time(int hr, int mins);
        ~Time();

    /** \brief setter for Hr
     *
     * \param Hr hour
     * \return void
     *
     */
    void setHr(int hr);

    /** \brief setter for Mins
     *
     * \param Mins minute
     * \return
     *
     */
    void setMins(int mins);

    /** \brief setter for Time
     *
     * \param hr hour
     * \param mins minute
     * \return void
     *
     */
    void setTime(int hr, int mins);

    /** \brief getter for Hr
     *
     * \return int
     *
     */
    int getHr() const;

    /** \brief getter for Mins
     *
     * \return void
     *
     */
    int getMins() const;

    /** \brief Print all elements
     *
     * \return void
     *
     */

    string getFTime() const;

    void print() const;

    private:
        int hour;
        int minutes;
};

#endif // TIME_H

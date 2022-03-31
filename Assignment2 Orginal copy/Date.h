#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date
{
    friend ostream& operator << (ostream&, const Date&);
    friend istream& operator >> (istream&,Date&);

    public:
        /** \brief constructor for Date
         *
         *
         *
         * \return void
         *
         */
        Date();

        /** \brief Specific constructor for Date with values
         *
         * \param d date
         * \param m month
         * \param y year
         * \return void
         *
         */
        Date(int d, int m, int y);
        ~Date();

        /** \brief Setters for Day
         *
         * \param d day
         * \return void
         *
         */
        void setDay(int d);

        /** \brief Setter for Month
         *
         * \param m month
         * \return void
         *
         */
        void setMonth (int m);

        /** \brief Setter for Year
         *
         * \param y year
         * \return void
         *
         */
        void setYear (int y);

        /** \brief Setter for Date
         *
         * \param d date
         * \param m month
         * \param y year
         * \return void
         *
         */
        void setDate (int d, int m, int y);

        /** \brief Getter for Day
         *
         * \return int
         *
         */
        int getDay () const;

        /** \brief Getter for Month
         *
         * \return int
         *
         */
        int getMonth () const;

        /** \brief Getter for Year
         *
         * \return int
         *
         */
        int getYear () const;

        /** \brief Print all elements
         *
         * \return void
         *
         */
        void print() const;

    private:
        int day;
        int month;
        int year;
};

#endif // DATE_H

#ifndef VECTOR2_H
#define VECTOR2_H
#include <iostream>
#include <string>
//string what ^^
using namespace std;

template <class elemType>
class Vector
{
    public:

        /** \brief constructor for Vector
         *
         *
         *
         * \return void
         *
         */
        Vector();

        /** \brief Specific constructor for Vector
         *
         * \return void
         *
         */
        ~Vector();

        /** \brief Vector insertation and print
         *
         * \param push_back
         * \return void
         *
         */
        void push_back (const elemType& i);

        /** \brief Vector insertation and print
         *
         * \param print
         * \return void
         *
         */
        void print() const;

        /** \brief Vector insertation and print
         *
         * \param pop_back
         * \return void
         *
         */
        void pop_back();

        /** \brief Vector size
         *
         * \param size
         * \return void
         *
         */
        int size();
        elemType& at(int i);

       /** \brief array validation
         *
         * \param isEmpty
         * \return bool
         *
         */
        bool isEmpty() const;

        /** \brief array validation
         *
         * \param isFull
         * \return bool
         *
         */
        bool isFull() const;

    private:
        elemType list[60000];
        int length;
};

///Implementation
template <class elemType>
/** \brief Implementaion of vector
 *
 * \param pop_back
 * \return void
 *
 */
void Vector<elemType>::pop_back()
{
    length--;
}

template <class elemType>
elemType& Vector<elemType>::at(int i)
{
    if((i>=0) && (i<length))
        return list[i];
}

template <class elemType>
/** \brief array validation
 *
 * \param size
 * \return int
 *
 */
int Vector<elemType>::size()
{
    return length;
}

template <class elemType>
/** \brief array validation
 *
 * \param isEmpty
 * \return bool
 *
 */
bool Vector<elemType>::isEmpty() const
{
    return(length == 0);
}

template <class elemType>
/** \brief array validation
 *
 * \param isFull
 * \return bool
 *
 */
bool Vector<elemType>::isFull() const
{
    return(length == 60000);
}

template <class elemType>
/** \brief print vecter's element
 *
 * \param print
 * \return void
 *
 */
void Vector<elemType>::print() const
{

    for(int i = 0; i < length; i++)
    {
        cout << list[i] << " " << endl;
    }
}

template <class elemType>
Vector<elemType>::Vector()
{
    length = 0;
}

template <class elemType>
Vector<elemType>::~Vector()
{

}

template <class elemType>
/** \brief Vector push_back
 *
 * \param push_back
 * \return void
 *
 */
void Vector<elemType>::push_back(const elemType& i)
{
    if(length == 60000)
        cout << "Cannot insert" << endl;
    else
    {
        list[length] = i;
        length++;
    }
}

#endif // VECTOR2_H

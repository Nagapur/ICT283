#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <iostream>

/**
 * @class Vector
 * @brief  Manages the dynamic array
 *
 * Vector template class that will store the data from the input CSV
 * has methods to retrieve data at specific index, newly added data will always be saved at the next index after the last element
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

///Initial size of the array
const int INITIAL_ALLOCATION =5;

template <class T>
class Vector
{
private:
    /// m_array is the integer pointer
    /// which stores the address of our vector
    T* m_array;

    /// m_allocation is the total storage
    /// m_allocation of the vector
    int m_allocation;

    /// m_size is the number of elements
    /// m_size present in the vector
    int m_size;

public:

    /**
     * @brief  Default constructor
     *
     * This function will be automatically called to initialize an array of INITIAL_ALLOCATION
     *
     */
    Vector();

    /**
    * @brief  Destructor
    *
    * This function will release memory before the class instance is destroyed. This must be done to avoid memory leak
    *
    */
    ~Vector();

    /**
      * @brief  Add element to the next available index of the array
      *
      * Add element to the array, will automatically create a new array with double the original allocation
      * copy every element from old array to the new array which has a larger allocation
      *
      *
      * @param  T &data , object to be added
      * @return void
      */
    void Add(const T &data);

    /**
    * @brief  Add element to a specific index
    *
    * Add element to the array, if index provided is same as m_allocation, will use Add()
    * else will proceed to add element to requested index
    *
    *
    * @param  T &data , int index, object to be added and index to be added at
    * @return void
    */
    void AddElement(const T &data, int index);

    /**
     * @brief  Getter for vector
     *
     * returns the value at the index position
     *
     *
     *
     * @param  int index, position of the data that is to be returned
     * @return m_array[index]
     */
    T At(int index);

    /**
    * @brief  To delete last element
    *
    * Delete the last element of the array
    *
    *
    *
    * @param  NIL
    * @return NIL
    */
    void RemoveLast();

    /**
      * @brief  Getter for the array
      *
      * return the number of element present in the array
      *
      *
      *
      * @param  NIL
      * @return int
      */
    int GetSize()const;

    /**
      * @brief  Getter for the array
      *
      * return the allocation assigned for this array
      *
      *
      *
      * @param  NIL
      * @return int
      */
    int GetAllocation()const;

    /**
    * @brief  Output for the array
    *
    * display each element of the array
    *
    *
    *
    * @param  NIL
    * @return m_array
    */
    void print();

    /**
    * @brief  clear the array
    *
    * set m_size to 0
    *
    *
    *
    * @param  NIL
    * @return m_array
    */
    void clear();

};

/// Default constructor to initialize
/// an initial allocation of 5 element and
/// allocating storage using dynamic allocation
template <class T>
Vector<T>::Vector()
{

    m_array = new T[INITIAL_ALLOCATION];
    m_size = 0;

    if(m_array !=nullptr)  /// check if enough memory to allocate
    {
        m_allocation = INITIAL_ALLOCATION;
    }
    else
    {
        m_allocation = 0; /// set to 0 as not enough memory
    }
}

///Destructor
template <class T>
Vector<T>::~Vector()
{
    if(m_array != nullptr)
    {

        delete[] m_array; ///delete array and set to nullptr
        m_array =nullptr;

    }

}

/// Function to add an element to the last
template <class T>
void Vector<T>:: Add(const T & data)
{

    /// if the number of elements is more than
    /// m_allocation/2 , we need to expand the array
    /// accommodate more elements
    if (m_size > m_allocation/2)
    {
        T* temp = new T[2 * m_allocation];     ///double m_allocation

        /// copying old m_array elements to new m_array
        for (int i = 0; i < m_allocation; i++)
        {
            temp[i] = m_array[i];
        }

        /// deleting previous m_array
        delete[] m_array;
        m_allocation *= 2;
        m_array = temp;
    }

    /// Inserting data
    m_array[m_size] = data;
    m_size++;
}

/// function to add element at any index
template <class T>
void Vector<T>::AddElement(const T &data, int index)
{
    /// if index is equal to m_allocation then this
    /// function is same as push defined above
    if (index == m_allocation)
        Add(data);
    else
        m_array[index] = data;
}

/// function to extract element at any index
template <class T>
T Vector<T>::At(int index)
{

    /// if index is within the range
    if (index < m_size)
        return m_array[index];
}

/// function to delete last element
template <class T>
void Vector<T>::RemoveLast()
{
    m_size--;
}

/// function to get size of the vector
template <class T>
int Vector<T>:: GetSize()const
{
    return m_size;
}

/// function to get allocation of the vector
template <class T>
int Vector<T>::GetAllocation()const
{
    return m_allocation;
}

/// function to print m_array elements
template <class T>
void Vector<T>::print()
{
    for (int i = 0; i < m_size; i++)
    {
        cout << m_array[i] << " ";
    }
    cout << endl;
}

///set array back to size 0
template <class T>
void Vector<T>::clear()
{
    m_size = 0;

}


#endif /// VECTOR_H_INCLUDED

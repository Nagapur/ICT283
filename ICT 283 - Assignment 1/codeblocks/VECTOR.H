#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <iostream>

using namespace std;

const int INITIAL_ALLOCATION =5;

template <class T>
class vectorClass
{
    private:
    // m_array is the integer pointer
    // which stores the address of our vector
    T* m_array;

    // m_allocation is the total storage
    // m_allocation of the vector
    int m_allocation;

    // m_size is the number of elements
    // m_size present in the vector
    int m_size;

public:

    vectorClass();
    ~vectorClass();
    void Add(const T &data);
    void AddElement(const T &data, int index);
    T At(int index);
    void RemoveLast();
    int GetSize()const;
    int GetAllocation()const;
    void print();

};

    // Default constructor to initialise
    // an initial allocation of 5 element and
    // allocating storage using dynamic allocation
    template <class T>
    vectorClass<T>::vectorClass()
    {

        m_array = new T[INITIAL_ALLOCATION];
        m_size = 0;

        if(m_array !=nullptr)  // check if enough memory to allocate
        {
            m_allocation = INITIAL_ALLOCATION;
        }
        else
        {
            m_allocation = 0; // set to 0 as not enough memory
        }
    }

        template <class T>
    vectorClass<T>::~vectorClass()
    {
        if(m_array != nullptr)
        {

        delete[] m_array;
        m_array =nullptr;

        }

    }

    // Function to add an element at the last
    template <class T>
    void vectorClass<T>:: Add(const T & data)
    {

        // if the number of elements is more than
        // m_allocation/2 , that means we don't have space to
        // accommodate more elements. We need to double the
        // m_allocation
        if (m_size > m_allocation/2)
        {
            T* temp = new T[2 * m_allocation];

            // copying old m_array elements to new m_array
            for (int i = 0; i < m_allocation; i++)
            {
                temp[i] = m_array[i];
            }

            // deleting previous m_array
            delete[] m_array;
            m_allocation *= 2;
            m_array = temp;
        }

        // Inserting data
        m_array[m_size] = data;
        m_size++;
    }

    // function to add element at any index
    template <class T>
    void vectorClass<T>::AddElement(const T &data, int index)
    {
        // if index is equal to m_allocation then this
        // function is same as push defined above
        if (index == m_allocation)
            Add(data);
        else
            m_array[index] = data;
    }

    // function to extract element at any index
    template <class T>
    T vectorClass<T>::At(int index)
    {

        // if index is within the range
        if (index < m_size)
            return m_array[index];
    }

    // function to delete last element
    template <class T>
    void vectorClass<T>::RemoveLast()
    {
        m_size--;
    }

    // function to get size of the vector
    template <class T>
    int vectorClass<T>:: GetSize()const
    {
        return m_size;
    }

    // function to get m_allocation of the vector
    template <class T>
    int vectorClass<T>::GetAllocation()const
    {
        return m_allocation;
    }

    // function to print m_array elements
    template <class T>
    void vectorClass<T>::print()
    {
        for (int i = 0; i < m_size; i++)
        {
            cout << m_array[i] << " ";
        }
        cout << endl;
    }


#endif // VECTOR_H_INCLUDED

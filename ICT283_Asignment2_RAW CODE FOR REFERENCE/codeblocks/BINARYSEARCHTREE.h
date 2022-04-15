#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include <iostream>
#include "DATE.H"
#include "WINDLOGTYPE.H"
#include "VECTOR.H"
#include <map>

/**
 * @class BinarySearchTree
 * @brief  Data structure of a Binary Search Tree
 *
 * Binary Search tree template class that will store the data from the input CSV
 * has methods to retrieve data at specific index, newly added data will always be saved at the next index after the last element
 * Variables are private
 *
 *
 *
 * @author Lim Seng Wei
 * @version 01
 * @date 29/03/2022
 *
 */

 using namespace std;

 typedef map<int,int> typeMap;
 typedef multimap<int, WindLogType> windMap;
 typedef multimap<pair<int,int>, WindLogType> multiWindMap;
 typedef multimap<string, WindLogType> multiStringMap;

template <class T>
struct Node
{

        string key;
        T data; // data
        Node<T> *lLink;
        Node<T> *rLink;

};




 template <class T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<T> & otherTree);
    bool IsEmpty() const;
    float GetMax();
    string GetMaxKey();
    float maxValue(Node<T> * node);
    string maxValueKey(Node<T> * node);
    void Insert (const T &item);
    void InsertTimeKey (const T &item , string fullTime);
    void ItrInsert(const T &insertItem);
    void FindNode (const T &item);
    void FindMapNode (int,int,const WindLogType &item);
    void InOrderTraversal() const;
    void InOrderTraversal(void(*funcPtr)(T&)) const; // function pointer

    //int InOrderTraversalInt(int(*funcPtr)(T&)) const; // function pointer

    void PreOrderTraversal() const;
    void PostOrderTraversal() const;
    void DestroyTree();
    const BinarySearchTree<T> & operator= (const BinarySearchTree<T> &);
    friend inline ostream & operator <<( ostream & os, multiWindMap &m );


    private:
        void CopyTree(Node<T>* &copiedTreeRoot, Node<T>* otherTreeRoot);
        void destroy(Node<T> *&p);
        void InOrder(Node<T> *p) const;
        void InOrder(Node<T> *p , void (*funcPtr)(T&)) const; // function pointer

        //int InOrderInt(Node<T> *p) const;
       // int InOrderInt(Node<T> *p , int (*funcPtr)(T&)) const; // function pointer

        void PreOrder(Node<T> *p) const;
        void PostOrder(Node<T> *p) const;
        void InsertFromNode (Node<T> * newNode, Node<T> * root);
        bool FindNode(Node<T> * root , const T & item);
        bool FindMapNode(Node<T> * root , const WindLogType & item);
        Node<T> * m_root;

};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
        m_root = NULL;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
        destroy(m_root);
}

template <class T>
bool BinarySearchTree<T>::IsEmpty() const
{
        return (m_root == nullptr);
}

template <class T>
float BinarySearchTree<T>::GetMax()
{
    return maxValue(m_root);
}

template <class T>
string BinarySearchTree<T>::GetMaxKey()
{
    return maxValueKey(m_root);
}


template <class T>
float BinarySearchTree<T>::maxValue(Node<T> * node)
{
    /* loop down to find the rightmost leaf */
    Node<T> * current = node;
    while (current->rLink != NULL)
        current = current->rLink;

    return (current->data);
}

template <class T>
string BinarySearchTree<T>::maxValueKey(Node<T> * node)
{
    /* loop down to find the rightmost leaf */
    Node<T> * current = node;
    while (current->rLink != NULL)
        current = current->rLink;

    return (current->key);
}

/*template <class T>
bool BinarySearchTree<T>:: operator < (const BinarySearchTree<T> &val)
{
      return
}*/

template <class T>
void BinarySearchTree<T>::InsertFromNode(Node<T> * newNode, Node<T> * root )
{


           if(newNode->data < root->data)
           {
               if(root->lLink == nullptr)
               {
                   root->lLink = newNode;

               }

               else
               {
                    InsertFromNode (newNode,root->lLink);
               }

           }

            else
            {
                if(root->rLink ==nullptr)

                {
                    root->rLink = newNode;
                }

                else
                {
                        InsertFromNode (newNode, root->rLink);
                }

            }

       }


/*template <class T>
void BinarySearchTree<T>::Insert(const T &item)
{

         map <T, T> testMap;



    Node <T> *newNode = new Node<T>;
    newNode->data = item;
        newNode->newMap = testMap;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;


    if (m_root == nullptr)
    {
        m_root = newNode;

    }

    else
    {
        InsertFromNode(newNode , m_root);
    }




}*/

template <class T>
void BinarySearchTree<T>::Insert(const T &item)
{



    Node <T> *newNode = new Node<T>;
    newNode->data = item;


    newNode->lLink = nullptr;
    newNode->rLink = nullptr;


    if (m_root == nullptr)
    {
        m_root = newNode;

    }

    else
    {
        InsertFromNode(newNode , m_root);
    }




}

template <class T>  // BST WITH TIME AS KEY
void BinarySearchTree<T>::InsertTimeKey(const T &item , string fullTime)
{

    Node <T> *newNode = new Node<T>;
    newNode->data = item;
    newNode->key = fullTime;

    newNode->lLink = nullptr;
    newNode->rLink = nullptr;


    if (m_root == nullptr)
    {
        m_root = newNode;

    }

    else
    {
        InsertFromNode(newNode , m_root);
    }



}

template <class T>
void BinarySearchTree<T>::ItrInsert(const T &insertItem)
{
        Node<T> *current = NULL;
        Node<T> *trailCurrent = NULL;
        Node<T> *newNode;

        newNode = new Node<T>;
        newNode->data = insertItem;
        newNode->lLink = NULL;
        newNode->rLink = NULL;

        if (m_root == NULL)
        {
                m_root = newNode;
        }
        else
        {
                current = m_root;

                while (current != NULL)
                {
                        trailCurrent = current;

                        if (insertItem == current->data)
                        {
                                cout << "Duplicates are not allowed!" << endl;
                                return;
                        }
                        else
                        {
                                if (insertItem < current->data)
                                {
                                        current = current->lLink;
                                }
                                else
                                {
                                        current = current->rLink;
                                }
                        }
                }

                if (insertItem < trailCurrent->data)
                {
                        trailCurrent->lLink = newNode;
                }
                else
                {
                        trailCurrent->rLink = newNode;
                }
        }
}


template <class T>   //WORKING FINDNODE
bool BinarySearchTree<T>::FindNode(Node<T> * root , const T & item)
{
        bool found;

        if (root == nullptr)
        {
            found = false;

            return found;
        }

        else if(root->data == item)
        {
            found = true;
            cout<<"FOUND!"<<endl;
            return found;
        }

         else if(item < root -> data)
        {
             FindNode(root->lLink,item);
        }

        else
        {
            FindNode(root->rLink ,item);
        }
}


//DRAFT FOR MAP KEY
/*template <class T>
bool BinarySearchTree<T>::FindMapNode(Node<T> * root , const WindLogType & item)
{
        bool found;

        if (root == nullptr)
        {
            found = false;

            return found;
        }

        else if(root->data == item)
        {
            found = true;
            cout<<"FOUND!"<<endl;
            return found;
        }

         else if(item < root -> data)
        {
             FindMapNode(root->lLink,item);
        }

        else
        {
            FindMapNode(root->rLink ,item);
        }
}*/


template <class T>
void BinarySearchTree<T>::FindNode(const T &item)
{
    FindNode(m_root, item);
}

/*template <class T>
void BinarySearchTree<T>::FindMapNode(int,int,const WindLogType &item)
{
    FindMapNode(m_root, item);
}*/

template <class T>
void BinarySearchTree<T>::InOrderTraversal() const
{
        InOrder(m_root);
}

template <class T>
void BinarySearchTree<T>::InOrderTraversal(void(*funcPtr)(T&)) const
{
        InOrder(m_root, *funcPtr);
}

/*template <class T>
int BinarySearchTree<T>::InOrderTraversalInt(int(*funcPtr)(T&)) const
{
        InOrderInt(m_root, *funcPtr);

}*/


template <class T>
void BinarySearchTree<T>::PreOrderTraversal() const
{
        PreOrder(m_root);
}

template <class T>
void BinarySearchTree<T>::PostOrderTraversal() const
{
        PostOrder(m_root);
}

template <class T>
void BinarySearchTree<T>::DestroyTree()
{
    destroy(m_root);
}


template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> & otherTree)
{
         if(otherTree.m_root == nullptr)
        m_root = nullptr;
    else
        CopyTree(m_root, otherTree.m_root);

}

template <class T>
void BinarySearchTree<T>::CopyTree(Node<T>* &copiedTreeRoot, Node<T>* otherTreeRoot)
{
      if(otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new Node<T>;
        copiedTreeRoot->data = otherTreeRoot->data;
        CopyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        CopyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
}

template <class T>
void BinarySearchTree<T>::destroy(Node<T>* &p)
{
    if (p != nullptr)
    {
        destroy (p->lLink);
        destroy (p->rLink);
        delete p;
        p = nullptr;
    }
}

/*template <class T>         ////WORKING METHOD, USE THIS IF SCREW UP
void BinarySearchTree<T>::InOrder(Node<T> *p) const
{
    if (p != NULL)
        {

            InOrder(p-> lLink);
            cout << p->data << " ";
            InOrder(p-> rLink);
        }
}*/

template <class T>
void BinarySearchTree<T>::InOrder(Node<T> *p) const
{
    if (p != NULL)
        {

            InOrder(p-> lLink);
            cout << p->data << " ";
            InOrder(p-> rLink);
        }
}

/*template <class T>         ////FOR SOLAR RAD FUNCTION
int BinarySearchTree<T>::InOrderInt(Node<T> *p) const
{
    if (p != NULL)
        {

            InOrderInt(p-> lLink);
            p->data;
            InOrderInt(p-> rLink);
        }
}*/

/*template <class T>    ////FOR SOLAR RAD FUNCTION
int BinarySearchTree<T>::InOrderInt(Node<T> *p , int (*funcPtr)(T&)) const
{
    if (p != NULL)
        {

            InOrderInt(p-> lLink, *funcPtr);
            (*funcPtr)(p->data);
            InOrderInt(p-> rLink, *funcPtr);
        }
}*/


template <class T>
void BinarySearchTree<T>::InOrder(Node<T> *p , void (*funcPtr)(T&)) const
{
    if (p != NULL)
        {

            InOrder(p-> lLink, *funcPtr);
            (*funcPtr)(p->data);
            InOrder(p-> rLink, *funcPtr);
        }
}

template <class T>
void BinarySearchTree<T>::PreOrder(Node<T> *p) const
{
    if (p != NULL)
        {

            cout << p->data << " ";
            PreOrder(p-> lLink);
            PreOrder(p-> rLink);
        }
}

template <class T>
void BinarySearchTree<T>::PostOrder(Node<T> *p) const
{
    if (p != NULL)
        {

            PreOrder(p-> lLink);
            PreOrder(p-> rLink);
            cout << p->data << " ";
        }
}

//template <typename Y,typename Z>
/*inline ostream & operator <<( ostream & os,  const multiWindMap &m )
{
   for (multiWindMap::const_iterator it = m.begin(); it != m.end(); ++it)
    {

        //os<<"HELLO IM HERE"<<endl;
        os <<"Map:" <<it->second.GetYear()<<endl;

    }

    return os;
}*/
#endif // BINARYSEARCHTREE_H_INCLUDED

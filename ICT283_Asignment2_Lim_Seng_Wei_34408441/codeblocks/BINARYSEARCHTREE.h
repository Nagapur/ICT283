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

template <class T>
struct Node
{

        T data; // key
        map <T, T> newMap;
        Node<T> *lLink;
        Node<T> *rLink;

};

//typedef map<int, map<int, Vector<WindLogType>>> windLogMap;

 template <class T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<T> & otherTree);
    bool IsEmpty() const;
    void Insert (const T &item);
    void FindNode (const T &item);
    void InOrderTraversal() const;
    void InOrderTraversal(void(*funcPtr)(T&)) const; // function pointer
    void PreOrderTraversal() const;
    void PostOrderTraversal() const;
    void DestroyTree();
    const BinarySearchTree<T> & operator= (const BinarySearchTree<T> &);



    private:
        void CopyTree(Node<T>* &copiedTreeRoot, Node<T>* otherTreeRoot);
        void destroy(Node<T> *&p);
        void InOrder(Node<T> *p) const;
        void InOrder(Node<T> *p , void (*funcPtr)(T&)) const; // function pointer
        void PreOrder(Node<T> *p) const;
        void PostOrder(Node<T> *p) const;
        void InsertFromNode (Node<T> * newNode, Node<T> * root);
        bool FindNode(Node<T> * root , const T & item);
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

/*template <class T>
bool BinarySearchTree<T>:: operator < (const BinarySearchTree<T> &val)
{
      return
}*/

template <class T>
void BinarySearchTree<T>::InsertFromNode(Node<T> * newNode, Node<T> * root )
{

        /*    map <T,T> testMap;

          typename map <T,T> ::iterator itr;
          newNode->newMap = testMap;
          testMap.insert(pair<T,T>(newNode->data,root->data));*/

           if(newNode->data < root->data)
           {
               if(root->lLink == nullptr)
               {
                   root->lLink = newNode;

               }

               else
               {
                   /*root->lLink =*/ InsertFromNode (newNode,root->lLink);
               }

           }

            else //(newNode->data > root->data)
            {
                if(root->rLink ==nullptr)

                {
                    root->rLink = newNode;
                }

                else
                {
                    /*root ->rLink =*/ InsertFromNode (newNode, root->rLink);
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

template <class T>
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

template <class T>
void BinarySearchTree<T>::FindNode(const T &item)
{
    FindNode(m_root, item);
}

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
#endif // BINARYSEARCHTREE_H_INCLUDED

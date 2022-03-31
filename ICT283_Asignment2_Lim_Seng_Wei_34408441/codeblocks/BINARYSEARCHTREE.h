#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include <iostream>
#include "DATE.H"

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

        T data;
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
    void Insert (const T &item);
    //Node<T> * Search (Node<T> * root , const T & item);
    void InOrderTraversal() const;
    void PreOrderTraversal() const;
    void PostOrderTraversal() const;
    void DestroyTree();
    const BinarySearchTree<T> & operator= (const BinarySearchTree<T> &);



    private:
        void CopyTree(Node<T>* &copiedTreeRoot, Node<T>* otherTreeRoot);
        void destroy(Node<T> *&p);
        void InOrder(Node<T> *p) const;
        void PreOrder(Node<T> *p) const;
        void PostOrder(Node<T> *p) const;
        void Insert (Node<T> * newNode, Node<T> * root);
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
bool BinarySearchTree<T>:: operator < (const BinarySearchTree<T> &val)
{
      return
}

template <class T>
void BinarySearchTree<T>::Insert(Node<T> * newNode, Node<T> * root )
{

           if(newNode->data < root->data)
           {
                /*root->lLink =*/ Insert (newNode,root->lLink);
           }

            else if (newNode->data > root->data)
            {
                /*root ->rLink =*/ Insert (newNode, root->rLink);
            }

            else
            {
                cout<<" Duplicate value!"<<endl;

            }



       }


template <class T>
void BinarySearchTree<T>::Insert(const T &item)
{

    Node <T> *newNode = new Node<T>;
    newNode->data = item;

    if (m_root == nullptr)
    {
        m_root = newNode;
        newNode->lLink = nullptr;
        newNode->rLink = nullptr;
    }

    else
    {
        Insert(newNode , m_root);
    }




}

/*template <class T>
Node <T> * BinarySearchTree<T>::Search(Node<T> * root , const T & item)
{
        if (root == NULL)
        {
            return nullptr;
        }

        else if(root->data == item)
        {
            return root;
        }

         else if(item < root -> data)
        {
            return Search(root->lLink,item);
        }

        else
        {
            return Search(root->rLink , item);
        }
}*/

template <class T>
void BinarySearchTree<T>::InOrderTraversal() const
{
        InOrder(m_root);
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
void BinarySearchTree<T>::PreOrder(Node<T> *p) const
{
    if (p != NULL)
        {

            cout << p->data << " ";
            PreOrder(p-> lLink);
            Preorder(p-> rLink);
        }
}

template <class T>
void BinarySearchTree<T>::PostOrder(Node<T> *p) const
{
    if (p != NULL)
        {

            PreOrder(p-> lLink);
            Preorder(p-> rLink);
            cout << p->data << " ";
        }
}
#endif // BINARYSEARCHTREE_H_INCLUDED

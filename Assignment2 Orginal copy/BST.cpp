#include "BST.h"
#include <iostream>
#include <map>

using namespace std;

BST::BST()
{
    root = NULL;
}

multimap <string, float> BST::search(const float searchItem) const
{
    nodeType *current;
    bool found = false;
    multimap <string, float> data;

    if (root == NULL)
        cout << "Cannot search an empty tree."<<endl;
    else
    {
        current = root;

        while (current != NULL && !found)
        {
            if (searchItem == current -> info)
            {
                found = true;
                data = current-> mapFile;
            }

            else if (searchItem < current -> info)
                current = current -> lLink;
            else
                current = current -> rLink;
        }
    }


        return data;


}
void BST::insert(const float insertItem, string time)
{
    multimap <string, float> myMap;
    myMap.insert(pair <string, float>(time, insertItem));
    multimap<string,float>::iterator it;

    nodeType *current;
    nodeType *trailCurrent = NULL;
    nodeType *newNode;

    newNode = new nodeType;
    newNode -> info = insertItem;
    newNode -> mapFile = myMap;
    newNode -> lLink = NULL;
    newNode -> rLink = NULL;

    if (root == NULL)
        root = newNode;
    else
    {
        current = root;
        while (current != NULL)
        {
            trailCurrent = current;
            if (insertItem == current-> info)
            {
                current->mapFile.insert(pair <string, float>(time, insertItem));
               // cout <<"Duplicates not allowed. Value:"<<insertItem<< " and " << time<< endl;
                return;
            }
            else
                if (insertItem < current->info)
                current = current ->lLink;
                else
                current = current -> rLink;
            }//end while


            if (insertItem < trailCurrent -> info)
                trailCurrent -> lLink = newNode;
            else
                trailCurrent -> rLink = newNode;
        }
    }//end insert
    bool BST::isEmpty() const
    {
        return (root == NULL);
    }
    void BST::preorderTraversal() const
    {
        preorder(root);
    }
    void BST::inorderTraversal() const
    {
        inorder(root);
    }
    void BST::postorderTraversal() const
    {
        postorder(root);

    }
    float BST::getMax() const
    {
        return maxValue(root);
    }
    void BST::preorder(nodeType* p) const
    {
        if (p != NULL)
        {
            cout << p-> info << " ";
            preorder(p->lLink);
            preorder(p->rLink);
        }
    }
    void BST::postorder (nodeType *p) const
    {
        if (p != NULL)
        {

            postorder(p-> lLink);
            postorder(p-> rLink);
            cout << p->info << " ";
        }
    }
    void BST::inorder (nodeType *p) const
    {
        if (p != NULL)
        {

            inorder(p-> lLink);
            cout << p->info << " ";
            inorder(p-> rLink);
        }
    }
    float BST::maxValue(nodeType *node) const
    {
        if (node == nullptr)
            throw "BT is empty";

        return maxValueNonNull(node, node->info);
    }
    float BST::maxValueNonNull(nodeType* node, float currentMax) const
    {
        if (node == NULL)
        {    return currentMax;
        }

        currentMax = currentMax > node->info ? currentMax : node->info;

        float leftMax  = maxValueNonNull(node->lLink,  currentMax);
        float rightMax = maxValueNonNull(node->rLink, currentMax);

        return leftMax > rightMax ? leftMax : rightMax;
    }
void BST::destroy(nodeType* p)
{
    if (p != NULL)
    {
        destroy(p -> lLink);
        destroy(p -> rLink);
        delete p;
        p = NULL;
    }
}

BST::~BST()
{
    destroy(root);
}

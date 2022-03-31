#ifndef BST_H
#define BST_H
#include <iostream>
#include <map>

using namespace std;

struct nodeType
{
    float info;
    multimap <string, float> mapFile;
    nodeType *lLink;
    nodeType *rLink;
};

//definition of the class
class BST
{
    public:
        BST();
        ~BST();

        multimap <string, float> search(const float searchItem) const;
        void insert(const float insertItem, string time) ;
        //void deleteNode (const int deleteItem);

        bool isEmpty() const;
        float getMax() const;
        void inorderTraversal() const;
        void preorderTraversal() const;
        void postorderTraversal() const;

        void destroy(nodeType* p);

    private:
        void inorder(nodeType *p) const;
        void preorder(nodeType *p) const;
        void postorder(nodeType *p) const;
        float maxValue(nodeType *node) const;
        float maxValueNonNull(nodeType *node, float currentMax) const;
        nodeType *root;
};

#endif // BST_H

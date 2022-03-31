#include "BINARYSEARCHTREE.H"
#include "DATE.H"
#include <iostream>

using namespace std;

int main()
{

    BinarySearchTree<int> intBst;
    BinarySearchTree<Date> dateBst;
    Date d;
    d.SetDay(1);
    d.SetMonth(12);
    d.SetYear(2022);

    dateBst.Insert(d);
    dateBst.InOrderTraversal();

    intBst.Insert(2);
    intBst.Insert(2);
    intBst.Insert(2);

    intBst.InOrderTraversal();

    //int intArray[] = {23, 12, 3, 7, 15, 13, 19, 31, 29, 25, 88, 53};

   // for (int n : intArray) // range-based for loop
              //  intBst.Insert(n);
            //    intBst.InOrderTraversal();


}

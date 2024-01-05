#include <iostream>
#include "BinaryTree.h"
using namespace std;

template <typename TreeType>
void testBinaryTree(TreeType& t, int NUMS, const int GAP)
{
    int i;
    cout << "Checking... (no more output means success)" << endl;
    for (i = GAP; i != 0; i = (i + GAP) % NUMS)
        t.insert(i);

    for (i = 1; i < NUMS; i += 2)
        t.remove(i);

    if (NUMS < 40)
        t.printTree();
    if (t.findMin() != 2 || t.findMax() != NUMS - 2)
        cout << "FindMin or FindMax error!" << endl;

    for (i = 2; i < NUMS; i += 2)
        if (!t.contains(i))
            cout << "Find error1!" << endl;

    for (i = 1; i < NUMS; i += 2)
    {
        if (t.contains(i))
            cout << "Find error2!" << endl;
    }
    TreeType t2= t;

    for (i = 2; i < NUMS; i += 2)
        if (!t2.contains(i))
            cout << "Find error1!" << endl;

    for (i = 1; i < NUMS; i += 2)
    {
        if (t2.contains(i))
            cout << "Find error2!" << endl;
    }

    cout << "Finished testing" << endl;
}

// Test program
int main()
{

    BinarySearchTree<int> bst;
    testBinaryTree(bst, 400000, 3711);

    //SplayTree<int> st;
    //testBinaryTree(st, 30000, 37);

    AvlTree<int> avlt;
    testBinaryTree(avlt, 2000000, 37);

    const int NEG_INF = -9999;
    RedBlackTree<int> t{ NEG_INF };
    int NUMS = 400000;
    const int GAP = 37;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for (i = GAP; i != 0; i = (i + GAP) % NUMS)
        t.insert(i);

    if (NUMS < 40)
        t.printTree();
    if (t.findMin() != 1 || t.findMax() != NUMS - 1)
        cout << "FindMin or FindMax error!" << endl;

    for (i = 1; i < NUMS; ++i)
        if (!t.contains(i))
            cout << "Find error1!" << endl;
    if (t.contains(0))
        cout << "Oops!" << endl;


    RedBlackTree<int> t2{ NEG_INF };
    t2 = t;

    for (i = 1; i < NUMS; ++i)
        if (!t2.contains(i))
            cout << "Find error1!" << endl;
    if (t2.contains(0))
        cout << "Oops!" << endl;

    cout << "Test complete..." << endl;

    return 0;
}

#include <iostream>
#include "BinaryTree.h"
int main(void)
{
    BTNode * bt1 = MakeBTreeNode();
    BTNode * bt2 = MakeBTreeNode();
    BTNode * bt3 = MakeBTreeNode();
    BTNode * bt4 = MakeBTreeNode();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);

    InorderTraverse(bt1);
    return 0;
}
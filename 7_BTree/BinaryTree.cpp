#include "BinaryTree.h"
#include <iostream>

BTNode*MakeBTreeNode(void)
{
    BTNode * newNode = (BTNode*)malloc(sizeof(BTNode));
    
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

BTData GetData(BTNode*bt)
{
    return bt->data;
}

void SetData(BTNode*bt, BTData data)
{
    bt->data = data;
}

BTNode * GetLeftSubTree(BTNode*bt)
{
    return bt->left;
}

BTNode * GetRightSubTree(BTNode*bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTNode* main, BTNode* sub)
{
    if(main->left != NULL)
        free(main->left);
    
    main->left = sub;
}

void MakeRightSubTree(BTNode* main, BTNode* sub)
{
    if(main->right != NULL)
        free(main->right);
    main->right = sub;
}

void InorderTraverse(BTNode*bt, VisitFuncPtr action)
{
    if(bt == NULL)
        return;
    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PreorderTraverse(BTNode*bt, VisitFuncPtr action)
{
    if(bt == NULL)
        return;
    
    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

void PostorderTraverse(BTNode*bt, VisitFuncPtr action)
{
    if(bt == NULL)
        return;
    
    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}

void DeleteTree(BTNode*bt)
{
    if(bt == NULL)
        return;

    DeleteTree(bt->left);
    DeleteTree(bt->right);
    printf("Delete Node Data: %d", bt->data);
    free(bt);
}
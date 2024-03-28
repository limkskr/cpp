/*
#include "Expression.h"
#include "ListBaseStack.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>

BTNode*MakeExpTree(char exp[])        //수식트리 구성
{
    Stack stack;
    StackInit(&stack);
    BTNode * pnode;

    int explen = strlen(exp);
    int i;

    for(i=0; i<explen; i++)
    {
        pnode = MakeBTreeNode();

        if(isdigit(exp[i]))
        {
            SetData(pnode, exp[i]-'0');
        }
        else
        {
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode, SPop(&stack));
            SetData(pnode, exp[i]);
        }
        SPush(&stack, pnode);
    }
    return SPop(&stack);
}

int EvaluateExpTree(BTNode*bt)       //수식트리 계산
{
    int op1, op2;

    if(GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
        return GetData(bt);
    
    op1 = EvaluateExpTree(GetLeftSubTree(bt));
    op2 = EvaluateExpTree(GetRightSubTree(bt));

    switch(GetData(bt))
    {
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
    }
    return 0;
}

void ShowNodeData(int data)
{
    if(0<=data&&data<=9)
        printf("%d", data);
    else
        printf("%c", data);
}

void ShowPrefixTypeExp(BTNode*bt)    //전위 표기법 기반 출력
{
    PreorderTraverse(bt, ShowNodeData);
}
void ShowInfixTypeExp(BTNode*bt)      //중위 표기법 기반 출력
{
    if(bt == NULL)
        return;
    
    if(bt->left != NULL || bt->right != NULL)
        printf("(");
    
    ShowInfixTypeExp(bt->left);
    ShowNodeData(bt->data);
    ShowInfixTypeExp(bt->right);
    
    if(bt->left != NULL || bt->right != NULL)
        printf(")");
}
void ShowPostfixTypeExp(BTNode*bt)    //후위 표기법 기반 출력
{
    PostorderTraverse(bt, ShowNodeData);
}
*/
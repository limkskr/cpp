#include "BinaryTree.h"
#include <iostream>

//트리의 높이를 계산하여 반환
int GetHeight(BTreeNode * bst)
{
    int leftH;
    int rightH;

    if(bst == NULL)
        return 0;

    leftH = GetHeight(GetLeftSubTree(bst));
    rightH = GetHeight(GetRightSubTree(bst));

    if(leftH > rightH)
        return leftH+1;
    else
        return rightH+1;
}
//균형인수 반환
int GetHeightDiff(BTreeNode * bst)
{
    int lsh;
    int rsh;

    if(bst==NULL)
        return 0;

    lsh = GetHeight(GetLeftSubTree(bst));
    rsh = GetHeight(GetRightSubTree(bst));

    return lsh - rsh;
}

BTNode * RotateLL(BTNode*bst)
{
    BTNode*pNode;
    BTNode*cNode;

    //pNode와 cNode가 LL회전을 위해 적절한 위치를 가리키게 만든다
    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    //실제 LL회전
    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    ChangeRightSubTree(cNode, pNode);

    return cNode;
}

BTNode * RotateRR(BTNode*bst)
{
    BTNode*pNode;
    BTNode*cNode;

    //pNode와 cNode가 RR회전을 위해 적절한 위치를 가리키게 만든다
    pNode = bst;
    cNode = GetRightSubTree(pNode);

    //실제 RR회전
    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);

    return cNode;
}

BTNode * RotateLR(BTNode*bst)
{
    BTNode*pNode;
    BTNode*cNode;

    //pNode와 cNode가 RR회전을 위해 적절한 위치를 가리키게 만든다
    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    ChangeLeftSubTree(pNode, RotateRR(cNode));
    return RotateLL(pNode);
}

BTNode * RotateRL(BTNode*bst)
{
    BTNode*pNode;
    BTNode*cNode;

    //pNode와 cNode가 RR회전을 위해 적절한 위치를 가리키게 만든다
    pNode = bst;
    cNode = GetRightSubTree(pNode);

    ChangeRightSubTree(pNode, RotateLL(cNode));
    return RotateRR(pNode);
}

//리벨런싱
BTNode * Rebalance(BTNode**pRoot)
{
    int hDiff = GetHeightDiff(*pRoot);

    //균형인수가 2 이상이면 LL또는 LR 상태
    if(hDiff > 1)
    {
        if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
            *pRoot = RotateLL(*pRoot);
        else
            *pRoot = RotateLR(*pRoot);
    }

    if(hDiff < -1)
    {
        if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
            *pRoot = RotateRR(*pRoot);
        else
            *pRoot = RotateRL(*pRoot);
    }

    return *pRoot;
}
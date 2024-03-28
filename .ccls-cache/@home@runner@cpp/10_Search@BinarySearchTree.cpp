#include "BinarySearchTree.h"
#include "AVLRebalance.h"
#include <iostream>

//BST 생성 및 초기화
void BSTMakeAndInit(BTreeNode ** pRoot)
{
    *pRoot = NULL;
}

//노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst)
{
    return GetData(bst);
}

// BST를 대상으로 데이터 저장(노드 생성과정 포함)
BTNode * BSTInsert(BTreeNode ** pRoot, BSTData data)
{
    if(*pRoot == NULL)
    {
        *pRoot = MakeBTreeNode();
        SetData(*pRoot, data);
    }
    else if(data < GetData(*pRoot))
    {
        BSTInsert(&((*pRoot)->left), data);
        *pRoot = Rebalance(pRoot);
    }
    else if(data > GetData(*pRoot))
    {
        BSTInsert(&((*pRoot)->right), data);
        *pRoot = Rebalance(pRoot);
    }
    else
    {
        return NULL;
    }

    return *pRoot;
}

// BST를 대상으로 데이터 탐색
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
    BTreeNode * cNode = bst;
    BSTData cd;

    while(cNode != NULL)
    {
        cd  = GetData(cNode);

        if(target == cd)
            return cNode;
        else if(target < cd)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    return NULL;    //탐색대상이 저장되어 있지 않음
}

//트리에서 노드를 제거하고 제거된 노드의 주소값을 반환
BTreeNode * BSTRemove(BTreeNode**pRoot, BSTData target)
{
    BTreeNode * pVRoot = MakeBTreeNode();
    BTreeNode * pNode = pVRoot;
    BTreeNode * cNode = *pRoot;
    BTreeNode * dNode;

    ChangeRightSubTree(pVRoot, *pRoot);

    //삭제 대상 노드 탐색
    while(cNode != NULL && GetData(cNode) != target)
    {
        pNode = cNode;
        if(target < GetData(cNode))
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    if(cNode == NULL)        //삭제대상 존재X
        return NULL;

    dNode = cNode;
    
    //첫번째: 삭제대상이 단말 노드인 경우
    if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
    {
        if(GetLeftSubTree(pNode) == dNode)
            RemoveLeftSubTree(pNode);
        else
            RemoveRightSubTree(pNode);
    }
    //두번째: 삭제대상이 1개의 자식노드를 가진 경우
    else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
    {
        BTreeNode * dcNode;    //삭제대상의 자식노드

        if(GetLeftSubTree(dNode) != NULL)
            dcNode = GetLeftSubTree(dNode);
        else
            dcNode = GetRightSubTree(dNode);

        if(GetLeftSubTree(pNode) == dNode)
            ChangeLeftSubTree(pNode, dcNode);
        else
            ChangeRightSubTree(pNode, dcNode);
    }
    //세번쨰: 삭제대상이 2개의 자식노드를 가진 경우
    else
    {
        BTreeNode * mNode = GetRightSubTree(dNode);    //대체노드
        BTreeNode * mpNode = dNode;                    //대체노드의 부모노드
        int delData;

        //대체노드 찾기
        while(GetLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }

        delData = GetData(dNode);
        SetData(dNode, GetData(mNode));

        //대체노드의 부모노드와 자식노드 연결
        if(GetLeftSubTree(mpNode) == mNode)
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        else
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

        dNode = mNode;
        SetData(dNode, delData);    //백업 데이터 복원
    }

    //삭제노드 = 루트노드일 경우 추가적 처리
    if(GetRightSubTree(pVRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVRoot);        //루트노드의 변경을 반영

    free(pVRoot);

    *pRoot = Rebalance(pRoot);
    return dNode;    //삭제 노드 반환
    
}

void ShowIntData(int data)
{
    printf("%d ", data);
}

// 이진탐색 트리에 저장된 모든 노드의 데이터를 출력한다.
void BSTShowAll(BTreeNode * bst)
{
    InorderTraverse(bst, ShowIntData);
}
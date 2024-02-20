#ifndef __BINARY_TREE__
#define __BINARY_TREE__

typedef int BTData;

typedef struct _bTreeNode        
{
    BTData data;
    struct _bTreeNode * left;
    struct _bTreeNode * right;
} BTreeNode;

//단일 노드라도 공집합으로 인해 이진트리가 됨 따라서 노드 구조체 = 이진트리 구조체
typedef BTreeNode BTNode;

BTNode * MakeBTreeNode(void);
BTData GetData(BTNode*bt);
void SetData(BTNode*bt, BTData data);

BTNode * GetLeftSubTree(BTNode*bt);
BTNode * GetRightSubTree(BTNode*bt);

void MakeLeftSubTree(BTNode* main, BTNode* sub);
void MakeRightSubTree(BTNode* main, BTNode* sub);

typedef void (*VisitFuncPtr)(BTData data);

void InorderTraverse(BTNode*bt, VisitFuncPtr action);     //중간탐색
void PreorderTraverse(BTNode*bt, VisitFuncPtr action);    //전위탐색
void PostorderTraverse(BTNode*bt, VisitFuncPtr action);   //후위탐색

void DeleteTree(BTNode*bt); //해당 트리 전체삭제
#endif
#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

//유일값을 가진 키 활용

#include "./../7_BTree/BinaryTree.h"

typedef BTData BSTData;

//BST 생성 및 초기화
void BSTMakeAndInit(BTreeNode ** pRoot);

//노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst);

// BST를 대상으로 데이터 저장(노드 생성과정 포함)
BTNode * BSTInsert(BTreeNode ** pRoot, BSTData data);

// BST를 대상으로 데이터 탐색
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

//트리에서 노드를 제거하고 제거된 노드의 주소값을 반환
BTreeNode * BSTRemove(BTreeNode**pRoot, BSTData target);

// 이진탐색 트리에 저장된 모든 노드의 데이터를 출력한다.
void BSTShowAll(BTreeNode * bst);

#endif
#ifndef __EXPRESSION_TREE__
#define __EXPRESSION_TREE__
//수식트리
#include "BinaryTree.h"

BTNode*MakeExpTree(char exp[]);        //수식트리 구성
int EvaluateExpTree(BTNode*bt);        //수식트리 계산

void showPrefixTypeExp(BTNode*bt);     //전위 표기법 기반 출력
void showInfixTypeExp(BTNode*bt);      //중위 표기법 기반 출력
void showPostfixTypeExp(BTNode*bt);    //후위 표기법 기반 출력

#endif
#ifndef __LB_STACK_H__
#define __LB_STACK_H__
#include "BinaryTree.h"

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef BTNode *Data;

typedef struct _node {
  struct _node *next;
  Data data;
} Node;

typedef struct _listStack {
  Node *head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

#endif
/*
#include "ListBaseStack.h"
#include <iostream>

void StackInit(Stack*pstack)
{
    pstack->head = NULL;
}

int SIsEmpty(Stack*pstack)
{
    if(pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack*pstack, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pstack->head;
    pstack->head = newNode;
}

Data SPop(Stack*pstack)
{
    Node * rNode = (Node*)malloc(sizeof(Node));
    Data rdata;

    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error");
        exit(-1);
    }
    
    rNode = pstack->head;
    rdata = rNode->data;

    pstack->head = pstack->head->next;
    free(rNode);
    return rdata;
}

Data SPeek(Stack*pstack)
{
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error");
        exit(-1);
    }
    return pstack->head->data;
}
*/
#include "DBDLinkedList.h"
#include <iostream>

void ListInit(List*plist)
{
    plist -> head = (Node*)malloc(sizeof(Node));
    plist -> tail = (Node*)malloc(sizeof(Node));
    
    plist -> head -> next = plist -> tail;
    plist -> head -> prev = NULL;
    
    plist -> tail -> prev = plist -> head; 
    plist -> tail -> next = NULL;
    
    plist -> numOfData = 0;
}

void LInsert(List*plist, Data data)
{
    Node*newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;

    newNode -> prev = plist -> tail -> prev;
    plist -> tail -> prev -> next = newNode;
    
    newNode -> next = plist -> tail;
    plist -> tail -> prev = newNode;
    
    (plist->numOfData)++;
}

int LFirst(List*plist, Data*data)
{
    if(plist->head->next == plist->tail)
        return FALSE;

    plist -> cur = plist -> head -> next;
    *data = plist -> cur -> data;
    return TRUE;
}

int LNext(List*plist, Data*data)
{
    if(plist->cur->next == plist -> tail)
        return FALSE;

    plist -> cur = plist -> cur -> next;
    *data = plist -> cur -> data;
    return TRUE;
}

int LPrevious(List*plist, Data*data)
{
    if(plist->cur->prev == plist -> head)
        return FALSE;

    plist -> cur = plist -> cur -> prev;
    *data = plist -> cur -> data;
    return TRUE;
}

Data LRemove(List*plist)
{
    Node * rpos = plist -> cur;
    Data rdata = plist -> cur -> data;

    plist -> cur -> prev -> next = plist -> cur -> next;
    plist -> cur -> next -> prev = plist -> cur -> prev;

    free(rpos);
    
    (plist->numOfData)--;
    return rdata;
}

int LCount(List*plist)
{
    return plist->numOfData;
}
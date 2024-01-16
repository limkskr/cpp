#ifndef __DBD_LINKED_LIST__
#define __DBD_LINKDE_LIST__

#define TRUE    1
#define FALSE   0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node * next;
    struct _node * prev;
} Node;

typedef struct _DLinkedList
{
    Node * head;
    Node * tail;
    Node * cur;
    int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List*plist);
void LInsert(List*plist, Data data);

int LFirst(List*plist, Data*data);
int LNext(List*plist, Data*data);
int LPrevious(List*plist, Data*data);

Data LRemove(List*plist);
int LCount(List*plist);

#endif
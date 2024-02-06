#ifndef __CURCULAR_QUEUE__
#define __CURCULAR_QUEUE__

#define TRUE     1
#define FALSE    0
#define QueLen   100
typedef int Data;

typedef struct _cQueue
{
    int front;
    int rear;
    Data queArr[QueLen];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);

#endif
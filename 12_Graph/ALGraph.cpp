/*
#include "ALGraph.h"
#include "./3_LinkedList/DLinkedList.h"
#include "./4_Stack/ArrayBaseStack.h"
#include "./5_Queue/CircularQueue.h"
#include <iostream>
#include <string.h>

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph * pg, int nv)
{
    int i;
    
    pg->numV = nv;
    pg->numE = 0;
    pg->adjList = (List*)malloc(sizeof(List)*nv);
    pg->visitInfo = (int*)malloc(sizeof(int)*pg-> numV);

    //adjList 초기화
    for(i=0; i<nv; i++)
    {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    //visitInfo 초기화
    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}

//그래프 리소스 해제
void GraphDestroy(ALGraph * pg)
{
    if(pg->adjList != NULL)
        free(pg->adjList);
    if(pg->visitInfo != NULL)
        free(pg->visitInfo);
}

//간선 추가
void AddEdge(ALGraph * pg, int fromV, int toV)
{
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;
}

//간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg)
{
    int i;
    int vx;

    for(i=0; i<pg->numV; i++)
    {
        printf("%c와 연결된 정점: ", i+65);

        if(LFirst(&(pg->adjList[i]), &vx))
        {
            printf("%c ", vx + 65);

            while(LNext(&(pg->adjList[i]), &vx))
            {
                printf("%c ", vx + 65);
            }
        }
        printf("\n");
    }
}

int WhoIsPrecede(int data1, int data2)
{
    if(data1 < data2)
        return 0;
    else
        return 1;
}

//2번째 매개변수 방문처리
int VisitVertex(ALGraph * pg, int visitV)
{
    if(pg->visitInfo[visitV] == 0)
    {
        pg->visitInfo[visitV] = 1;
        printf("%c ", visitV + 65);
        return TRUE;
    }
    return FALSE;
}

//DFS기반 정점출력
void DFShowGraphVertex(ALGraph * pg, int startV)
{
    Stack stack;
    int visitV = startV;
    int nextV;

    StackInit(&stack);
    VisitVertex(pg, visitV);
    SPush(&stack, visitV);

    //여기부터 첫 정점과 연결된 정점에 방문시도 반복문 만들기
    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
    {
        int visitFlag = FALSE;

        if(VisitVertex(pg, nextV) == TRUE)
        {
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        }
        else
        {
            while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
            {
                if(VisitVertex(pg, nextV) == TRUE)
                {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        if(visitFlag == FALSE)    //추가로 방문한 정점이 없다면
        {
            if(SIsEmpty(&stack) == TRUE)
                break;
            else
                visitV = SPop(&stack);
        }
    }

    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}

void BFShowGraphVertex(ALGraph * pg, int startV)
{
    Queue queue;
    int visitV = startV;
    int nextV;

    QueueInit(&queue);

    VisitVertex(pg, visitV);

    while(LFirst(&(pg->adjList[visitV]), &nextV))
    {
        if(VisitVertex(pg, nextV) == TRUE)
            Enqueue(&queue, nextV);
        
        while(LNext(&(pg->adjList[visitV]), &nextV))
        {
            if(VisitVertex(pg, nextV) == TRUE)
                Enqueue(&queue, nextV);
        }

        if(QIsEmpty(&queue) == TRUE)
            break;
        else
            visitV = Dequeue(&queue);
    }
    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}
*/
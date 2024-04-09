#include "ALGraphKruskal.h"
#include "./3_LinkedList/DLinkedList.h"
#include "./4_Stack/ArrayBaseStack.h"
#include "./5_Queue/CircularQueue.h"
#include "./8_Heap/PriorityQueue.h"
#include <iostream>
#include <string.h>


//adjList 정렬 함수
//연산자를 반대로 할 시 역정렬
int WhoIsPrecede(int data1, int data2)
{
    if(data1 < data2)
        return 0;
    else
        return 1;
}

//첫번째 인자의 가중치가 클 때 양수 반환 = 내림차순
int PQWeightComp(Edge d1, Edge d2)
{
    return d1.weight - d2.weight;
}

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

    //pqueue 초기화
    PQueueInit(&(pg->pqueue), PQWeightComp);
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
void AddEdge(ALGraph * pg, int fromV, int toV, int weight)
{
    Edge edge = {fromV, toV, weight};
    
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;

    PEnqueue(&(pg->pqueue), edge);
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


//2번째 매개변수 방문처리
int VisitVertex(ALGraph * pg, int visitV)
{
    if(pg->visitInfo[visitV] == 0)
    {
        pg->visitInfo[visitV] = 1;
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

//이하 크루스칼 알고리즘을 위한 함수
//한쪽 방향의 간선 소멸
void RemoveWayEdge(ALGraph * pg, int fromV, int toV)
{
    int edge;

    if(LFirst(&(pg->adjList[fromV]), &edge))
    {
        if(edge == toV)
        {
            LRemove(&(pg->adjList[fromV]));
            return;
        }

        while(LNext(&(pg->adjList[fromV]), &edge))
        {
            
            if(edge == toV)
            {
                LRemove(&(pg->adjList[fromV]));
                return;
            }
        }
    }
}

//간선 삭제, 무방향 그래프라 소멸시킬 간선 정보가 2개
void RemoveEdge(ALGraph * pg, int fromV, int toV)
{
    RemoveWayEdge(pg, fromV, toV);
    RemoveWayEdge(pg, toV, fromV);
    (pg->numE)--;
}


int IsConnVertex(ALGraph * pg, int v1, int v2)
{
    Stack stack;
    int visitV = v1;
    int nextV;

    StackInit(&stack);
    VisitVertex(pg, visitV);
    SPush(&stack, v1);

    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
    {
        int visitFlag = FALSE;
        if(nextV == v2)
        {
            memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
            return TRUE;
        }

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
                if(nextV == v2)
                {
                    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
                    return TRUE;
                }

                if(VisitVertex(pg, nextV) == TRUE)
                {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        if(visitFlag == FALSE)
        {
            if(SIsEmpty(&stack) == TRUE)
                break;
            else
            {
                visitV = SPop(&stack); 
            }   
        }
    }
    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
    return FALSE;
}


void RecoverEdge(ALGraph * pg, int fromV, int toV, int weight)
{
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    (pg->numE)++;
}
    
void ConKruskalMST(ALGraph * pg)
{
    Edge recvEdge[20];    //복원할 간선의 정보 저장
    Edge edge;
    int eidx = 0;
    int i;

    //MST를 형성할 때까지 반복
    while(pg->numE+1 > pg->numV)
    {
        edge = PDequeue(&(pg->pqueue));
        RemoveEdge(pg, edge.v1, edge.v2);

        if(!IsConnVertex(pg, edge.v1, edge.v2))
        {
            RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
            recvEdge[eidx++] = edge;
        }
    }

    //우선순위 큐에서 삭제된 간선의 정보를 회복
    for(i=0; i<eidx; i++)
        PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(ALGraph * pg)
{
    PQueue copyPQ = pg->pqueue;
    Edge edge;

    while(!PQIsEmpty(&copyPQ))
    {
        edge = PDequeue(&copyPQ);
        printf("(%c-%c), w:%d \n", edge.v1+65, edge.v2+65, edge.weight);    
    }
}
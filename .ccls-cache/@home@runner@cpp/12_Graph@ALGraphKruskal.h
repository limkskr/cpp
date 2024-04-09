#ifndef __AL_GRAPH_KRUSKAL_H__
#define __AL_GRAPH_KRUSKAL_H__

#include "./../3_LinkedList/DLinkedList.h"
#include "./../8_Heap/PriorityQueue.h"
#include "ALEdge.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
    int numV;    //정점의 수
    int numE;    //간선의 수
    List * adjList;    //간선 정보
    int * visitInfo;   //방문 정보
    PQueue pqueue;     //간선의 가중치 정보 저장
} ALGraph;

//그래프 초기화
void GraphInit(ALGraph * pg, int nv);

//그래프 리소스 해제
void GraphDestroy(ALGraph * pg);

//간선 추가
void AddEdge(ALGraph * pg, int fromV, int toV, int weight);

//간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

//DFS
void DFShowGraphVertex(ALGraph * pg, int startV);

void ConKruskalMST(ALGraph * pg);

void ShowGraphEdgeWeightInfo(ALGraph * pg);

#endif
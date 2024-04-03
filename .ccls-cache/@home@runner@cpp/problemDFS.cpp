#include "ALGraph.h"
#include <iostream>

int DFS(ALGraph * pg, int n)
{
    int nv;
    if(LFirst(&(pg->adjList[n]), &nv))
    {
        n = nv;
        printf("%c ", n + 65);
        DFS(pg, n);

        while(LNext(&(pg->adjList[n]), &nv))
        {
            n = nv;
            printf("%c ", n + 65);
            DFS(pg, n);
        }
    }
    return 0;
}

int main(void)
{
    ALGraph graph;
    GraphInit(&graph, 6);

    AddEdge(&graph, A, B);
    AddEdge(&graph, A, C);
    AddEdge(&graph, B, C);
    AddEdge(&graph, B, D);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, F);
    AddEdge(&graph, F, B);

    ShowGraphEdgeInfo(&graph);
    DFS(&graph, A);
    GraphDestroy(&graph);
    return 0;
}


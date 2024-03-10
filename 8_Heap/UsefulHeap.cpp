#include "UsefulHeap.h"
#include <iostream>

void HeapInit(Heap*ph, PriorityComp pc)
{
    ph->numOfData = 0;
    ph->comp = pc;
}

int  HIsEmpty(Heap*ph)
{
    if(ph->numOfData == 0)
        return TRUE;
    return FALSE;
}

int GetParentIdx(int idx)
{
    return idx/2;
}

int GetLChildIdx(int idx)
{
    return idx*2;
}
int GetRChildIdx(int idx)
{
    return GetLChildIdx(idx)+1;
}

int GetHiprichildIdx(Heap*ph, int idx)
{
    if(GetLChildIdx(idx) > ph->numOfData)
        return 0;
        
    else if(GetLChildIdx(idx)==ph->numOfData)
        return GetLChildIdx(idx);
        
    else
    {
        if(ph->comp(ph->heapArr[GetLChildIdx(idx)], ph->heapArr[GetRChildIdx(idx)]) < 0)
            return GetRChildIdx(idx);
            
        else
            return GetLChildIdx(idx);
    }
}

void HInsert(Heap*ph, HData data)
{
    int idx = ph->numOfData+1;

    while(idx != 1)
    {
        if(ph->comp(data, ph->heapArr[GetParentIdx(idx)]) > 0)
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
            idx = GetParentIdx(idx);
        }
        else
            break;
    }
    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}

HData HDelete(Heap*ph)    //루트 노드 삭제
{
    HData rdata = ph->heapArr[1];    //루트노드의 데이터 저장 = 삭제할 노드의 데이터 저장
    HData lastElem = ph->heapArr[ph->numOfData];        //힙의 마지막 노드 저장

    int parentIdx = 1;        //마지막 노드를 루트노드로 옮김과 동일, 마지막 노드가 저장될 위치
    int childIdx;        

    while((childIdx = GetHiprichildIdx(ph,parentIdx))) 
    {
        if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0) //마지막 노드 우선순위 높으면 탈출 
            break;
        //마지막 노드보다 우선순위 우선순위 높으니 비교 노드 위치를 한 레벨 올림
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;                         //마지막 노드가 저장될 위치를 한 레벨 내림
    }

    ph->heapArr[parentIdx] = lastElem;    //마지막 노드 최종 저장
    ph->numOfData -= 1;
    return rdata;
}
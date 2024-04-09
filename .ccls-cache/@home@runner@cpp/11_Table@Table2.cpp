/*
#include "Table2.h"
#include "Slot2.h"
#include "./../3_LinkedList/DLinkedList.h"
#include <iostream>

//테이블 초기화
void TableInit(Table * pt, HashFunc f)
{
    int i;

    //모든 슬롯 초기화
    for(i=0; i<MAX_TBL; i++)
        ListInit(&(pt->tbl[i]));

    pt->hf = f;    //해쉬함수 등록

}

//테이블에 키와 값 저장
void TableInsert(Table * pt, Key k, Value v)
{
    int hv = pt->hf(k);
    Slot ns = {k, v};

    if(TableSearch(pt,k) != NULL)
    {
        printf("키가 중복되었습니다.");
        return;
    }
    else
    {
        LInsert(&(pt->tbl[hv]), ns);
    }

}

//키를 근거로 테이블 데이터 삭제
Value TableDelete(Table * pt, Key k)
{
    int hv = pt->hf(k);
    Slot cSlot;
    
    if(LFirst(&(pt->tbl[hv]), &cSlot))
    {
        if(cSlot.key == k)
        {
            LRemove(&(pt->tbl[hv]));
            return cSlot.value;
        }
        else
        {
            while(LNext(&(pt->tbl[hv]), &cSlot))
            {
                if(cSlot.key == k)
                {
                    LRemove(&(pt->tbl[hv]));
                    return cSlot.value;
                }
            }
        }
    }
    return NULL;
}

//키를 근거로 테이블 데이터 탐색
Value TableSearch(Table * pt, Key k)
{
    int hv = pt->hf(k);
    Slot cSlot;
    
    if(LFirst(&(pt->tbl[hv]), &cSlot))
    {
        if(cSlot.key == k)
            return cSlot.value;
        else
            while(LNext(&(pt->tbl[hv]), &cSlot))
                if(cSlot.key == k)
                    return cSlot.value;
    }
    return NULL;
}
*/
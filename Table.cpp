#include "Table.h"
#include "Slot.h"
#include <iostream>

//테이블 초기화
void TableInit(Table * pt, HashFunc f)
{
    int i;

    //모든 슬롯 초기화
    for(i=0; i<MAX_TBL; i++)
        (pt->tbl[i]).status = EMPTY;
    
    pt->hf = f;    //해쉬함수 등록
    
}

//테이블에 키와 값 저장
void TableInsert(Table * pt, Key k, Value v)
{
    int hv = pt->hf(k);
    pt->tbl[hv].value = v;
    pt->tbl[hv].key = k;
    pt->tbl[hv].status = INUSE;

}

//키를 근거로 테이블 데이터 삭제
Value TableDelete(Table * pt, Key k)
{
    int hv = pt->hf(k);

    if((pt->tbl[hv]).status != INUSE)
        return NULL;
    else
    {
        (pt->tbl[hv]).status = DELETED;
        return (pt->tbl[hv]).value;
    }
}

//키를 근거로 테이블 데이터 탐색
Value TableSearch(Table * pt, Key k)
{
    int hv = pt->hf(k);

    if((pt->tbl[hv]).status != INUSE)
        return NULL;
    else
        return (pt->tbl[hv]).value;
}
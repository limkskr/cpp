#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"

#define MAX_TBL 100

typedef int (*HashFunc)(Key k);

typedef struct _table
{
    Slot tbl[MAX_TBL];
    HashFunc hf;
} Table;

//테이블 초기화
void TableInit(Table * pt, HashFunc f);

//테이블에 키와 값 저장
void TableInsert(Table * pt, Key k, Value v);

//키를 근거로 테이블 데이터 삭제
Value TableDelete(Table * pt, Key k);

//키를 근거로 테이블 데이터 탐색
Value TableSearch(Table * pt, Key k);

#endif
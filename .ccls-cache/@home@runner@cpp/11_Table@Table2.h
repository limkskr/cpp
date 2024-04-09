/*
1. 슬롯 자체를 노드로 = Slot에 next 삽입
2. 노드와 슬롯 구분, 노드에 슬롯 주솟값 저장
3. 슬롯을 노드의 데이터로 저장

#ifndef __TABLE2_H__
#define __TABLE2_H__

#include "Slot2.h"
#include "./../3_LinkedList/DLinkedList2.h"

#define MAX_TBL 100

typedef int (*HashFunc)(Key k);

typedef struct _table
{
    List tbl[MAX_TBL];
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
*/
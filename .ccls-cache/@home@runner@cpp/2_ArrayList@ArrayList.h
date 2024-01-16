#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
#include "Point.h"

#define TRUE    1
#define FALSE    0

#define LIST_LEN 100

//삽입 데이터 변경시 타입 변경 ex) int LData -> Point*LData
typedef int LData;

typedef struct __ArrayList
{
    //배열 크기
    LData arr[LIST_LEN];
    //배열에 저장된 데이터 개수
    int numOfData;
    //배열이 인덱스값 저장(-1 초기값(아무 위치도 가르키지 않음))
    int curPosition;
} ArrayList;

typedef ArrayList List;

void ListInit(List*plist);
void LInsert(List*plist, LData data);

int LFirst(List*plist, LData*pdata);
int LNext(List*plist, LData*pdata);

LData LRemove(List*plist);
int LCount(List*plist);

#endif
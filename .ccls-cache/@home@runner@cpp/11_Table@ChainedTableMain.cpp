/*
#include <iostream>
#include "Table2.h"
#include "Person.h"

int MyHashFunc(int k)
{
    return k % 100;
}

int Main(void)
{
    Table myTbl;
    Person * np;
    Person * sp;
    Person * rp;

    TableInit(&myTbl, MyHashFunc);

    //데이터 입력
    np = MakePersonData(900254, (char*)"Lee", (char*)"Seoul");
    TableInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(90139, (char*)"Kim", (char*)"Jeju");
    TableInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(900827, (char*)"HAN", (char*)"Kangwon");
    TableInsert(&myTbl, GetSSN(np), np);

    //데이터 탐색
    sp = TableSearch(&myTbl, 900254);
    if(sp != NULL)
        ShowPerInfo(sp);

    sp = TableSearch(&myTbl, 90139);
    if(sp != NULL)
        ShowPerInfo(sp);

    sp = TableSearch(&myTbl, 900827);
    if(sp != NULL)
        ShowPerInfo(sp);

    //데이터 삭제
    rp = TableDelete(&myTbl, 900254);
    if(rp != NULL)
        free(rp);

    rp = TableDelete(&myTbl, 90139);
    if(rp != NULL)
        free(rp);

    rp = TableDelete(&myTbl, 900827);
    if(rp != NULL)
        free(rp);

    return 0;
}
*/
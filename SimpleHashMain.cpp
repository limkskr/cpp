#include <iostream>
#include "Table.h"
#include "Person.h"

int MyHashFunc(int k)
{
    return k % 100;
}

int main(void)
{
    Table myTbl;
    Person * np;
    Person * sp;
    Person * rp;

    TableInit(&myTbl, MyHashFunc);

    //데이터 입력
    np = MakePersonData(20120003, (char*)"Lee", (char*)"Seoul");
    TableInsert(&myTbl, GetSSN(np), np);
    
    np = MakePersonData(20130012, (char*)"Kim", (char*)"Jeju");
    TableInsert(&myTbl, GetSSN(np), np);
    
    np = MakePersonData(20170049, (char*)"HAN", (char*)"Kangwon");
    TableInsert(&myTbl, GetSSN(np), np);

    //데이터 탐색
    sp = TableSearch(&myTbl, 20120003);
    if(sp != NULL)
        ShowPerInfo(sp);

    sp = TableSearch(&myTbl, 20130012);
    if(sp != NULL)
        ShowPerInfo(sp);

    sp = TableSearch(&myTbl, 20170049);
    if(sp != NULL)
        ShowPerInfo(sp);

    //데이터 삭제
    rp = TableDelete(&myTbl, 20120003);
    if(rp != NULL)
        free(rp);

    rp = TableDelete(&myTbl, 20130012);
    if(rp != NULL)
        free(rp);

    rp = TableDelete(&myTbl, 20170049);
    if(rp != NULL)
        free(rp);

    return 0;
}
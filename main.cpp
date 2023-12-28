#include <iostream>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"
int main()
{    
    List list;
    Point compos;
    Point * ppos;

    ListInit(&list);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);

    printf("현재 데이터 수: %d \n", LCount(&list));

    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos))
                ShowPointPos(ppos);
    }
    printf("\n");

    compos.xpos = 2;
    compos.ypos = 0;


    if(LFirst(&list, &ppos))
    {
        if(PointComp(ppos, &compos)==1)
        {
            ppos=LRemove(&list);
            free(ppos);
        }
        while(LNext(&list, &ppos))
        {
            if(PointComp(ppos, &compos)==1)
            {
                ppos=LRemove(&list);
                free(ppos);
            }
        }
    }
    printf("현재 데이터 수: %d \n", LCount(&list));

    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos))
                ShowPointPos(ppos);
    }
    printf("\n");
    return 0;
}

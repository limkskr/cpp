#include <iostream>
#include <stdlib.h>
#include "DLinkedList.h"

int Comp(int a, int b)
{
    if(a<b)
        return 0;
    else
        return 1;
}
int main()
{
    List list;
    int data;
    ListInit(&list);
    SetSortRule(&list, Comp);

    LInsert(&list, 11); LInsert(&list, 11);
    LInsert(&list, 22); LInsert(&list, 22);
    LInsert(&list, 33);

    printf("현재 데이터수: %d \n", LCount(&list));

    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    if(LFirst(&list, &data))
    {
        if(data == 22)
            LRemove(&list);

        while(LNext(&list, &data))
        {
            if(data == 22)
                LRemove(&list);
        }
    }

    printf("현재 데이터수: %d \n", LCount(&list));

    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");


}

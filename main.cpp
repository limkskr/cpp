#include <iostream>
#include "UsefulHeap.h"
#include <string.h>

int DataPriorityComp(char * str1, char * str2)    //우선순위 비교함수
{
    return strlen(str1) - strlen(str2);
}

int main(void)
{
    Heap heap;
    HeapInit(&heap, DataPriorityComp);

    HInsert(&heap, "Good morning");
    HInsert(&heap, "I am a boy");
    HInsert(&heap, "Priority Queue");

    while(!HIsEmpty(&heap))
        printf("%s \n", HDelete(&heap));

    return 0;
}
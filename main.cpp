#include <iostream>
#include "UsefulHeap.h"
#include <string>

int DataPriorityComp(std::string str1, std::string str2)    //우선순위 비교함수
{
    return str1.length() - str2.length();
}

int main(void)
{
    Heap heap;
    HeapInit(&heap, DataPriorityComp);

    HInsert(&heap, "Good morning");
    HInsert(&heap, "I am a boy");
    HInsert(&heap, "Priority Queue");

    while(!HIsEmpty(&heap))
        printf("%s \n", HDelete(&heap).c_str());

    return 0;
}
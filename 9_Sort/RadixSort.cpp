/*
// 기수 = 데이터를 이루는 기본 요소 ex) 2진수 -> 0,1 10진수 -> 0,1,2,3,4,5,6,7,8,9
// 종류: LSD = 가장 덜 중요한 것 부터 = 작은 자릿수 부터, MSD = 가장 중요한 것 부터 = 큰 자릿수 부터 
#include <iostream>
#include "ListBaseQueue.h"

#define BUKET_NUM    10

void RadixSort(int arr[], int num, int maxlen)
{
    Queue bukets[BUKET_NUM];
    int bi;
    int pos;
    int di;
    int divfac = 1;
    int radix;

    for(bi=0; bi<BUKET_NUM; bi++)
        QueueInit(&bukets[bi]);

    for(pos=0; pos<maxlen; pos++)
    {
        for(di=0; di<num; di++)
        {
            //n번째 자릿수 추출
            radix = (arr[di]/divfac)%10;
            //추출 숫자를 근거로 버킷에 저장
            Enqueue(&bukets[radix], arr[di]);
        }

        for(bi=0, di=0; bi<BUKET_NUM; bi++)
        {
            //버킷에 저장된 것 부터 꺼내서 다시 arr에 저장
            while(!QIsEmpty(&bukets[bi]))
                arr[di++] = Dequeue(&bukets[bi]);
        }
        divfac *= 10;
    }
    
}

int RMain(void) //메인
{
    int arr[7] = {13, 212, 14, 7141, 10987, 6, 15};
    //int arr[3] = {3, 3, 3};
    //int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int len = sizeof(arr)/sizeof(int);
    int i;
    RadixSort(arr, len, 5);

    for(i=0; i<len; i++)
        printf("%d ", arr[i]);

    return 0;
} */
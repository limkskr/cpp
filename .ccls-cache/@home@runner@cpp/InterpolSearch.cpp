#include <iostream>

//이진탐색과 같으나 탐색 시작 위치가 다름
//이 경우 mid
int ISearch(int d[], int first, int last, int target)
{
    int mid;

    if(d[first]>target || d[last] < target)
        return -1;

    mid = ((double)(target-d[first]) / (d[last]-d[first]) * (last-first)) + first;
    if(d[mid] == target)
        return mid;
    else if(target < d[mid])
        return ISearch(d,first,mid-1,target);
    else
        return ISearch(d,mid+1,last,target);
}

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 2);
    if(idx == -1)
        printf("탐색실패\n");
    else
        printf("타겟 저장 인덱스: %d \n", idx);
}
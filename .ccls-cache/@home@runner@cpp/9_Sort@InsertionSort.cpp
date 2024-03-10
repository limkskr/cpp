#include <iostream>
//삽입정렬 시간복잡도: n^2
void InsertionSort(int arr[], int n)
{
    int i,j;
    int temp;

    for(i=1; i<n; i++)
    {
        temp = arr[i];
        for(j=i-1; j>=0; j--)
        {
            if(temp < arr[j])
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = temp;
    }
}

int IMain(void) //메인
{
    int arr[5] = {5, 3, 2, 4, 1};
    int i;

    InsertionSort(arr, sizeof(arr)/sizeof(int));

    for(i=0; i<5; i++)
        printf("%d", arr[i]);

    printf("\n");
    return 0;
}
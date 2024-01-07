//1.반복문
int BSearch(int arr[], int len, int target){
    int first = 0;
    int last = len-1;
    int mid;

    while(first<=last)
        {
            mid = (first+last)/2;
            if(target == arr[mid])
            {
                return mid;
            }
            else
            {
                if(target < arr[mid])
                    last = mid-1;
                else
                    first = mid+1;
            }
        }
    return -1;
}
// 2. 재귀
int BSerchRecur(int d[], int first, int last, int target)
{
    int mid;

    if(first > last)
        return -1;

    mid = (first + last)/2;
    if(d[mid] == target)
        return mid;
    else if(target < d[mid])
        return BSerchRecur(d,first,mid-1,target);
    else
        return BSerchRecur(d,mid+1,last,target);
}
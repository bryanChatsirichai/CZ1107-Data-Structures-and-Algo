#include <stdio.h>
#include <stdlib.h>

int find(int arr[],int start,int end);
int main()
{
    int index;
    int arr[8] = {5,6,7,8,1,2,3,4};
    index = find(arr,0,7);
    printf("smallest number is %d at index %d\n",arr[index],index);
    return 0;
}
int find(int arr[],int start,int end)
{
    int mid,mid_num;
    mid = (start + end) / 2;
    printf("start is %d end is %d\n",start,end);
    if(start == end)
    {
        return start; ///min
    }
    else
    {
        mid_num = arr[mid];
        if(mid_num > arr[end])
        {
            find(arr,mid + 1,end);
        }
        else
        {
            find(arr,start,mid );
        }
    }

}

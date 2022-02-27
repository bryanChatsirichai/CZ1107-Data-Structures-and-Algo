#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[],int start,int end,int key);
int binary_search2(int arr[],int start,int end,int key);
int main()
{
    int arr[10] = {10,20,25,30,45,50,60,65,70,75};
    if(binary_search2(arr,0,9,220))
    {
        printf("found\n");
    }
    else
    {
        printf("Not found\n");
    }
    return 0;
}
int binary_search(int arr[],int start,int end,int key)
{
    //("TEST\n");
    int mid;
    if(start > end)
    {
        return 0;
    }
    else
    {
        mid = (start + end) / 2;
        printf("mid is %d\n",mid);
        if(arr[mid] == key)
        {
            return 1;
        }
        else if(arr[mid] > key)
        {
            end = mid - 1;
            binary_search(arr,start,end,key);
        }
        else if(arr[mid] < key)
        {
            start = mid + 1;
            binary_search(arr,start,end,key);
        }
    }
}
int binary_search2(int arr[],int start,int end,int key)
{
    int mid;
    while(start <= end)
    {
        mid = (start + end ) / 2;
        if(arr[mid] == key)
            return 1;
        else if(arr[mid] > key)
        {
            end = mid - 1;
        }
        else if(arr[mid] < key)
        {
            start = mid + 1;
        }
    }
    return 0;
}

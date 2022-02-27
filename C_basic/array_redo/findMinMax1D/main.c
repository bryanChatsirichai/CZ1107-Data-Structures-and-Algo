#include <stdio.h>
#include <stdlib.h>
#define SIZE 999
void findMinMax1D(int *arr,int size,int *max, int *min);
int main()
{
    int size,max_num,min_num,i;
    int num_ary[SIZE];
    printf("Enter array size: \n");
    scanf("%d", &size);
    for( i = 0;i < size; i ++)
        scanf("%d",&num_ary[i]);
    findMinMax1D(num_ary,size,&max_num,&min_num);
    printf("min = %d; max = %d\n",min_num,max_num);
    return 0;
}
void findMinMax1D(int *arr,int size,int *max, int *min){
    int i,temp;
    //set to 1st element in array
    //arr is a pointer constant to 1st element in array
    *max = *(arr);
    *min = *(arr);
    for(i=0;i < size; i ++)
        {
            if (*max <= arr[i])
                *max = arr[i];
            if(*min >= arr[i])
                *min = arr[i];
            if(*max < *min)
            {
                temp = *min;
                *min  = *max;
                *max = temp;
            }
        }

        return ;
}

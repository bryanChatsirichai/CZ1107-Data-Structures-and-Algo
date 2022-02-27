#include <stdio.h>
#include <stdlib.h>
#define SIZE 999
void find2Max1D(int arr[],int size,int *max1, int *max2);
int main()
{
    int max_num1,max_num2;
    int num_arr[SIZE],size,i;

    printf("Enter array size: \n");
    scanf("%d",&size);
    for(i = 0;i<size;i++)
        scanf("%d",&num_arr[i]);
    find2Max1D(num_arr,size,&max_num1,&max_num2);
    printf("Max1: %d\nMax2: %d\n",max_num1,max_num2);

    return 0;
}
void find2Max1D(int arr[],int size,int *max1, int *max2){
    int i,temp;
    *max1 = arr[0];
    *max2 = arr[0];
    for(i = 0;i < size;i++)
    {
            if(arr[i] >= *max1)
            {
                *max1 =  arr[i];
            }

            if(*max1 < *max2)
            {
            temp = *max2;
            *max2 = max1;
            *max1 = temp;
            }
    }

    return;
 }

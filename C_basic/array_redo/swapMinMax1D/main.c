#include <stdio.h>
#include <stdlib.h>
void swapMinMax(int *ar, int size);
int main()
{
    int arry[50];
    int size,i;
    printf("Enter array size: \n");
    scanf("%d", &size);
    swapMinMax(arry,size);
    printf("swapMinMax1D(): ");
    for(i = 0;i< sizei++)
        printf("%d ",*(arry+i));
    return 0;
}
void swapMinMax(int *ar, int size){
    int min,max,pos_max,pos_min,temp,i;
    min = ar[0];
    max = ar[0];
    for(i = 0;i<size;i++) //find min / max index
    {
        if(ar[i] <= min)
        {
            min = ar[i];
            pos_min = i;

        }
        if(ar[i] >= max)
        {
            max = ar[i];
            pos_max = i;

        }
    }

    //swap
    temp = ar[pos_min];
    ar[pos_min] = ar[pos_max];
    ar[pos_max] = temp;



}

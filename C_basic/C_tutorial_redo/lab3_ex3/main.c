#include <stdio.h>
#include <stdlib.h>
void printReverse1(int ar[],int size);
void printReverse2(int ar[],int size);
void reverse1D(int *ar,int size);
int main()
{
    int ar[80],size;
    int i;
    printf("Enter the array size\n");
    scanf("%d",&size);
    printf("Enter %d data\n",size);
    for(i = 0 ;i < size; i++)
    {
        scanf("%d",&ar[i]);
    }
    printReverse1(ar,size);
    printReverse2(ar,size);
    reverse1D(ar,size);
    return 0;
}
void printReverse1(int ar[],int size)
{
    int i,index;
    i = 0;
    index = size - 1;
    printf("printReverse1():\n");
    for(index;index>=0;index--)
        printf("%d ",ar[index]);
    printf("\n");
}

void printReverse2(int ar[],int size)
{
    int i,*index;
    i = 0;
    index = ar + (size - 1); //index a ptr to &last num
    printf("printReverse2():\n");
    for(index;index>=ar;index--)
        printf("%d ",*index);
    printf("\n");
}
void reverse1D(int *ar,int size){
    int i,j,temp;
    i = 0; //0 index
    j = size - 1; //last char in array
    printf("rever1D() \n");
    for(i; i < size/2;i++,j--)
    {   //printf("j index is %d\n",j);
        temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
    }
    for(i = 0;i<size;i++)
        printf("%d ",ar[i]);
    printf("\n");

}

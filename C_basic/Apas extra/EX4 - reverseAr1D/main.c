#include <stdio.h>
#include <stdlib.h>
void printReverse1(int ar[], int size);
void printReverse2(int ar[], int size);
void reverseAr1D(int ar[], int size);
int main()
{
    int size,i;
    int ar[10];
    printf("Enter array size:\n");
    scanf("%d",&size);
    printf("Enter %d array: \n", size);
    for(i = 0 ;i<size;i++)
        scanf("%d",&ar[i]);
   printReverse1(ar, size);
   printReverse2(ar, size);
   reverseAr1D(ar,size);
   printf("reverseAr1D():");
   if (size > 0) {
      for (i=0; i<size; i++)
         printf("%d ", ar[i]);


    return 0;

    }

}
void printReverse1(int ar[], int size){
    int i=0;
    printf("printReverse1():");
    for(size-1;size>0;size--) //size minus 1 for index only does not effect the loop
        //printf("size is %d\n",size-1);
        printf("%d ",ar[size-1]);
    printf("\n");
}

void printReverse2(int ar[], int size){
    int i=0;
    printf("printReverse2():");
    for(size-1;size>0;size--)
        printf("%d ",*(ar+size-1));
    printf("\n");
}
void reverseAr1D(int ar[], int size){
    int i,temp;
    for(i=0;i<size/2;i++)
    {
        //printf("size is %d\n",size);
        temp = ar[size-1-i];
        ar[size-1-i] = ar[i];
        ar[i] = temp;

    }


}


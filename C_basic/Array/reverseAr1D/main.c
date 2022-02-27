#include <stdio.h>
void printReverse1(int ar[], int size);
void printReverse2(int ar[], int size);

void reverseAr1D(int ar[], int size);
int main()
{
   int ar[80];
   int size, i;

   printf("Enter array size: \n");
   scanf("%d", &size);
   printf("Enter %d data: \n", size);
   for (i=0; i <= size-1; i++)
     {
      scanf("%d", &ar[i]);
     }
   printReverse1(ar, size);
   printReverse2(ar, size);
   reverseAr1D(ar, size);
   printf("reverseAr1D(): ");
   if (size > 0) {
      for (i=0; i<size; i++)
         printf("%d ", ar[i]);
   }
   return 0;
}
void printReverse1(int ar[], int size)
{
    int i=0;
    printf("printReverse1(): ");
    for(size;size>i;size--)
        printf("%d ",ar[size-1]);
    printf("\n");

}
void printReverse2(int ar[], int size)
{
    int *p,i=0;
    p = ar;
    printf("printReverse2(): ");
    for (size;size>i;size--)
        printf("%d ",*(p+(size-1)));
}
void reverseAr1D(int ar[ ], int size)
{
      /* Write your code here */
}

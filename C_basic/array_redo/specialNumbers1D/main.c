#include <stdio.h>
#include <stdlib.h>
#define SIZE 999
void specialNumbers1D(int arr[],int nums, int *size_ptr);
int main()
{
    int number,size,i;
    size = 0;
    int list_ary[SIZE];
    printf("Enter a number between (100 to 999)\n");
    scanf("%d",&number);
    specialNumbers1D(list_ary, number, &size);
    printf("specialNumbers1D(): ");
    for (i=0; i<size; i++)
        printf("%d ",list_ary[i]);

    return 0;
}
void specialNumbers1D(int arr[],int num, int *size_ptr){
    int last_digit,total,base,is_special;
    base = 100;
    for(base;base<= num; base++)
    {
        total = 0; //reset
        is_special = base;

    while(is_special != 0)
     {

       last_digit = is_special % 10;
        total = total + (last_digit * last_digit * last_digit);
        is_special /= 10 ;
     }
     if (total == base)
     {

        arr[*size_ptr] = total;
        printf("special number is %d\n",arr[*size_ptr]);
        (*size_ptr)++;
     }
    }

    return;
}

#include <stdio.h>
#include <stdlib.h>
int sumSqDigits1(int num);
void sumSqDigits2(int num,int *result);
int main()
{
   int num;
   int result_ptr;
   printf("Enter a number:\n");
   scanf("%d",&num);
   printf("sumSqDigits1(): %d\n", sumSqDigits1(num));
   sumSqDigits2(num,&result_ptr);
   printf("sumSqDigits2(): %d\n", result_ptr);
    return 0;
}
int sumSqDigits1(int num){
    int total,sqr;
    total = 0;
    while(num != 0){
        sqr = num % 10;
        total = total + (sqr * sqr);
        num /= 10;
    }
    return total;
}
void sumSqDigits2(int num,int *result){
    int total,sqr;
    total = 0;
    while(num != 0){
        sqr = num % 10;
        total = total + (sqr * sqr);
        num /= 10;
    }
 *result  = total;
}


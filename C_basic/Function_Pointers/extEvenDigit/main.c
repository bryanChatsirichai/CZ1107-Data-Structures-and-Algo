#include <stdio.h>
#define INIT_VALUE 999
int extEvenDigits1(int num);
void extEvenDigits2(int num, int *result);
int main()
{
 int number, result = INIT_VALUE;

 printf("Enter a number: \n");
 scanf("%d", &number);
 printf("extEvenDigits1(): %d\n", extEvenDigits1(number));
 extEvenDigits2(number, &result);
 printf("extEvenDigits2(): %d\n", result);
 return 0;
}
int extEvenDigits1(int num)

{
 int pow=1,last,newnum=0;
 while(num !=0)
 {
     last = num % 10;
     if(last % 2 == 0)
     {
         newnum = newnum + (last * pow);
         pow*=10;
     }
     num = num/10;
     //printf("num is %d\n",num);
 }
    if(newnum == 0)
    {
        return -1;
    }
    else
        return newnum;
}
void extEvenDigits2(int num, int *result)
{
int pow=1,last,newnum=0;
 while(num !=0)
 {
     last = num % 10;
     if(last % 2 == 0)
     {
         newnum = newnum + (last * pow);
         pow*=10;
     }
     num = num/10;
     printf("num is %d\n",newnum);
 }
    if(newnum == 0)
    {
        *result = -1;
    }
    else
        *result = newnum;

}

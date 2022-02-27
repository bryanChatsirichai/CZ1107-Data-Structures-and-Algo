#include <stdio.h>
int reverseDigits1(int num);
void reverseDigits2(int num, int *result);
int main()
{
 int num, result=999;
 printf("Enter a number: \n");
 scanf("%d", &num);
 printf("reverseDigits1(): %d\n", reverseDigits1(num));
 reverseDigits2(num, &result);
 printf("reverseDigits2(): %d\n", result);
 return 0;
}
int reverseDigits1(int num)
{
    int newnum=0,pow=10,temp;
    while(num != 0)
    {
        temp = num % 10;
        newnum = (newnum*pow) + temp;
        num=num/10;
        printf("new num %d\n",newnum);
    }
    return newnum;
}
void reverseDigits2(int num, int *result)
{
    int newnum=0,pow=10,temp;
    while(num != 0)
    {
        temp = num % 10;
        newnum = (newnum*pow) + temp;
        num=num/10;
        printf("new num %d\n",newnum);
    }
    *result = newnum;
}

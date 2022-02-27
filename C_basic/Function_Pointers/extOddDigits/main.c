#include <stdio.h>
#define INIT_VALUE 999
int extOddDigits1(int num);
void extOddDigits2(int num, int *result);
int main()
{
 int number, result = INIT_VALUE;

 printf("Enter a number: \n");
 scanf("%d", &number);
 printf("extOddDigits1(): %d\n", extOddDigits1(number));
 extOddDigits2(number, &result);
 printf("extOddDigits2(): %d\n", result);
 return 0;
}
int extOddDigits1(int num){
    int pow=1,new_num=0,last,digit;
    while(num != 0)
    {
        last = num % 10;

        if (last%2 == 1)
        {
            new_num = new_num + (last * pow);
            pow*=10;
        }
        num /= 10;
    }
    return (new_num != 0) ? new_num : -1;
}
void extOddDigits2(int num, int *result)
{
    *result = 0;
 int pow=1,new_num=0,last,digit;

    while(num != 0)
    {
        last = num % 10;

        if (last%2 == 1)
        {
            *result+= (last * pow);
            pow*=10;
        }
        num /= 10;
    }
    if(*result==0)
        *result = -1;

}

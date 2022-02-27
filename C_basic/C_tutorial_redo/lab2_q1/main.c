#include <stdio.h>
#include <stdlib.h>
int numdigit1(int num);
void numdigit2(int num,int *result);
int main()
{
    int number,result;
    printf("Enter the number: \n");
    scanf("%d",&number);
    printf("numDigits1(): %d\n", numdigit1(number));
  numdigit2(number, &result);
    printf("numDigits2(): %d\n", result);
    return 0;
}
int numdigit1(int num){
    int count = 0;
    while (num != 0)
    {
        num /= 10;
        count++;
    }

    return count;
}
void numdigit2(int num,int *result){
    int count = 0;
    while (num != 0)
    {
        num /= 10;
        count++;
    }

    *result =  count;
}

#include <stdio.h>
#include <stdlib.h>
int numDigits1(int num);
int numDigits2(int num,int *result);
int main()
{
    int number,result;
    printf("Enter the number: \n");
    scanf("%d",&number);
    printf("numDigit1(): %d\n", numDigits1(number));
    numDigits2(number, &result);
    printf("numDigit2(): %d\n", result);
    return 0;
}
int numDigits1(int num){
    int count=0;
    while(num !=0 )
    {
        num = num / 10;
        count += 1;
    }

    return count;
}

int numDigits2(int num,int *result){
    int count;
    while(num !=0 )
    {
        num = num / 10;
        count += 1;
    }
    *result = count;
}

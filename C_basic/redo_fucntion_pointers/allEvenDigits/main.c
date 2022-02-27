#include <stdio.h>
#include <stdlib.h>
int allEvenDigits1(int num);
int allEvenDigits2(int num,int *result);
int main()
{
    int number,is_even;
    int is_even_ptr;
    printf("Enter a number:\n");
    scanf("%d",&number);
    is_even = allEvenDigits1(number);
    if(is_even == 1)
        printf("allEvenDigits1(): yes\n");
    else if (is_even == 0)
    printf("allEvenDigits1(): no\n");
    else
        printf("allEvenDigits1(): error\n");
    allEvenDigits2(number,&is_even_ptr);
     if(is_even_ptr == 1)
        printf("allEvenDigits2(): yes\n");
    else if (is_even_ptr == 0)
    printf("allEvenDigits2(): no\n");
    else
        printf("allEvenDigits2(): error\n");
    return 0;
}

int allEvenDigits1(int num){
    int last_digit,even,count;
    count = 0;
    while (num != 0)
    {
        last_digit =  num % 10;
        if(last_digit % 2 != 0) //check if got odd digits
        {
            count+=1;
        }
        num /= 10;
    }

    if (count > 0) //not all digit is even
        return 0;
    else               //all digit even
        return 1;
}
int allEvenDigits2(int num,int *result){
    int last_digit,even,count;
    count = 0;
    while (num != 0)
    {
        last_digit =  num % 10;
        if(last_digit % 2 != 0) //check if got odd digits
        {
            count+=1;
        }
        num /= 10;
    }

    if (count > 0) //not all digit is even
        *result= 0;
    else               //all digit even
        *result = 1;
}


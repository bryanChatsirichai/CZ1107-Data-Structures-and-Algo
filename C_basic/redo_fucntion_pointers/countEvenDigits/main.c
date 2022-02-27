#include <stdio.h>
#include <stdlib.h>
int counteven1(int num);
void counteven2(int num,int *count);
int main()
{   int number;
    int count_ptr;
    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("countEvenDigits1(): %d\n", counteven1(number));
    counteven2(number,&count_ptr);
    printf("countEvenDigits2(): %d\n", count_ptr);

    return 0;
}
int counteven1(int num){
    int lastDigit,even;
    even = 0;
    while(num != 0) //check last digit at a time
    {
        lastDigit = num % 10;
        if(lastDigit % 2 == 0)//check last digit is even
        {
            even += 1;
        }
        num /= 10; //remove last digit
    }
    return even;
}
void counteven2(int num,int *count){
    int lastDigit,even;
    even = 0;
    while(num != 0) //check last digit at a time
    {
        lastDigit = num % 10;
        if(lastDigit % 2 == 0)//check last digit is even
        {
            even += 1;
        }
        num /= 10; //remove last digit
    }
    *count = even;

}

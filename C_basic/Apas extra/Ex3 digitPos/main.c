#include <stdio.h>
#include <stdlib.h>
int digitPos1(int number,int digit);
void digitPos2(int number, int digit, int *result);
int main()
{
    int number,digit,result=0;
    printf("Enter the number:\n");
    scanf("%d",&number);
    printf("Enter the digit:\n");
    scanf("%d",&digit);
    printf("digitPos1(): %d\n",digitPos1(number,digit));
    digitPos2(number, digit, &result);
   printf("digitPos2(): %d\n", result);
    return 0;
}

//count form the back assume last digit is position 1
int digitPos1(int number,int digit){
    int pos,last_digit;
    pos = 1; //default
    while(number != 0){
        last_digit = number % 10;
        if(digit == last_digit)
            return pos;
        else
            pos++;

        number /= 10; //remove last digit
        //reach here mean digit not in number
    }
 return 0;
}
void digitPos2(int number, int digit, int *result){
    int pos,last_digit;
    pos = 1; //default
    while(number != 0){
        last_digit = number % 10;
        if(digit == last_digit){
            *result = pos;
             return;
        }
        else
            pos++;

        number /= 10; //remove last digit
        //reach here mean digit not in number
    }
    *result = 0;
    return;
}

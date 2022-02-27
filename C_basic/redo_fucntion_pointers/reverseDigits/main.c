#include <stdio.h>
#include <stdlib.h>
int reverse1(int num);
void reverse2(int num,int *result);
int main()
{   int number,reverse_num;
    int result_ptr;
    printf("Enter a number:\n");
    scanf("%d",&number);
    reverse_num = reverse1(number);
    printf("reverseDigits1(): %d\n",reverse_num);
    reverse2(number, &result_ptr);
    printf("reverseDigits1(): %d\n",result_ptr);
    return 0;
}

int reverse1(int num){
    int last_digit,pow,new_num;
        pow = 10;
        new_num = 0;
        while(num != 0)
        {
            last_digit = num % 10;
            new_num = (new_num * pow) +last_digit;
            num /= 10;
        }
    return new_num;
}

void reverse2(int num,int *result){
        int last_digit,pow,new_num;
        pow = 10;
        new_num = 0;
        while(num != 0)
        {
            last_digit = num % 10;
            new_num = (new_num * pow) +last_digit;
            num /= 10;
        }
   *result = new_num;

}

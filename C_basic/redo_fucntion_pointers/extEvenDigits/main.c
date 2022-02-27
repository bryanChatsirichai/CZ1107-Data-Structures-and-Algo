#include <stdio.h>
#include <stdlib.h>
int extEvenDigits1(int num);
int extEvenDigits2 ( int num, int *result_ptr);
int main()
{   int number,even_nums;
    int result;
    printf("Enter a numbe:\n");
    scanf("%d",&number);
    even_nums = extEvenDigits1(number);
    printf("extEvenDigits1(): %d\n",even_nums);
    extEvenDigits2(number, &result);
    printf("extEvenDigits2(): %d\n",result);
    return 0;
}
int extEvenDigits1(int num){
    int pow,new_num,last_digit,check;
        new_num = 0;
        check = 0;
        pow = 1;
    while(num != 0){//start from last digit and arrange them in order
        last_digit = num % 10;
        if (last_digit  % 2 == 0 )
        {   check +=1; //if got even check + 1
            new_num = new_num + (last_digit * pow );
            pow *= 10; //control the position of the digit
        }
        num /= 10;
    }
    if (check > 0)
        return new_num;
    else
        return -1;
}
int extEvenDigits2(int num, int *result_ptr){
        int pow,new_num,last_digit,check;
        new_num = 0;
        check = 0;
        pow = 1;
    while(num != 0){//start from last digit and arrange them in order
        last_digit = num % 10;
        if (last_digit  % 2 == 0 )
        {   check +=1; //if got even check + 1
            new_num = new_num + (last_digit * pow );
            pow *= 10; //control the position of the digit
        }
        num /= 10;
    }
    if (check > 0)
        *result_ptr = new_num;
    else
         *result_ptr = -1;
}

#include <stdio.h>
#include <stdlib.h>
int digitPos1(int num, int digit);
void digitPos2(int num, int digit, int *result);
int main()
{
    int num,digit,result;

    printf("Enter the number\n");
    scanf("%d",&num);
   printf("Enter the digit: \n");
   scanf("%d", &digit);
   printf("digitPos1(): %d\n", digitPos1(num, digit));
   digitPos2(num,digit,&result);
     printf("digitPos2(): %d\n", result);
    return 0;
}
//i self change the question.Left is 1
int digitPos1(int num,int digit){
    int pos,count,total_len,last_digit,result,have=0;
    total_len = 0;
    pos = 1;
    while(num != 0)
    {
        total_len += 1;
        last_digit = num % 10;
        if(last_digit == digit)
            {
                pos = total_len;
                have = 1;

            }
        num /= 10;
    }

    printf("pos = %d\n",pos);
    printf("toal len = %d\n",total_len);

    result =  total_len - pos + 1;
    if(have>0)
        return result;
    else
        return 0;
}
//Original
void digitPos2(int num,int digit,int *result){
    int pos,count,total_len,last_digit;
    *result = 0; //set default 0 thus if fail return 0 to *ptr
    pos = 0;
    while ( num != 0)
    {
        pos += 1;
        last_digit = num % 10;
        if(last_digit == digit)
            {
                *result = pos;
                break;
            }
        num /= 10;

    }

}

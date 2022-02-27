#include <stdio.h>
#include <stdlib.h>
int square1(int num);
int square2(int num ,int *result);
int main()
{
    int number,result;
    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("square1(): %d\n", square1(number));
    square2(number, &result);
    printf("square2(): %d\n", result);
    return 0;
}
int square1(int num){
    int total,new_num,start,odd;
    total = 0;
    start = 1;
    new_num = num * 2;
    while (start < new_num)
    {

        //check if odd
        if(start % 2 == 1)
            total = total + start;
        start++;
    }

    return total;
}
int square2(int num,int *result){
    int total,new_num,start,odd;
    total = 0;
    start = 1;
    new_num = num * 2;
    while (start < new_num)
    {

        //check if odd
        if(start % 2 == 1)
            total = total + start;
        start++;
    }

    *result = total;
}

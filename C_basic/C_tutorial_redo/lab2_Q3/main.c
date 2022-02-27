#include <stdio.h>
#include <stdlib.h>
int square1(int num);
void square2(int num,int *result);
int main()
{
    int number , result;
    printf("Enter the number:\n");
    scanf("%d",&number);
    result = square1(number);
    printf("square1() %d\n",result);
    square2(number,&result);
   printf("square2() %d\n",result);
    return 0;
}
int square1(int num){
    int i,total;
    total = 0;
    num = num * 2;
    for(i = 1;i< num;i++)
        if(i%2 == 1)
            total += i;


return total;

}
void square2(int num,int *result){
    int i,total;
    total = 0;
    num = num * 2;
    for(i = 1;i< num;i++)
        if(i%2 == 1)
            total += i;


    *result = total;

}

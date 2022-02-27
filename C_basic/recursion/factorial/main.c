#include <stdio.h>
#include <stdlib.h>
int count = 0;
int factorial(int num); //return a integer
int main()
{
    int num;

printf("Enter an integer: ");
scanf("%d", &num);
printf("n! = %d\n", factorial(num));
    return 0;
}
int factorial(int num){

    printf("%d\n",count+=1);
    if(num==0)
        return 1;
    else
        return num * factorial(num-1);


}

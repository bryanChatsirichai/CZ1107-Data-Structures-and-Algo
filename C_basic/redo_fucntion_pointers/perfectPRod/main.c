#include <stdio.h>
#include <stdlib.h>
int perfectProd1(int num);
void perfectProd2(int number, int *result);
int main()
{
    int number;
    int result;
    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("Calling perfectProd1() \n");
    printf("perfectProd1(): %d\n", perfectProd1(number));
    printf("Calling perfectProd2() \n");
    perfectProd2(number, &result);
    printf("perfectProd2(): %d\n", result);


    return 0;
}

int perfectProd1(int num)
{
    int i,total=1,check;
    for(i=1;i<=num;i++) //check up till number given
    {
        check = 0; //reset every check
        for(int factor = 1; factor <= i; factor++)
        {
            if(i%factor == 0)
                check += factor;
        }
         //printf("check number: %d\n",check);

        check = check - i; //excluding its own factor
        if (check ==  i)  //check if sum of factor is num
        {
            printf("perfect number: %d\n",check);
            total = check * total;

        }

    }
    return total;
}
void perfectProd2(int num, int *result)
{
    int i,total=1,check;
    for(i=1;i<=num;i++) //check up till number given
    {
        check = 0; //reset every check
        for(int factor = 1; factor <= i; factor++)
        {
            if(i%factor == 0)
                check += factor;
        }
         //printf("check number: %d\n",check);

        check = check - i; //excluding its own factor
        if (check ==  i)  //check if sum of factor is num
        {
            printf("perfect number: %d\n",check);
            total = check * total;

        }

    }
    *result =  total;
}

#include <stdio.h>
#include <stdlib.h>
float power1(int num,int power);
void power2(int num,int power,float *result);


int main()
{
    int num,power;
   float pow_num,pow_num2 ;
    printf("Enter the number and power:");
    scanf("%d %d",&num,&power);
    pow_num = power1(num, power);
    printf("power1(): %.2f\n",pow_num);
    power2(num,power,&pow_num2);
    printf("power1(): %.2f\n",pow_num2);
    return 0;
}

float power1(int num, int power)
{
    int i=0;
    float result=1.0;
    if (power >= 0)
        for(i;i<power;i++)
            result = result * num;

    else
        for(i;i > power;i--)
            result = result * (1.0/num);


    return result;
}

void power2(int num,int power,float *result)
{
        int i=0;
    float result2=1.0;
    if (power >= 0)
        for(i;i<power;i++)
            result2 = result2 * num;

    else
        for(i;i > power;i--)
            result2 = result2 * (1.0/num);

    *result =  result2;
}

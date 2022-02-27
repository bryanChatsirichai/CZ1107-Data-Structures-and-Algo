#include <stdio.h>
#include <stdlib.h>

int main()
{
    //base case of 1 set as default
    int denominator = 1,n;
    float numerator = 1,result = 1,x;
    printf("Please enter the value of x: \n");
    scanf("%f", &x);
    for(n = 1;n <= 10; n++)
    {
        numerator =  numerator * x;
        denominator = denominator * n;
        result = result +(numerator / denominator);
    }
    printf("Result = %.2f\n",result);
    return 0;
}

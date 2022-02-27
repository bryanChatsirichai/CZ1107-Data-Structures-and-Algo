#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, denominator = 1 ;
    float x, result = 1.0, numerator = 1.0;

    printf("Please enter the value of x: \n");
    scanf("%f", &x);
    for (n = 1; n <= 10; n++)
    {
        denominator *= n;
        numerator *= x ;
        result = result + numerator / denominator;
        printf("%d\n", n);
        printf("Result = %.2f\n", result);

    }
    printf("Result = %.2f\n", result);
    return 0;
}

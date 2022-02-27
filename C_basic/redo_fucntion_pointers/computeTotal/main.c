#include <stdio.h>
#include <stdlib.h>
void computeTotal(int numOfLines);
int main()
{
    int numOfLines;
    printf("Enter number of lines: \n");
    scanf("%d", &numOfLines);
    computeTotal(numOfLines);
    return 0;
}


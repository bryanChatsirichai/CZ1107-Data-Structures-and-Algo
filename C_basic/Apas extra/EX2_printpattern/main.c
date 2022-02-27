#include <stdio.h>
#include <stdlib.h>

int main()
{
    int height,row,col,pattern;
    printf("Enter the height: \n");
    scanf("%d",&height);
     printf("Pattern: \n");
    for(row =  1;row <= height;row++)
    {
        pattern = row;
        for(col=1;col<=row;col++)
        {   if(pattern%3==0)
                pattern = 3;
            else
                pattern = pattern % 3;
            printf("%d",pattern);
        }
        printf("\n");
    }
    return 0;
}

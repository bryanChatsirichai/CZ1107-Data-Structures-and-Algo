#include <stdio.h>
#include <stdlib.h>
void printPattern3(int height);
int main()
{
    int height;
    printf("Enter the height: \n");
    scanf("%d",&height);
    printPattern3(height);
    return 0;
}
void printPattern3(int height){
    int row,col,count;

    for(row = 1;row <= height ;row++)
    {
        count = row;
        for(col = 1;col<=row;col++ )
        {
           printf("%d",count);
           count++;
           if (count > 9)
            count = 0;
        }
        printf("\n");
    }
}

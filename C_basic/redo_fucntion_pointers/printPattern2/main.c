#include <stdio.h>
#include <stdlib.h>
void printPattern2(int height);
int main()
{
    int height;
    printf("Enter the height:\n");
    scanf("%d",&height);
    printf("printPattern2():\n");
    printPattern2(height);

    return 0;
}
void printPattern2(int height)
{
    int row,col,control; //
    control = 1;
    for (row = 1 ;row <= height;row++) //control height
    {
        for(col = 1; col <= row;col++) //control how many per row
        {
            if(control % 2 == 1)
            {
                printf("A");
                control = 0; //alternate A / B
            }
            else
            {
                printf("B");
                control = 1; //alternate A / B
            }
        }
        printf("\n"); //new row

    }
}

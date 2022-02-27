#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void transpose2D(int ar[][SIZE], int row, int col);

int main()
{
   int ary[SIZE][SIZE], col,row,i,j;
   printf("Enter row size of the 2D array:\n");
   scanf(" %d",&row);
   printf("Enter column size of the 2D array:\n");
   scanf(" %d",&col);
   for(i=0;i<row;i++)
    for(j=0;j<col;j++)
   {
       scanf(" %d",&ary[i][j]);
   }
    transpose2D(ary,row,col);
    for(i=0;i<row;i++){
        for(j=0;j<col;j++)
        {
            printf("%d ",ary[i][j]);
        }
        printf("\n");
    }
}
void transpose2D(int ary[][SIZE], int row, int col)
{
    int i,j,temp;
     for(i=1;i<row;i++)
        for(j=0;j<i;j++) //using col as control
        {
            temp = ary[i][j];
            ary[i][j] = ary[j][i];
            ary[j][i] = temp;
        }
}

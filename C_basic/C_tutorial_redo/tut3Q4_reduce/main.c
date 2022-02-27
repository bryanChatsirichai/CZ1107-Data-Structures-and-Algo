#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void reduce2D(int ar[][SIZE],int row_size,int col_size);
int main()
{
    int i,j,row,col;
    int matrix[SIZE][SIZE];
    printf("Enter the row size\n");
    scanf("%d",&row);
    printf("Enter the col size\n");
    scanf("%d",&col);
    printf("Enter the matrix %d X %d\n",row,col);
    for(i = 0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%d",&matrix[i][j]);
    reduce2D(matrix,row,col);
    printf("reduce2D():\n");
        for(i = 0;i<row;i++){
            for(j=0;j<col;j++)
               printf("%d ",matrix[i][j]);
            printf("\n");
        }

    return 0;
}
void reduce2D(int ar[][SIZE],int row_size,int col_size){
    int i, j;
    int total;
    for(j = 0;j<col_size-1;j++)
    {
        total = 0;
        i = j+1;
        for(i;i<row_size;i++)
        {
            //printf("%d\n",ar[i][j]);
            total = total + ar[i][j];
            ar[i][j] = 0;

        }

        ar[j][j] = ar[j][j] + total ;

    }
}

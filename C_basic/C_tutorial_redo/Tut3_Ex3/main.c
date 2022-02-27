#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void transpose2D(int ar[][SIZE],int row_size,int col_size);
int main()
{
    int i,j,row,col;
    int matrix[SIZE][SIZE];
    int trans[SIZE][SIZE];
    printf("Enter the row size\n");
    scanf("%d",&row);
    printf("Enter the col size\n");
    scanf("%d",&col);
    printf("Enter the matrix %d X %d\n",row,col);
    for(i = 0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%d",&matrix[i][j]);
    transpose2D(matrix,row,col);
        printf("transpose2D():\n");
        for(i = 0;i<row;i++){
            for(j=0;j<col;j++)
               printf("%d ",matrix[i][j]);
            printf("\n");
        }

    return 0;
}


void transpose2D(int ar[][SIZE],int row_size,int col_size){
    int i,j;
    int temp;
    printf("transpose2D():\n");
    for(i = 1;i<row_size;i++)
    {
     for(j=0;j<i;j++)
      {
        temp = ar[i][j];
        ar[i][j] = ar[j][i];
        ar[j][i] = temp;
      }

}
}


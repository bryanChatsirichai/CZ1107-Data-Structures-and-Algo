#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int symmetry( int ar[][SIZE],int row_size, int col_size);
int main()
{
    int row,col,i,j,result;
    int matrix[SIZE][SIZE];
    result = 999; //set default error
    printf("Enter the array size (rowSize, colSize): \n");
    scanf("%d %d ",&row,&col);
    for(i = 0 ; i < row;i++)
        for(j = 0; j < col ; j++)
            scanf("%d",&matrix[i][j]);
    result = symmetry(matrix,row,col);
   if (result == 1)
    printf("symmetry(): Yes\n");

 else if (result == 0)
    printf("symmetry(): No\n");

 else
    printf("Error\n");
return 0;
}
int symmetry( int ar[][SIZE],int row_size,int col_size){
    int i,j,result; //local to function
    result = 1; //assume symmetric
    for(i = 0  ; i < row_size;i++)
        for(j = 0; j < col_size ; j++)
            if(ar[i][j] != ar[j][i])
                result = 0;

    printf("result are %d\n",result);
    return result;
}

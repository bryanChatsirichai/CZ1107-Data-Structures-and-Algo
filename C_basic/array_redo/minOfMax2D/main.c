#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int minOfMax2D(int ar[][SIZE],int rowsize,int colsize);
int main()
{   int row,col,i,j,result;
    int matrix[SIZE][SIZE];
    printf("Enter row / col size of the 2D array: \n");
    scanf("%d %d",&row,&col);
    for (i=0; i<row; i++)
        for (j=0; j<col; j++)
            scanf("%d", &matrix[i][j]);
    result = minOfMax2D(matrix,row,col);
    printf("minOfMax2D(): %d\n",result);
    return 0;
}
int minOfMax2D(int ar[][SIZE],int rowsize,int colsize){
    int i , j, minOfmax,temp,max; //local
    int new_nums[rowsize];
    for (i=0; i<rowsize; i++)
    {
        temp = ar[i][0]; //row 1st number set as min default
        for (j=0; j<colsize; j++)
            if(ar[i][j] > temp)
                temp = ar[i][j];

        new_nums[i] = temp; //put all max of each row in a new array
    }

    minOfmax = new_nums[0];
    for(i = 0; i< sizeof(new_nums)/sizeof(new_nums)[0] ; i++)
    {
        if(minOfmax > new_nums[i])
            minOfmax =  new_nums[i];
    }
    return minOfmax;
}

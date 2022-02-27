#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
void compress2D(int ar[SIZE][SIZE],int rowsize,int colsize);
int main()
{
    int row,col;
    int i,j;
    int data[SIZE][SIZE];
    printf("Enter row and col size:\n");
    scanf("%d %d",&row,&col);
    for(i = 0;i<row;i++)
        for(j = 0;j<col;j++)
            scanf("%d",&data[i][j]);
    compress2D(data,row,col);
    return 0;
}
void compress2D(int ar[SIZE][SIZE],int rowsize,int colsize){
    int i,j,count,bit;

    for(i = 0;i<rowsize;i++)
    {
        //initialize 1st column data since no need to compare
        bit = ar[i][0];
        count = 1;
        for(j = 1;j < colsize;j++)
        {
            if(ar[i][j] == bit)
                ++count;
            else //come here when break streak
            {
                //out put compress matrix without assigning new array
                printf("%d %d ",bit,count);
                //change bit
                //bit = 1 - bit;
                bit = ar[i][j]; //also can but more generic than just bits
                //reset number of bit
               count = 1;
            }

        }
    //if all row same or last few all same
    printf("%d %d",bit,count);
    printf("\n"); //next row
    }

}

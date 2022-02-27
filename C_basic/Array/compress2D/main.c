#include <stdio.h>
#define SIZE 100
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize);
int main()
{
 int data[SIZE][SIZE];
 int i,j;
 int rowSize, colSize;
 printf("Enter the array size (rowSize, colSize): \n");
 scanf("%d %d", &rowSize, &colSize);
 printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
 for (i=0; i<rowSize; i++)
    for (j=0; j<colSize; j++)
        scanf("%d", &data[i][j]);
 printf("compress2D(): \n");
 compress2D(data, rowSize, colSize);
 return 0;
}
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize)
{
 int row,col,count,bit;
 for(row=0;row<rowSize;row++)
 {
    count=1;
    bit = data[row][0]; //first number in each row/sub array set as default for 1st check
    for(col=1;col<colSize;col++) //check with digit in front of bit
    {
        if(data[row][col] == bit)
            {
              count++;
            }
        else
        {
            //output compress matrix without assigning to new array
            printf("not same %d %d ",bit,count);

            bit = 1 - bit; //change bit
            count = 1; //reset count

        }
    }
       printf("%d %d",bit,count); //Here is entire row same
       printf("\n");

 }
}

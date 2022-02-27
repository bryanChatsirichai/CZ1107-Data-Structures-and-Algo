#include <stdio.h>
#define SIZE 10
int minOfMax2D(int ar[][SIZE], int rowSize, int colSize);
int main()
{
   int ar[SIZE][SIZE], rowSize, colSize;
   int i,j,min;

   printf("Enter row size of the 2D array: \n");
   scanf("%d", &rowSize);
   printf("Enter column size of the 2D array: \n");
   scanf("%d", &colSize);
   printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
   for (i=0; i<rowSize; i++)
      for (j=0; j<colSize; j++)
         scanf("%d", &ar[i][j]);
   min=minOfMax2D(ar, rowSize, colSize);
   printf("minOfMax2D(): %d\n", min);
   return 0;
}
int minOfMax2D(int ar[][SIZE], int rowSize, int colSize)
{   int check[rowSize];
    int min,i,j,x,row_max,smallest_max;
    for (i=0; i<rowSize; i++)
    {
    row_max = ar[i][0];
      for (j=0; j<colSize; j++)
      {
          if (row_max < ar[i][j])
          {
            row_max =  ar[i][j];
            check[i] = row_max;
          }
            else
                check[i] = row_max;

      }
    printf("check %d\n",check[i]);
      }
    smallest_max = check[0];
for(x ;x < rowSize; x++)
    {
    printf("last check %d\n",check[x]);
    if(smallest_max > check[x])
    {
       smallest_max = check[x];
    }
    }
    printf("final exit %d\n",smallest_max);
    return smallest_max;

}

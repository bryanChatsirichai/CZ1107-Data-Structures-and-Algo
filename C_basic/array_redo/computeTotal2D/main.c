#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
void total2D(int (*matrix)[4],int size);//matrix pointer to array of 4 integers
int main()
{
    int row,col;
    int arr[SIZE][SIZE];
    printf("Enter the matrix data (%d %d): \n", SIZE, SIZE);
    for(row = 0 ;row < 4; row++)
    {
        for(col = 0; col < 4; col++)
            scanf("%d",&arr[row][col]);
    }
    total2D(arr,SIZE);

    for(row = 0 ;row < 4; row++)
    {
        for(col = 0; col < 4; col++)
            printf("%d ",arr[row][col]);
    putchar('\n');
    }
return 0;
}
void total2D(int (*matrix)[4],int size){
    int row,col;
    int total;
        for(row = 0 ;row < SIZE; row++)
    {
        total = 0;
        for(col = 0; col < (SIZE-1); col++)
            //total+=matrix[row][col];
            total = total + *gh(*(matrix+row)+col);
        matrix[row][3] = total;
    }


}

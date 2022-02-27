#include <stdio.h>
#include <stdlib.h>
void findAvg2D(float matrix[4][4]);
int main()
{
    int row,col;
    float arr[4][4];
    printf("Enter data:\n");
    for(row = 0;row < 4;row++)
    {
        for(col = 0;col< 4;col++)
            scanf("%f",&arr[row][col]);
    }
    findAvg2D(arr);
    printf("findAverage2D(): \n");
   for(row = 0;row < 4;row++)
    {
        for(col = 0;col< 4;col++)
            printf("%.2f ",arr[row][col]);
        printf("\n");

    }
    return 0;
}
void findAvg2D(float matrix[4][4]){
    int row,col;//local to function
    float total,avg;
        //calc 1st 3 number only
        for(row = 0;row < 4 ;row++)
        {
            total = 0.0;//reset after each row
            for(col = 0;col< 3;col++)
                total += matrix[row][col];

            avg = total / 3;
            matrix[row][3] = avg; //last col of each row is avg;


        }

}

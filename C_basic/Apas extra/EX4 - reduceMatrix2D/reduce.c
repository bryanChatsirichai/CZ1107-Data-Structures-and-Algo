#define SIZE 10

void reduceMatrix2D(int ar[][SIZE],int rowSize,int colSize){
    int i,j,total;
    for(j=0;j<colSize;j++) //lower triangle 0
    {
        total = 0;
        i = j + 1;
        for(i;i<rowSize;i++)
        {

            total = total + ar[i][j];
            ar[i][j] = 0;

        }
        ar[j][j] = total + ar[j][j]; //diagonal set to sum of col below diagonal and including
    }
}

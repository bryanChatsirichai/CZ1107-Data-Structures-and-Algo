#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
float absoluteSum1D(int size, float vector[]);
int main()
{
    float vector_ary[SIZE];
    float result;
    int size;

    printf("Enter vector size: \n");
    scanf("%d", &size);
    result = absoluteSum1D(size, vector_ary);
    printf("absoluteSum1D(): %.2f",result);

    return 0;
}
float absoluteSum1D(int size, float vector[]){
    float total=0;
    printf("Enter %d data:\n",size);
    for(int i = 0; i < size;i++)
    {
        scanf("%f",&vector[i]);
        if (vector[i] >= 0)
            total += vector[i];
        else
            total-=vector[i];
    }

    return total;
}

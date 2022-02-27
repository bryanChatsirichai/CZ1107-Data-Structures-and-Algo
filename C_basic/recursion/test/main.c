#include <stdio.h>
#include <stdlib.h>
int recursiveSum(int a[],int size);
int main()
{
    int a[] = {1,2,3,4};
    int sum;
    sum = recursiveSum(a,4);
    printf("%d\n",sum);
    return 0;
}
int recursiveSum(int a[],int size){
    if(size == 1){printf("INSIDE %d\n",a[0]);
        return a[0];}
    else{
       // printf("INSIDE %d\n",a[0]);
        return a[0] + recursiveSum(a+1,size-1);


    }
}

#include <stdio.h>
#include <stdlib.h>
#define SIZE 999
int platform1D(int ar[], int size);
int main()
{
    int size,i,result;
    int platform[SIZE];
    printf("Enter the array size !\n");
    scanf("%d",&size);

    for(i=0;i<size;i++)
        scanf("%d",&platform[i]);
    result = platform1D(platform,size);
    printf("platform1D(): %d\n", result);
    return 0;
}
int platform1D(int ar[],int size){
    int i,j,count_amt,num,max_amt;
    max_amt = 0;
    for(i=0;i<size;i++)
    {
        count_amt = 0;
        num = ar[i];
        for(j=0;j<size;j++)
        {
            if(num == ar[j])
                count_amt+=1;
        }
        //printf("max is %d\n",max_amt);
        if(count_amt > max_amt)
            max_amt = count_amt;
    }

    return max_amt;
}



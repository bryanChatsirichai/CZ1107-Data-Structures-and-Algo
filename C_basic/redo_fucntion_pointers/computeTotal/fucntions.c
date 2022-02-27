#include <stdio.h>
#include <stdlib.h>
void computeTotal(int numOfLines){
    int i,j,total,num,row;
    for(i=0;i<numOfLines;i++)
    {
        total = 0;
        printf("Enter line %d: \n",i+1);
        scanf("%d",&row);
        for(j=0;j<row;j++){
             scanf("%d",&num);
             total = total + num;
        }
       printf("Total : %d\n",total);
    }


}

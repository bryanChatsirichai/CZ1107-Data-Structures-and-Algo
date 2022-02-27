#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int array [3][3] = {{4,23,7},{9,3,5},{40,3,1}};
    int *ptr = array;
    int (*ptr2)[2] = array;
    int i,j;
    int *array_end = (*array+9);
    printf("ptr is %d ptr2 is %d \n",ptr,ptr2);
    printf("%d\n",*(*(ptr2+1)+2));
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            printf("%d ",ptr2[i][j]);


    return 0;
}

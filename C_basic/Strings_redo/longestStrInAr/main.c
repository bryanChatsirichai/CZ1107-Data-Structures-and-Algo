#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 20

char *longestStrInAr(char str [N][40], int size, int *length);
int main()
{

    int size,length,i;
    char str[N][40],*p,*result;
    printf("Enter the array size: \n");
    scanf("%d",&size);
    //getchar();
    for(i=0;i<size;i++)
    {
        printf("Enter string %d\n",i+1);
        getchar();
        fgets(str[i],80,stdin);
        if( p = strchr(str[i],'\n'))
            *p = '\0';
    }
    result = longestStrInAr(str,size,&length);
    printf("longest: %s \nlength: %d\n", result, length);
    return 0;
}
/*
char *longestStrInAr(char str [N][40], int size, int *length){
    int i,j,max,count;
    char *longest;
    max = 0;
    for(i=0;i<size;i++)
    {
        count = 0;
        j = 0;
        while(  *(*(str+i)+j) != '\0')
        {
            count++;
            j++;
        }

        if(count > max){
            max = count;
            longest = str+i;
        }
    }
    *length = max;
    return longest;

    }
*/

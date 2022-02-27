#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 20

char *longestStrInAr(char str [N][40], int size, int *length){
    int i,j,max,count;
    char *longest;
    max = 0;
    for(i=0;i<size;i++)
    {

        count = strlen(*(str+i));
        if(count > max){
            max = count;
            longest = str+i;
        }
    }
    *length = max;
    return longest;

    }

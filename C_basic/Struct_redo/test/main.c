#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct num{
    int num;
    int num2;
};
int main()
{
    struct num *ptr;
    int x;
    printf("enter amount\n");
    scanf("%d",&x);
    ptr = (struct num *)malloc(sizeof(struct num) * x);
    for(int i = 0;i<x;i++)
    {
        (ptr+i)->num= i+5;
        (ptr+i)->num2= i+10;
    }
    for(int i = 0;i<x;i++)
    {
        printf("%d %d\n",(ptr+i)->num,(ptr+i)->num2);
    }

return 0;
    }


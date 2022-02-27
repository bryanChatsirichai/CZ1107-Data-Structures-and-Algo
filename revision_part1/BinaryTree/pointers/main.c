#include <stdio.h>
#include <stdlib.h>
int x = 10;
int y = 20;
void myfunc(int *ptr);
void myfunc2(int **ptr);
int main()
{
    int *ptr,*ptr2ptr;

    ptr2ptr = &x;
    //ptr = &x;
    printf("ouside\n");
    printf("address is %d num is %d\n",ptr2ptr,*ptr2ptr);
    printf("after outside\n");
    //myfunc(ptr);
    myfunc2(&ptr2ptr);
    printf("address is %d num is %d\n",ptr2ptr,*ptr2ptr);

    return 0;
}
void myfunc(int *ptr)
{
    printf("inside func\n");
    printf("address is %d num is %d\n",ptr,*ptr);
    printf("after\n");
    ptr = &y;
    printf("address is %d num is %d\n",ptr,*ptr);
    return;
}
void myfunc2(int **ptr){
    printf("inside func\n");
    printf("address is %d num is %d\n",*ptr,**ptr);
    printf("after\n");
    *ptr = &y;
    printf("address is %d num is %d\n",*ptr,**ptr);
    return;


}

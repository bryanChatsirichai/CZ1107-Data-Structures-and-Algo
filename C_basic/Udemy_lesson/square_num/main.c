#include <stdio.h>
#include <stdlib.h>
void square(int *const ptr); //cant change the address ptr addressing poitning to
int main()
{
    int num;
    printf("Enter a number to square\n");
    scanf("%d",&num);
    square(&num);
    printf("The squared is %d\n",num);
    return 0;
}
void square(int *const ptr)
{
    *ptr = (*ptr) * (*ptr);


}

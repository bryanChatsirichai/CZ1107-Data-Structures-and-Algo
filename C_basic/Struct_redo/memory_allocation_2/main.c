#include <stdio.h>
#include <stdlib.h>
struct example
    {
        int i1;
        double d1;
        char c1;

    } example1;
int main()
{
    printf("size = %I64d bytes\n",sizeof(example1.i1));
    printf("size = %I64d bytes\n",sizeof(example1.d1));
    printf("size = %I64d bytes\n",sizeof(example1.c1));
    //4 +pad(4) + 8 + 1 = 17
    printf("size = %I64d bytes\n",sizeof(example1));
    printf("\n");

    struct example example2[2]; //array
    printf("Address of example2[0].i1 = %d\n", &example2[0].i1);
    printf("Address of example2[0].d1 = %d\n", &example2[0].d1);
    printf("Address of example2[0].c1 = %d\n", &example2[0].c1);
    return 0;
}
/* Address of structure and structure
length must be multiples of t_max.
Here, t_max is the maximum size taken by a member in the structure.*/

/*Following these two rules, you can easily find the size of any structure:
Any data type stores its value at an address that is a multiple of its size.
Any structure takes the size which is a multiple of the maximum bytes taken by a member*/

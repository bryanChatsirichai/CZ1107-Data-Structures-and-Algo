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
    printf("size = %d bytes\n",sizeof(example1));

    struct example example2[2];
    printf("Address of example2[0].i1 = %d\n", &example2[0].i1);
    printf("Address of example2[0].d1 = %d\n", &example2[0].d1);
    printf("Address of example2[0].c1 = %d\n", &example2[0].c1);
    return 0;
}

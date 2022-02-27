#include <stdio.h>
#include <stdlib.h>

extern int var;
int main()

{   int value;
    printf("var is %d\n",var);
    printf("%d\n", value);
    value = increment();
    printf("%d\n", value);
    value = increment();
    printf("%d\n", value);
    value = increment();
    printf("%d\n", value);
    //printf("%d\n", count);



    return 0;
}

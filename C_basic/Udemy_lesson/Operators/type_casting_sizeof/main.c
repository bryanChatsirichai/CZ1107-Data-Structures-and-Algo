#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    x = (int)21.51 + (int)26.99; //21 + 26
    printf("%f\n",x);
    //sizeof() tellls how many bytes occupied by a given type
    //it is a operator not a fucntion
    //evaluated at compile time not at run time
    //can be variable,array name,basic / derive date types
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(float));
    return 0;
}

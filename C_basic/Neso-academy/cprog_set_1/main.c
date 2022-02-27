#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned i = 1; //positive
    int j = -4;
    char c = 255;
    c = c + 10 ;
    printf("%d\n",c);
    //printf not only prints content to screen.
    //It also returns the number of character it successfully prints on creen
    printf(" %d\n", printf("%s","Hello world!"));
    printf("%s\n","Hello");
    printf("%10s\n","Hello");
    printf("%u\n", i + j );
    printf("%d", i + j);
    return 0;
}

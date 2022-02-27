#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    /* C offerers three adjective keywords to modify basic integer types
    short,long and unsigned (can also be used by itself)*/
    /*Type short int or short may be use less storage than int
    saving space when program need more memory and is limited
    Type long use more memory but can have more storage
    Type long long int ,or long long may use more storage than long
    Constant value of type long int is formed by optionally
    appending the letter L(upper or lower) onto end of int constanct :*/
    //Type unsigned int or unsigned use for variable that have non negative value
    /*Keyword signed can be use with any of the signed types to make
    intent explicit.eg short int,signed short int */
    unsigned int d = 234123;
    long double longcar = 1.234e+7L;
    unsigned long int y, integervar = 10000;
    float floatingvar = 331.79;
    double doublevar = 8.44e+11;
    bool boolvar = true;
    char a = 77;
    y = integervar * 100;
    printf("%d\n",y);
    printf("%c" ,a);

}

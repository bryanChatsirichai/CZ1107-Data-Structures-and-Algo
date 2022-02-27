#include <stdio.h>
#include <stdlib.h>
    // int var == auto int var
    //after completion of function local var destroy
    //never initialize auto var  will be random value
    //global var default 0
    /* int var declaration and definition - allocate memory to this var
    external int var Declaration only - no memory allocated  to it.
    use when a file need access variable from another file.*/

extern int a;
int b = 1; // if not found in its scope find here if here dont have go other file
int extern c = 888; //when extern var initiliaze memory allocated
int main()
{
    extern int b;
    printf("%d\n", a);
    printf("%d\n", b);
     printf("%d\n", c);

    return 0;
}

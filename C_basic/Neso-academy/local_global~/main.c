#include <stdio.h>
#include <stdlib.h>

int main()
{
    // int var == auto int var
    //after completion of function local var destroy
    //never initialize auto var  will be random value
    //global var default 0
    /* int var declaration and definition - allocate memory to this var
    external int var Declaration only - no memory allocated  to it.
    use when a file need access variable from another file.*/

    int x ;
    printf("Hello world!\n");
    {
        int x = 10;
        printf("%d\n",x);
    }
    printf("%d\n",x);
    return 0;
}

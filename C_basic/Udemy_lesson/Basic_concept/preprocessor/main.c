/*preprocessor statement are identified by #
first non-space character on the line
run before compiler actually  run
run before any code is generated, object files or executable file */
/*header files define information about some of the functions
that are provided by that file
Header files specify information that the compiler uses to integrate
any predefine functions within a program
Two ways to #include header files in a program
Using angle brackets #include ,stdio.h>
-Tells the preprocessor to look for the file in one or more
standard system directory
Using double quotes #include "stdio.h"
-tells the preprocessor to first look in the current directory*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    //arithmathic operator
    int a = 33 , b = 15;
    int result = 0;
    float c;
    result  = a % b;

    printf("%d\n",result);
    printf("%d\n",a++);
    printf("%d\n",a);
    printf("%d\n",++a);

    //logical operators
    // 0 is false, non-zero is consider True
    bool x = false, y = true,z;
    z = x && y;
    printf("%d\n" ,z);
    z = x || y;
    printf("%d\n" ,z);
    printf("%d\n" ,!z);

    //assignment operator
    // += , -=,...




    return 0;
}

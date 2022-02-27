#include <stdio.h>
#include <stdlib.h>
#define PI 3.14759
#define ADD(x, y) x+y
#define greater(x,y) if(x > y)\
                    printf("%d is greater than %d\n",x,y);\
                    else \
                    printf("%d is greater than %d\n",y,x);


int main()
{

    const int var = 4;
    printf("%.5f\n",PI);
    printf("add is %d\n", ADD(4,3)); //replace by x + y
    printf("add is %d\n", 5* ADD(4,3)); //expansion then evaluation 5*4+3
    greater(5,6)
    printf("Date: %s\n",__DATE__); //pre-define
    printf("Time: %s\n",__TIME__);
    printf("var is %d",var);
    //var = 7; what ever assign to var is permantnent
    printf("var is %d",var);
    return 0;
}

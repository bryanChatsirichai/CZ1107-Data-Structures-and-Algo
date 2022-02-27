#include <stdio.h>
#include <stdlib.h>

struct student{
    char *name;
    int *roll;
    char gender;
    int marks[5];

};

int main()
{
    /*array structure ,each element of the
    array represent a structure variable*/
    struct student std[3];
    int alexRoll = 5;
    std[0].roll = &alexRoll;
    printf("roll number is %d\n",*(std[0].roll));

    return 0;
}

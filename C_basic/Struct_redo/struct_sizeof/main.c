#include <stdio.h>
#include <stdlib.h>
struct student
    {
        char name[20];
        int roll;
        char gender;
        int marks[5];
    } stu1;
int main()
{

    printf("Sum of the size of members = %d bytes\n", sizeof(stu1.name) + sizeof(stu1.roll) + sizeof(stu1.gender) + sizeof(stu1.marks));
    printf("Using sizeof() operator = %d bytes\n",sizeof(stu1));
    printf("Address of member name = %d\n", &stu1.name);
    printf("Address of member roll = %d\n", &stu1.roll);
    printf("Address of member gender = %d\n", &stu1.gender);
    printf("Address of member marks = %d\n", &stu1.marks);
    return 0;
}
/*
char	1	multiple of 1
short	2	multiple of 2
int, float	4	multiple of 4
double, long, * (pointers)	8	multiple of 8
long double	16	multiple of 16 */

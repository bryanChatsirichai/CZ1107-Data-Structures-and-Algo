#include <stdio.h>
#include <stdlib.h>
struct student{
    char name[20];
    int roll;
    char gender;
    int marks[5];


};
int main()
{
    struct student stu[10];
    for(int i = 0; i < 3;i ++)
   {
    printf("Sum of the size of members = %d bytes\n", sizeof(stu[i].name) + sizeof(stu[i].roll) + sizeof(stu[i].gender) + sizeof(stu[i].marks));
    printf("Using sizeof() operator = %d bytes\n",sizeof(stu[i]));
    printf("address of stu%d = %d \n",i,stu+i);
    printf("Address of member name = %d\n", &stu[i].name);
    printf("Address of member roll = %d\n", &stu[i].roll);
    printf("Address of member gender = %d\n", &stu[i].gender);
    printf("Address of member marks = %d\n", &stu[i].marks);
    /*due to padding size will be 48*/
    printf("\n");
   }
    return 0;
}
/*processor reads one word in onecycle.
4 bytes for 32 bits
8 bytes for 64 bits
lower the number of cycles, the better is the performance of the CPU.
DATA TYPES	SIZE (IN BYTES)	ADDRESS
char	1	multiple of 1
short	2	multiple of 2
int, float	4	multiple of 4
double, long, * (pointers)	8	multiple of 8
long double	16	multiple of 16*/
/*Structure padding
may need to insert some extra bytes between the
members of the structure to align the data.
These extra bytes are known as padding.*/

#include <stdio.h>
#include <stdlib.h>
struct student {
    char name[20];
    int roll;
    char gender;
    int marks[5];
};
int main()
{
    struct student stu[2] ={ {"Alex", 43, 'M', {76, 98, 68, 87, 93}},
                            {"Bob", 29, 'M', {23, 38, 67, 47, 73}}};
    /* Pointer to the first element (structure) of the array */
    struct student *ptr_stu; //pointer variable to struct student
    ptr_stu = stu; //stu is a pointer constant to the base address of the array

    /* Pointer to an array of 2 struct student */
    struct student (*ptr2)[2] = &stu;


    /*Note that ptrStu_type1 is a pointer to stu[0]
    whereas ptrStu_type2 is a pointer to the whole array of 10 struct student.
    Adding 1 to ptrStu_type1 would point to stu[1].*/

    printf("Address of structure = %d\n", ptr_stu+0);
    printf("Adress of member `name` = %d\n", &(ptr_stu->name));
    printf("size of each stuct element in the array %d\n",sizeof(stu[0]));
    printf("Total size of the array %d\n",sizeof(stu));
    printf("Increment by 1 results in %d\n", ptr_stu + 1);
    puts("\n");
    printf("Name[1] w.o using ptrStu1 : %s\n",stu[1].name );
    printf("Name[1] using ptrStu1 and * : %s\n", (*(ptr_stu + 1)).name);
    printf("Name[1] using ptrStu1 and -> : %s\n", (ptr_stu+1)->name);
    printf("\n");
    printf("ptr2 = %d\n",ptr2);
    printf("ptr2 + 1 = %d\n",ptr2+1);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct student {
    char name[20];
    int roll;
    char gender;
    int marks[5];
};
struct student add5(struct student p);
int main()
{
    struct student stu1 = {"Alex", 43, 'M', {76, 98, 68, 87, 93}};
    stu1 = add5(stu1);
    printf("Name: %s\n", stu1.name);
    printf("Roll: %d\n", stu1.roll);
    printf("Gender: %c\n", stu1.gender);
    for(int i = 0;i<5;i++)
        printf("marks in subject %d is %d\n",i,stu1.marks[i]);
    return 0;
}
struct student add5(struct student p){
    for(int i = 0; i < 5;i++)
    {
        p.marks[i]+=5;
    }

    return p; //return a struct student variable
};
/*****
type is a structure variable of type struct student.
While returning a structure member the return type has to be that of the member.*****/

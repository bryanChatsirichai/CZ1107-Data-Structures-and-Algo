#include <stdio.h>
#include <stdlib.h>
struct student {
    char name[20];
    int roll;
    char gender;
    int marks[5];
    struct student *next; //pointer to a struct student variable address
};
int main()
{
    struct student stu1 = {"Alex", 43, 'M', {76, 98, 68, 87, 93}, NULL};
    struct student stu2 = { "Max", 33, 'M', {87, 84, 82, 96, 78}, NULL};
    struct student stu3 = { "John", 63, 'M', {31, 34, 85, 37, 72}, NULL};
    stu1.next = &stu2;
    stu2.next = &stu3;
    printf("name is %s\n",stu1.next->name);
    printf("roll is %d\n",(*(stu1.next)).roll);
    printf("Gender: %c\n", stu1.next->gender);
    for(int i = 0; i < 5; i++)
        printf("marks is %d\n",(stu1.next)->marks[i]);
    printf("\n");
    printf("accessing stu3 from stu1\n");
    printf("name is %s\n",stu1.next->next->name);
    printf("roll is %d\n",stu1.next->next->roll);
    printf("Gender: %c\n", stu1.next->next->gender);
    for(int i = 0; i < 5; i++)
        printf("marks is %d\n",stu1.next->next->marks[i]);
    return 0;
}

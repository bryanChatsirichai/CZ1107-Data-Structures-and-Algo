#include <stdio.h>
#include <stdlib.h>
struct student {
    char name[20];
    int roll;
    char gender;
    int marks[5];
};
void display(struct student p[]);
int main()
{
    struct student stds[2] = { {"bryan",100,'M',{2,4,6,8,10}} ,
                                {"sandy",200,'F',{1,3,5,7,9}} };

    //stds is the base address of the array and the first element address as well

    display(stds);
    printf("final row for stds[0] is %d\n",stds[0].roll);
    return 0;
}
void display(struct student p[]){
    for(int i = 0;i < 2;i++)
    {
        printf("Name: %s\n", (p+i)->name);
        printf("Roll: %d\n", (p+i)->roll);
        printf("Gender: %c\n", (*(p+i)).gender);
    for(int j = 0;j < 5;j++)
        printf("marks: %d\n",(p + i)->marks[j]);
    }

    p[0].roll = 999;
    printf("new roll  is %d\n",p[0].roll);
}

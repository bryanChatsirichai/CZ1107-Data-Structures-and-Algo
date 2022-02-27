#include <stdio.h>
#include <stdlib.h>

struct date{
    int date;
    int month;
    int year;
};

struct student{
    char name [20];
    int roll;
    char gender;
    int marks[5];
    struct date birth;

};
int main()
{  //int nums[10] = {1,2,3,4,5};
    struct student std1 = {"bryan",5,'M',{10,20,30,40,50}};
    scanf("%s",std1.name);
    std1.birth.date = 03;
    std1.birth.month  = 02;
    std1.birth.year = 1998;
    printf("%s birth day is %d/%d/%d\n",std1.name,std1.birth.date,std1.birth.month,std1.birth.year);
    return 0;
}

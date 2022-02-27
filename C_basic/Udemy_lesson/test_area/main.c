#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct person_tag{
    char id[20];
    char tel[20];

}INFO;

typedef struct course_tag{
    int year,semester;
    char grade;
}MODULE;


typedef struct student_tag {

    int age;
    char name[20];
    INFO details;
    MODULE CZ1100;

}STUDENTS;

int main()
{

STUDENTS std[10]; //array of struct student
strcpy(std[0].name,"Bryan");
std[0].age = 22;
strcpy(std[0].details.id,"c200180");
strcpy(std[0].details.tel,"81890211");
std[0].CZ1100.year = 2020;
std[0].CZ1100.semester = 1;
std[0].CZ1100.grade = 'A';





printf("student %s age %d, ID %s and tel is %s\n",std[0].name,std[0].age,std[0].details.id,std[0].details.tel);
printf("Took CZ1100 int %d semestral %d and got grade %c\n",std[0].CZ1100.year,std[0].CZ1100.semester,std[0].CZ1100.grade);

}

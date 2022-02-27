#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*Note that the structure struct student
is declared outside main(),
at the very top. This is to ensure that it is
available globally and display() can use it.*/
typedef struct student {
    char name[20];
    int roll;
    char gender;
    int marks[5];
}STD;

void display(char a[],int b,char c,int *marks); //pass individual structure members as arguments.
void display2(STD std); //structure variables can be passed to a function.
void display3(STD *std);
#include <stdio.h>

int main()
{
    STD std1 = {.marks = {34,65,34,78,22} };//structure is defined inside main(), its scope will be limited to main().
    strcpy(std1.name,"Alex");
    std1.roll = 43;
    std1.gender = 'M';
    STD *ptrstd; //pointer to  struct STD
    ptrstd = &std1;

    display(std1.name,std1.roll,std1.gender,std1.marks);
    display2(std1);
    display3(ptrstd);
    printf("final row is %d\n",std1.roll);
    return 0;
}
void display(char a[],int b,char c,int *marks){
    printf("name : %s\n",a);
    printf("roll is %d\n",b);
    printf("gender is %c\n",c);
    for(int i = 0;i< 5;i++)
        printf("marks is %d\n",*(marks+i));
}
void display2(STD std){ //local copy is created
    printf("display2()\n");
    printf("name : %s\n",std.name);
    printf("roll is %d\n",std.roll);
    printf("gender is %c\n",std.gender);
    for(int i = 0;i< 5;i++)
        printf("marks is %d\n",*((std.marks)+i));
        //printf("marks is %d\n",std.marks[i]); //same as above
    std.roll = 10;
    printf("new roll is %d\n",std.roll); //changes here only affect a local copy
    //pass by reference;
}
void display3(STD *std){
    printf("display3()\n");
    printf("name : %s\n",std->name);
    printf("roll is %d\n",std->roll);
    printf("gender is %c\n",(*std).gender);
    for(int i = 0;i< 5;i++)
        //printf("marks is %d\n",std->marks[i]);
        printf("marks is %d\n",(*std).marks[i]); //same as above
    std->roll = 33;
    printf("display 3 new roll is %d\n",std->roll); //changes here affect the std1 directly




}

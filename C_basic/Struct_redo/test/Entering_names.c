#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee{
    char name[10];
    int pay;

};

int main()
{
    int i;

    struct Employee emp_ary[5];
    struct Employee *ptr = emp_ary; //emp_ary is pointer to the base address of the array
    printf("Enter names\n");
    //scanf("%s",ptr->name);
   // printf("%s\n",(*ptr).name);
    for(i=0;i<5;i++)
       scanf("%s",(ptr + i) ->name);
    for(i=0;i<5;i++)
        printf("%s\n",(*(ptr+i)).name);
}


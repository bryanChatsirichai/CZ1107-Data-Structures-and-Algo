#include <stdio.h>
#include <stdlib.h>




typedef struct employee{
    char name[20];
    char hireDate[10];
    float salary;
}EMP;


int main()
{
    EMP emp[3];
    for(int i = 0;i < 3;i++)
    {
        printf("Enter %d name\n",i+1);
        scanf("%s",emp[i].name);
        printf("Enter %d hiredate\n",i+1);
        scanf("%s",(emp + i)->hireDate);
        printf("Enter %d salary\n",i+1);
        scanf("\n");
        //getchar();
        scanf("%f",&(emp[i].salary));
    }
    for(int i = 0;i < 3;i++)
    {
        printf("employee %d %s started on %s and salary is %.2f\n",i+1,emp[i].name,(emp+i)->hireDate,(*(emp+i)).salary);
    }
    return 0;
}

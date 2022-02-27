#include <stdio.h>
#include <stdlib.h>

int main()
{
    int salary,merit;
    char grade;
    printf("Enter the salary\n");
    scanf("%d",&salary);
    printf("Enter the merit\n");
    scanf("%d",&merit);
    if(salary >=500 && salary <= 649)
        grade = 'C';
    if (salary >=600 && salary <= 799)
        {
        grade = 'B';
        if(salary >=600 && salary <= 649)
        {
            if(merit < 10)
                grade = 'C';
        }
        }
    if(salary >=700 && salary <= 899)
        {
            grade = 'A';
            if(merit < 20)
                grade = 'B';
        }
    printf("The grade: %c",grade);




    return 0;
}

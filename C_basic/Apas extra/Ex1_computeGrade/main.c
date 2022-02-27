#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mark,student_ID;
    printf("Enter Student ID:");
    scanf("%d",&student_ID);
    while(student_ID != -1)
    {
        printf("Enter Mark:\n");
        scanf("%d",&mark);
        switch(mark)
        {
        case 75 ... 100:
            printf("A\n");
            break;
        case 65 ... 74:
          printf("B\n");
            break;
        case 55 ... 64:
            printf("C\n");
            break;
        case 45 ... 54:
          printf("D\n");
            break;
        case 0 ... 44:
          printf("F\n");
            break;
        default:
            printf("Error");
            break;

        }

    printf("Enter Student ID:");
    scanf("%d",&student_ID);
    }
    return 0;
}

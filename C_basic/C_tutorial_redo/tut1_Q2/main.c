#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lines,i,total,count,input;
    double avg;

    printf("Enter the number of lines\n");
    scanf("%d",&lines);
    for(i = 0;i< lines;i++)
    {   total = 0;
        count = 0;
        printf("Enter line %d\n",i+1);
        scanf("%d",&input);
        while(input != -1)
        {
            total = total + input;
            count++;
            scanf("%d",&input);
        }
        avg = (float)total / count;
        printf("Average = %.2f\n",avg);


    }


    return 0;
}

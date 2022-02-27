#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lines,nums,total,count,i;
    float avg;
    printf("Enter number of lines: \n");
    scanf("%d", &lines);
    for(i = 1;i<=lines;i++)
    {
         //default
         nums = 0;
        total = 0;
        count = 0;
        printf("Enter line %d (end with -1):\n",i);
        while(nums != -1)
        {   scanf("%d",&nums);
          if(nums != -1)
            {
                total = total + nums;
                count++;
            }

        }
        avg = (float)total / count;
        printf("Average is %.2f\n",avg);

    }
    return 0;
}

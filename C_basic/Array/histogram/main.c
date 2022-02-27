#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void frequency(int [],int total);
void show(int ary[]);
int main()
{
int ary[10];
int total;
printf("Please input the number of random numbers: ");
scanf("%d", &total);
srand(time(NULL));
frequency(ary,total);
show(ary);
}

void frequency(int ary[],int total)
{
    int i,num;
    for (i=0;i<10;i++)
        ary[i]=0; //set array elements to 0
    for(i=0;i<total;i++)
    {
        num=(rand()%100/10);
    ary[num]++;
    }

}

void show(int ary[])
{
    int i,j;


    for(i=0;i<10;i++)
        {
        printf("%2d--%2d |", i*10, i*10+9);
        //printf("%d\n",ary[i]);
        for(j=0;j<ary[i];j++)
            {
             putchar('*');
            }
            printf(" Total count is %d\n",ary[i]);
            printf("\n");
        }
}

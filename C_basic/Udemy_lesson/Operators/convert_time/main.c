#include <stdio.h>
#include <stdlib.h>

int main()
{
   int mins ;
   double years,days;
   printf("Enter number of minutes\n");
   scanf("%d",&mins);
   days =  mins / (60 * 24);
   years = days / 365;
   printf("days %f years %f",days,years);
    return 0;
}

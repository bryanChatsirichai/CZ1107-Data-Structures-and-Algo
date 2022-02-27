#include <stdio.h>
#include <stdlib.h>
#define MONTHS 12
#define YEARS 5
int main()
{

    float rain[YEARS][MONTHS] =
    {// initialize rainfall data for 2011-2015
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    int year,months;
    float  average,total,total_years=0;
    for(year=0;year<YEARS;year++)
    {
        //set default;
        average = 0.0;
        for(months=0,total = 0;months<MONTHS;months++)

        {
            total = total + rain[year][months];

        }
        total_years = total_years + total;

        printf("YEAR \t RAINFALL (inches)\n");
        printf("%d \t %.1f\n",2010 + year,total); //average per year
    }
        printf("\nThe yearly average is %.1f inches\n\n",total_years / YEARS);

        printf("MONTHLY AVERAGES:\n\n");
        printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");

 for (months = 0; months < MONTHS; months++)
     {
         //set default;
        average = 0;
        for (year = 0,total = 0; year < YEARS; year++)
        {
            //printf("rain is %.1f \n",rain[year][months]);
            total = total + rain[year][months];
        }
       // printf("\n");
        average = total / YEARS ; //average of the mths in 5 years
        //Example january average in 5 years

        printf("%4.1f ",average);
     }
    return 0;

}

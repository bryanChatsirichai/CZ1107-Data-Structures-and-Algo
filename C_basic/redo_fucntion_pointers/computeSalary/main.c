#include <stdio.h>
#include <stdlib.h>
void readInput(int *id, int *noOfHours, int *payRate);
double computeSalary1(int noOfHours,int payRate);
void computeSalary2(int noOfHours,int payRate, double *gross_pay);
int main()
{
    int id = -1, hours, pay;
    double gross;
    readInput(&id, &hours, &pay);
    while (id != -1)
    {
        gross = computeSalary1(hours,pay);
        printf("computeSalary1(): ID: %d grossPay %.2f\n",id,gross);
        computeSalary2(hours,pay,&gross);
        printf("computeSalary2(): ID: %d grossPay %.2f\n",id,gross);
        readInput(&id, &hours, &pay);
    }
    return 0;
}
void readInput(int *id, int *noOfHours, int *payRate)
{
    printf("Enter ID (-1 to end):\n");
    scanf("%d",id);
    printf("Enter number of hours:\n");
    scanf("%d",noOfHours);
    printf("Enter hourly pay rate:\n");
    scanf("%d",payRate);

}

double computeSalary1(int noOfHours,int payRate)
{
    double gross;
    int base,ot;
    if (noOfHours < 160)
    {
        base = noOfHours * payRate;
        gross = base;
    }
    else
    {
        base = 160 * payRate;
        ot = (noOfHours - 160) * payRate *1.5;
        gross = base + ot;
    }
        return gross;
}
void computeSalary2(int noOfHours,int payRate, double *gross_pay)
{
    double gross;
    int base,ot;
    if (noOfHours < 160)
    {
        base = noOfHours * payRate;
        gross = base;
    }
    else
    {
        base = 160 * payRate;
        ot = (noOfHours - 160) * payRate *1.5;
        gross = base + ot;
    }
    *gross_pay = gross;
}

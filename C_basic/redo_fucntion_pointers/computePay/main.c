#include <stdio.h>
#include <stdlib.h>
double computePay1(int num_hours,int pay_rate);
void computePay2(int num_hours,int pay_rate,double *gross_pay);
int main()
{
int hours,pay;
double grossPay,grossPay2;
  printf("Enter number of hours: \n");
  scanf("%d", &hours);
  printf("Enter hourly pay rate: \n");
  scanf("%d", &pay);
  grossPay = computePay1(hours,pay);
  printf("computePay1(): %.2f\n", grossPay);
  computePay2(hours,pay,&grossPay2);
  printf("computePay1(): %.2f\n", grossPay2);



    return 0;
}
double computePay1(int num_hours,int pay_rate)
{
    double base,ot,gross;
    if (num_hours < 160)
    {
        base = num_hours * pay_rate;
        gross = base;
    }
    else if (num_hours > 160)
    {
        base = 160 * pay_rate;
        ot = (pay_rate * 1.5) * (num_hours - 160);
        gross = base + ot;
    }
    return gross;
}

void computePay2(int num_hours,int pay_rate,double *gross_pay)
{
       double base,ot,gross;
    if (num_hours < 160)
    {
        base = num_hours * pay_rate;
        gross = base;
    }
    else if (num_hours > 160)
    {
        base = 160 * pay_rate;
        ot = (pay_rate * 1.5) * (num_hours - 160);
        gross = base + ot;
    }

    *gross_pay = gross;

}

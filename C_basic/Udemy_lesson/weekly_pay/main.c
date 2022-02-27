#include <stdio.h>
#include <stdlib.h>
#define TAXRATE_300 0.15
#define TAXRATE_150 0.20
#define  TAXRATE_REST 0.25
int main()
{
    double pay_rate,taxes,gross,net;
    int hours;
    printf("Enter pay rate\n");
    scanf("%lf",&pay_rate);
    printf("Enter the amount of hours\n");
    scanf("%d",&hours);
    if (hours <= 40)
    {
        gross = pay_rate * hours;
    }
    else
    {
        gross = (40 * pay_rate) + (hours - 40) * (pay_rate * 1.5);

    }
    if (gross < 300)
        taxes = gross * TAXRATE_300;
    else if (gross > 300 && gross <= 450)
    {
        taxes = 300 * TAXRATE_300;
        taxes = taxes + (gross - 300) * TAXRATE_150;
    }

    else
    {
        taxes = 300 * TAXRATE_300;
        taxes = taxes + (150 * TAXRATE_150);
        taxes = taxes + (gross-450) * TAXRATE_REST;
    }

    net = gross - taxes;
    printf("you eard %.2f and tax is %.2f\n",gross,taxes);
    printf("therefore net pay is %.2f\n",net);

    return 0;
}

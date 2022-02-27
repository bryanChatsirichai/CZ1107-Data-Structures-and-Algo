#include <stdio.h>
#include <stdlib.h>

int main()
{
   double a,b;
   char option;
   printf("Enter expression\n");
   scanf("%lf %c %lf",&a,&option,&b);
   switch(option)
   {
   case '+':
    printf("add is %.2f\n",a+b);
    break;
   case '-':
    printf("minus is %.2f\n",a-b);
    break;
   case '*':
    printf("multiply is %.2f\n",a*b);
    break;
    case '/':
    printf("divide is %.2f\n",a/b);
    break;
    default:
        printf("thanks\n");
   }

   return 0;
}


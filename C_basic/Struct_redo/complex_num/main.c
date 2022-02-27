#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{

    double real;
    double imag;

}Complex;

Complex addition(Complex c1, Complex c2);
 Complex mul(Complex c1, Complex c2);
Complex subtraction(Complex *c1, Complex *c2);
Complex division(Complex *c1, Complex *c2);
int main()
{
 /*** variable ***/
    int choice;
    Complex input1,input2,result;
/*** main body***/
   printf("Complex number operations: \n");
   printf("1 - addition \n");
   printf("2 - subtraction \n");
   printf("3 - multiplication \n");
   printf("4 - division \n");
   printf("5 - quit \n");
do{
    printf("Enter your choice: \n");
    scanf("%d",&choice);
    if(choice == 5)
        return 0; //exit main function


    printf("Enter Complex Number 1: \n");
    scanf("%lf %lf",&input1.real,&input1.imag);
    printf("Enter Complex Number 2: \n");
    scanf("%lf %lf",&input2.real,&input2.imag);
    switch(choice){
    case 1:
    result = addition(input1,input2);
    break;
    case 2:
    result = subtraction(&input1,&input2);
    break;
    case 3:
    result = mul(input1,input2);
    break;
    case 4:
        result = division(&input1,&input2);
    break;

    }
    printf("Complex(): real %.2f imag %.2f\n",result.real,result.imag);

}while(choice < 5);
    return 0;
}
Complex addition(Complex c1, Complex c2){
//return a Complex data type variable
Complex temp; //local variable of complex type to this function only
temp.real = c1.real + c2.real;
temp.imag = c1.imag + c2.imag;
return temp;
}
Complex mul(Complex c1, Complex c2)
{
    Complex temp;

    temp.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    temp.imag = (c1.real * c2.imag) + (c1.imag * c2.real);

    return temp;
}
Complex subtraction(Complex *c1, Complex *c2){
//return a Complex data type variable
Complex temp; //local variable of complex type to this function only
temp.real = c1->real - c2->real;
temp.imag = (*c1).imag - c2->imag;
return temp;
}
Complex division(Complex *c1, Complex *c2){
Complex temp; //local variable of complex type to this function only
temp.real = ( (c1->real * c2->real) + (c1->imag * c2->imag) ) / (pow(c2->real,2) + pow(c2->imag,2) );
temp.imag = -1 * (((c1->real * c2->imag) - (c1->imag * c2->real)) / (pow(c2->real, 2) + pow(c2->imag, 2)));
/***
(a+bi)    (ac + bd)   -1 * (ad - bc)i
------ == --------- + ----------------   -1 was factor out from the imaginary side
(c+di)     c^2 + d^2    c^2 + d^2
***/
return temp;
}

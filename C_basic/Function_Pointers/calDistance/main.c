#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void inputXY(double *, double *, double *, double *);
void reference(double x1,double y1,double x2,double y2,double *dist);
void outputdist(double dist );
double value(double x1,double y1,double x2,double y2);

int main()
{
    double x1, y1, x2, y2, distance;
   printf("calReference()\n");
   inputXY(&x1, &y1, &x2, &y2); // call by reference
   reference(x1,y1,x2,y2,&distance);
   outputdist(distance);
   printf("calValue()\n");
   inputXY(&x1, &y1, &x2, &y2); // call by reference
   distance = value(x1,y1,x2,y2);
   outputdist(distance);




    return 0;
}
void inputXY(double *x1, double *y1, double *x2, double *y2)
{    //double *z1,z2;
    printf("nput x1 y1 x2 y2: ");
    scanf("%lf %lf %lf %lf", x1, y1, x2, y2);

}
void reference(double x1,double y1,double x2,double y2,double *dist)
{
    double z1,z2;
        z1 = x2 - x1;
        z2 = y2 - y1;
        z1 = z1 * z1;
        z2 = z2 * z2;
        *dist = sqrt(z1+z2);
}

double value(double x1,double y1,double x2,double y2)
{
    double z1,z2;
        z1 = x2 - x1;
        z2 = y2 - y1;
        z1 = z1 * z1;
        z2 = z2 * z2;
        return sqrt(z1+z2);
}


void outputdist(double dist)
{
    printf("The distance is %1f\n",dist);
}

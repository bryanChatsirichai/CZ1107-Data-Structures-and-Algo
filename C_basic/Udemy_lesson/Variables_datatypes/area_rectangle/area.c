#include <stdio.h>
#include <stdlib.h>

int main()
{
    float area,parameter,width,height;

    printf("Enter width and height\n");
    scanf("%f %f",&width,&height);
    parameter = 2 * (width + height);
    printf("perameter is %f\n",parameter);
    area = width * height;
    printf("area is %f\n ",area);
   float z = 4.0f /9.0f;
    printf("z is %f",z);
    return 0;
}

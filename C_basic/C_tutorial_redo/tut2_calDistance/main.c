#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float calDistance1(float x1,float y1,float x2,float y2);
void calDistance12(float x1,float y1,float x2,float y2,float *result);
int main()
{
    float x1,y1,x2,y2;
    float result;
    printf("Enter x1 ,y1\n");
    scanf("%f %f",&x1,&y1);
    printf("Enter x2 ,y2\n");
    scanf("%f %f",&x2,&y2);
    printf("calDistance1() = %.2f",calDistance1(x1,y1,x2,y2));
    calDistance12(x1,y1,x2,y2,&result);
     printf("calDistance2() = %.2f",result);

    return 0;
}
float calDistance1(float x1,float y1,float x2,float y2){
        float distance,x_square,y_square;
        x_square = (x2 - x1)*(x2-x1);
        y_square = (y2 - y1) * (y2 - y1);
        distance = sqrt(x_square + y_square);

        return distance;


}

void calDistance12(float x1,float y1,float x2,float y2,float *result){
            float distance,x_square,y_square;
        x_square = (x2 - x1)*(x2-x1);
        y_square = (y2 - y1) * (y2 - y1);
        distance = sqrt(x_square + y_square);
        *result = distance;


}

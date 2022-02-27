#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int x1,y1;
    int x2,y2;
    float  distance;
    printf("Enter first point x1 y1:\n");
    scanf("%d %d",&x1,&y1);
    printf("Enter first point x2 y2:\n");
    scanf("%d %d",&x2,&y2);
    distance = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    printf("The distance is %.2f",distance);
    return 0;
}

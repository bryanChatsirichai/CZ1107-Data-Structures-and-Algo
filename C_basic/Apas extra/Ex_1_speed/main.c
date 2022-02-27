#include <stdio.h>
#include <stdlib.h>

int main()
{
    double dist,time,speed;
    printf("Enter the distance (in km):\n");
    scanf("%lf",&dist);
    printf("Enter time (in sec):\n");
    scanf("%lf",&time);
    speed = dist/time;
    printf("The speed is %.2f km/sec",speed);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define CARRIER 1
#define SUBMARINE 2
typedef struct {
    int shipClass;
    char name[20];
    int speed;
    int crew;
}warShip;
void printShip(warShip ship);
int main()
{
    int i;
    warShip ship[2]; //array of structures
    for(i = 0;i < 2;i++)
    {
        printf("Enter ship %d details\n",i+1);
        printf("Enter class type 1 or 2\n");
        scanf("%d",&ship[i].shipClass);
        printf("Enter ship name\n");
        scanf("%s",(*(ship+i)).name); //eqivalent to index notation
        printf("Enter ship speed\n");
        scanf("%d",&(ship[i].speed));
        printf("Enter crew size\n");
        scanf("%d",&ship[i].crew);
    }

    for(i = 0;i<2;i++)
    {
        printShip(ship[i]); //every iteration pass in 1 element of stuct warship
    }

    return 0;
}
void printShip(warShip ship){ //func takes in struc variable and print details
    if(ship.shipClass == 1)
        printf("Carrier:\n");
    else
        printf("Submarine:\n");

    printf("\tname = %s\n",ship.name);
    printf("\tspeed = %d\n",ship.speed);
    printf("\tcrew = %d\n",ship.crew);

}

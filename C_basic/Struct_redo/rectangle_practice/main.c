#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*** A structure called Point is defined to represent
 a point in 2D which is given as follows:***/
typedef struct {
   double x;
   double y;
} Point;

/***Another structure called Rectangle is defined as follows:***/
typedef struct {
   Point topLeft;    // top left point of rectangle
   Point botRight;   // bottom right point of rectangle
}Rectangle;


Rectangle getRect(); //Structure as a Function Return
double findArea(Rectangle rect);
void printRect(Rectangle r);
int main()
{   /***Variables***/
    Rectangle rect; //rect is a variable of structure Rectangle
    int choice;

   /***Main body***/
   printf("Select one of the following options:\n");
   printf("1: getRect()\n");
   printf("2: findArea()\n");
   printf("3: printRect()\n");
   printf("4: exit()\n");
    do{
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        switch(choice){

    case 1:
        printf("getRect(): \n");
        rect = getRect();
        break;

    case 2:
        printf("findArea(): %.2f\n",findArea(rect));
        break;

    case 3:
        printRect(rect);
        break;

    default:
        break;
        }

    }while(choice < 4);
    return 0;
}
/***Functions***/
Rectangle getRect(){
    Rectangle func_rect;
    printf("Enter top left point: \n");
    scanf("%lf %lf",&func_rect.topLeft.x,&func_rect.topLeft.y);
    printf("Enter bottom right point: \n");
    scanf("%lf %lf",&func_rect.botRight.x,&func_rect.botRight.y);

    return func_rect;
}
double findArea(Rectangle rect){
    double area;
    double diff_x,diff_y;
    //get absolute value of difference
    diff_x = fabs(rect.topLeft.x - rect.botRight.x);
    diff_y = fabs(rect.topLeft.y - rect.botRight.y);
    area = diff_x *diff_y;
    return area;

}
void printRect(Rectangle r){
    printf("Top left point: %.2f %.2f\n",r.topLeft.x,r.topLeft.y);
    printf("Bottom right point: %.2f %.2f\n",r.botRight.x,r.botRight.y);

}

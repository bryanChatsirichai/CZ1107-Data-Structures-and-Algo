#include <stdio.h>
#include <stdlib.h>
struct rectangle{
    int length;
    int breadth;
};

struct rectangle *myfunc(int length,int breadth);
int main()
{
    struct rectangle *ptr; //pointer to struct rectangle
    struct rectangle *ptr_rectangle1 = myfunc(5,4);
    printf("Length of rectangle = %d units\n", ptr_rectangle1->length);
    printf("Breadth of rectangle = %d units\n", ptr_rectangle1->breadth);
    printf("Area of rectangle = %d square units\n", ptr_rectangle1->length * ptr_rectangle1->breadth);
    return 0;
}
struct rectangle *myfunc(int length,int breadth){
    struct rectangle *ptr; //pointer to struct rectangle

    ptr =(struct rectangle*) malloc(sizeof(struct rectangle));
    //typecast to pointer to struct rectangle

    ptr->length = length;
    (*ptr).breadth = breadth;

return ptr;
};

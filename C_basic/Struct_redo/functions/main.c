#include <stdio.h>
#include <stdlib.h>
void message(int i);
struct example{
    int i;
    int *num;
    void (*ptrMessage)(int i); //pointer to Message function that takes in 1 integer
    //function ptr points to does not return anything thus void.



};
int main()
{
    int  number  = 10;
    struct example eg1 = {6 , &number ,&message};


    printf("numptr is %d\n",*(eg1.num));
    (eg1.ptrMessage)(eg1.i);
    return 0;
}
void message(int i){

 printf("Hello, I'm a member of a structure. This structure also has an integer with value %d", i);


}

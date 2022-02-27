#include <stdio.h>
#include <stdlib.h>
struct example{
    int i;
    void(*ptrFunc)(int i);



};
void message(int i);
int main()
{
    struct example eg1 = {6, &message};
    //eg1.ptrFunc = &message; //&address of func not really needed
    (*(eg1.ptrFunc))(eg1.i); //* not needed
    eg1.ptrFunc(8);
/* A function’s name can also be used to get functions’ address.
For example, in the below program,
we have removed address operator ‘&’ in assignment.
We have also changed function call by removing *,
the program still works.*/
    return 0;
}
void message(int i){
    printf("Hello, I'm a member of a structure. This structure also has an integer with value %d\n", i);

}

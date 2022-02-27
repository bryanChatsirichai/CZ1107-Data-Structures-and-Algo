#include <stdio.h>
#include <stdlib.h>
struct nameTag{
    char fname[20];
    char lname[20];
};
struct nameTag getname(); //function return struct nameTage
int main()
{
    struct nameTag name;
    name = getname();
    printf("your name is %s %s\n",name.fname,name.lname);

    return 0;
}

struct nameTag getname(){
    struct nameTag funcName; //make struct variable funcname local to getname function
    printf("Enter fname\n");
    scanf("%s",funcName.fname);
    printf("Enter lname\n");
    scanf("%s",funcName.lname);
    return funcName;

};

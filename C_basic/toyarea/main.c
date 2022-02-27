#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char name[10],temp[] = "#",*p;
   int result;
   //gets(name);
   fgets(name, 10, stdin);
    if (p=strchr(name,'\n'))
        *p = '\0';
    result = strcmp(name,temp);
    printf("result %d\n",result);
    printf("result %s\n",name);
    return 0;
}

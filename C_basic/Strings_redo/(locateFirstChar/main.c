#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int locateFirstChar(char *str, char ch);
int main()
{
   char str[40], ch, *p;
    printf("Enter a string: \n");
    fgets(str,80,stdin);
    if (p = strchr(str,'\n'))
        *p = '\0';
    printf("Enter the target character: \n");
    ch = getchar();
    printf("locateFirstChar(): %d\n",locateFirstChar(str,ch));

    return 0;
}
int locateFirstChar(char *str, char ch){
    int i = 0;
    int count = 0;
    while(*(str+count) != '\0') //inititally pointed to index 0 of string array
    {
        if(str[count] == ch)
        {
            printf("%c\n",i);

            return count;
        }
        count++;


    }

    return -1;

}

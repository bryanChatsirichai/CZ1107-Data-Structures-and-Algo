#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void maxCharToFront(char *str);
int main()
{
    char str[80];
    char *p;
    printf("Enter a string\n");
    fgets(str,80,stdin);
    if(p = strchr(str,'\n'))
        *p = '\0';
    maxCharToFront(str);
    puts(str);

    return 0;
}
void maxCharToFront(char *str){
    int index,i=0;
    char temp,max_char;
    index = 0;

    max_char = str[0]; //set default first to be biggest
    while(*(str+index) != '\0') //get max char index
    {
        if(max_char < str[index]){
            i = index;  //i will be set to the index if condition met
            max_char = str[i];
        }
        index++;
    }
    temp = str[0];
    str[0] = str[i];
    str[i] = temp;
    //printf("%s\n",str);
}

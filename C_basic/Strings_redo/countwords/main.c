#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int countWords(char *s);
int main()
{
    char str[50];
    char *p;
    printf("Enter the string: \n");
    fgets(str,50,stdin);
    if (p = strchr(str,'\n')) //strchr return the address of the index at \n
       *p = '\0';
    printf("countWords(): %d", countWords(str));
    return 0;
}
int countWords(char *s){
    int count,max,i;
    count = 0;
    max = 0;
    i = 0;
    printf("strlen %d\n",strlen(s));
    for(i;i<strlen(s)+1;i++) //strlen does not count \0 thus add 1 to index to check it
    {

        if(s[i] == '\n' || s[i]  == '\t' || s[i] == ' ' || s[i] == '\0') //any whitespace add 1 count or end of string
            count+=1;

        printf("%d\n",i);
    }

return count; //cause WHILE LOOP ends at '\0'

}

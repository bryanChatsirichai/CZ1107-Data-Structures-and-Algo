#include <stdio.h>
#include <string.h>
int longWordLength(char *s);
int main()
{
    char str[80];
    char *p;
    printf("Enter a string: \n");
    fgets(str,80,stdin);
    if(p = strchr(str,'\n'))
        *p = '\0';
    printf("longWordLength(): %d\n", longWordLength(str));
    return 0;
}
int longWordLength(char *s){
    int i,count,longest;
    count = 0;
    longest=0;
     for(i=0;i<strlen(s);i++) //stop before \0
    {
       if( ((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >='A') && (s[i] <= 'Z')) )
        {
            count+=1;
        }
       else
            count = 0; //reset when encounter breaks

        if(count > longest) //update after every iteration before repeating next loop
            longest = count;


    }
    return longest;
}


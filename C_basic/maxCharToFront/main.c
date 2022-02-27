#include <stdio.h>
#include <string.h>
void maxCharToFront(char *str);
int main()
{
 char str[80], *p;

 printf("Enter a string: \n");
 fgets(str, 80, stdin);
 if (p=strchr(str,'\n')) *p = '\0';
 printf("maxCharToFront(): ");
 maxCharToFront(str);
 puts(str);
 return 0;
}
void maxCharToFront(char *str)
{
 int i=0,size,pos=0;
 char big;
 big = str[0];
 size = strlen(str);
 for(i;i<size;i++)
    {
        if(big < str[i])
        {
            pos = i;
        big = str[pos];
        }
    }
    printf("pos num is %d word is %c\n",pos,str[pos]);
    pos;
    for(pos;pos>0;pos--)
        str[pos] = str[pos-1];

    str[0] = big;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insertChar(char *str1, char *str2, char ch);
int main()
{
    char a[80], b[80];
    char ch, *p;
    printf("Enter a sting: \n");
    fgets(a, 80,stdin);
    if (p = strchr(a,'\n'))
        *p = '\0';
    printf("Enter a character to be inserted: \n");
    ch = getchar();
    insertChar(a,b,ch);
    printf("insertChar(): ");
    puts(b);
    return 0;
}
void insertChar(char *str1, char *str2, char ch)
{
 int count=0;
 while(*str1 != '\0'){
 int count=1;

 while(*str1 != '\0')
 {
     *str2++ = *str1++;
     ++count;

     if(count == 4)
     {
         *str2++ = ch;
         count = 1;
     }
 }

 *str2 = '\0';
}
}

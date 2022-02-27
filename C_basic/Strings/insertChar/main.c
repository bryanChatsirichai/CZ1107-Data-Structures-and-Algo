#include <stdio.h>
#include <string.h>
void insertChar(char *str1, char *str2, char ch);
int main()
{
 char a[80],b[80];
 char ch, *p;

 printf("Enter a string: \n");
 fgets(a, 80, stdin);
 if (p=strchr(a,'\n')) *p = '\0';
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
 while(*str1) {// end at str1 reaches '\0'
    *(str2++) = *(str1++); //both str1 and str2 assign then postfix increment
    count++;
    if(count==3)
    {
        *str2++ = ch; //only str2 increment here
        count = 0;
    }
 }
 //exit when str1 increment till null
//The latest str1 is pointing to 'nothing' after exit loop due to post increment
 *str2 = '\0' ; //to end string
}


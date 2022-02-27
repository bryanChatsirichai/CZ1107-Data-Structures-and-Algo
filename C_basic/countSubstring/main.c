#include <stdio.h>
#include <string.h>
#define INIT_VALUE -1

int countSubstring(char str[], char substr[]);
int main()
{
 char str[80], substr[80], *p;
 int result=INIT_VALUE;

 printf("Enter the string: \n");
 fgets(str, 80, stdin);
 if (p=strchr(str,'\n')) *p = '\0';
    printf("Enter the substring: \n");
 fgets(substr, 80, stdin);
 if (p=strchr(substr,'\n'))
    *p = '\0';
 result = countSubstring(str, substr);
 printf("countSubstring(): %d\n", result);
 return 0;
}
int countSubstring(char str[], char substr[])
{
 int i=0,j=0,count=0;
 for(i;str[i] != '\0';i++)
 {
     if(str[i]==substr[j])
     {
         j++;
        if(substr[j]=='\0')
        {

        count++;

        j=0;
        }
     }
     else
    {
        j=0;
        printf("i count %d\n",i);
        printf("j count %d\n",j);
       if(substr[j]==str[i])
        {
          // printf("j char is %c, i char is %c\n",substr[j],str[i]);
            i--;
        }
         printf("after i count %d\n",i);
    }
 }
 return count;
 }

#include <stdio.h>
#include <string.h>
#define INIT_VALUE 999
int findSubstring(char *str, char *substr);
int main()
{
 char str[40], substr[40], *p;
 int result = INIT_VALUE;
 printf("Enter the string: \n");
 fgets(str, 80, stdin);
 if (p=strchr(str,'\n'))
    *p = '\0';
printf("Enter the substring: \n");
fgets(substr, 80, stdin);
 if (p=strchr(substr,'\n')) *p = '\0';
    result = findSubstring(str, substr);
 if (result == 1)
    printf("findSubstring(): Is a substring\n");
 else if ( result == 0)
    printf("findSubstring(): Not a substring\n");
 else
    printf("findSubstring(): An error\n");
 return 0;
}
int findSubstring(char *str, char *substr)
{
 int i=0,j=0,result;
 for(i,j; str[i]!= '\0' && substr[j] != '\0' ;i++) //i never reset
 {
    printf("str word is %c substr word is %c i = %d j = %d\n",str[i],substr[j],i ,i);
    if (str[i] == substr[j])
        {printf("j count %d\n",j);
            j++;//if substr then will go all the way to null

        }
    else
    {
        j=0;//reset to test substring
        if(substr[j]==str[i])
        {
            i--;
        }

    }
 }
 if(j>0)
    return 1;
 else
    return 0 ;
}

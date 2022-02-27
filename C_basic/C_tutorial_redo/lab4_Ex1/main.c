#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void *sweepace1(char *str);
void *sweepace2(char *str);
int main()
{
    char str1[80], *p;
    char str2[80];
    printf("Enter the string:\n");
    fgets(str1,80,stdin);
    if(p = strchr(str1,'\n'))
        *p = '\0';
    strcpy(str2,str1);
    printf("sweepSpace1(): %s\n",sweepace1(str1));
    printf("sweepSpace2(): %s\n",sweepace2(str2));
    return 0;
}
void *sweepace1(char *str){
    int str_len,i,index,check;
    index = 0;
    str_len = strlen(str);
    while( str[i] != '\0')
    {
        check = isspace(str[i]);
        if(check == 0) //not space then ass
        {
            str[index] = str[i];
            index++;
        }
        i++;
    }
    str[index] = '\0'; //stop before Null thus need add null behind
    return str;
}
void *sweepace2(char *str){
    int str_len,i,index,check;
    index = 0;
    str_len = strlen(str);
    for(i = 0;i< str_len;i++) //stop before Null
    {
        if(str[i] != ' ')
        {
            *(str+index) = str[i];
             index++;
        }
    }
    *(str+index) = '\0'; //stop before Null thus need add null behind
    return str;
}

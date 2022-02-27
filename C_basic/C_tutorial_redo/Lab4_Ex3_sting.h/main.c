#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int palindrome(char *str);
int main()
{
    char str[80], *p;
    int result;
    printf("Enter a string:\n");
    fgets(str,80,stdin);
    if (p = strchr(str,'\n'))
        *p = '\0';
    result = palindrome(str);
    if (result == 1)
        printf("palindrome(): A palindrome\n");
    else if (result == 0)
        printf("palindrome(): Not a palindrome\n");
   else
        printf("An error\n");
    return 0;
}
int palindrome(char *str){
   int  result;
   int str_len,i,index;
   char str2[80];
    str_len = strlen(str);
    index  = str_len - 1; ///string index n-1; exclude Null
     //index from end of string
    i = 0;
    for(index ; index>=0; index--) //make a new str2 with reverse of str
    {
        str2[i] = str[index];
        i++;
    }
    str2[i] = '\0';
    printf("str1 is %s\n",str);
    printf("str2 is %s\n",str2);


    result = strcmp(str,str2);
    if(result == 0)
        return 1; //palidrome
    else
        return 0; //fail

}

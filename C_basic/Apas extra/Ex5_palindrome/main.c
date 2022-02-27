#include <stdio.h>
#include <stdlib.h>
int palindrome(char *str);
int main()
{
    int result = 0;
    char str[80];
    printf("Enter a string: \n");
    gets(str); // no \n appended
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
   int str_len,i,j,index;
   char str2[80];
   i = 0;
   str_len = 0;
   while( str[i] != '\0')
       i++; //get total len of str
    str_len = i;
    index  = str_len - 1; ///string index n-1; exclude Null
     //index from end of string
    i = 0;
    for(index ; index>=0; index--)
    {
        str2[i] = str[index];
        i++;
    }
    str2[i] = '\0';
    i = 0;
    while(str[i] != '\0' && str2[i] != '\0')
    {
        if(str[i] == str2[i])
            i++;
        else //go here mean fail
            return 0;
    }
return 1; //exit here means all same until Null then exit loop
}


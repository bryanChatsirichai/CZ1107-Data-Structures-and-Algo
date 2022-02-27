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
   char *ptr1,*ptr2;
   i = 0;
   str_len = 0;
   while( str[i] != '\0')
       i++; //get total len of str
    str_len = i;
    index  = str_len - 1; ///string index n-1; exclude Null
     //index from end of string
    i = 0;
    //pointers variable
    //ptr1 = str + i //0 position index
    //ptr2 = str + index //last index before Null
    ptr1 = str + 0; //0 position index
    ptr2 = str + index;//+ index //last index before Null
    //not increasing i and index wont change here directly
    while(ptr1 < ptr2) // address in ptr1 < address of ptr2
    {
        printf("i is %d\n",i);
        printf("index is %d\n",index);
        printf("char ptr 1 is %c\n",*ptr1);
         printf("char ptr 2 is %c\n",*ptr2);
        if(*ptr1 != *ptr2) //their character at opposite ends of the strings different
            {
                printf("fail\n");
                result = 0;
               break;
            }
        else
        {
           ptr1++;
           ptr2--;
            result = 1; //will be 1 when char same but will change to 0 if fail once
        }
    }//loop will break when ptr1 > ptr2 eg
    return result;
}

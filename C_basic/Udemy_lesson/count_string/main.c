#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int count_str(char const *str); //char cannot be change
int main()
{
    char string1[50];
    char *p;
    printf("Enter a string\n");
    fgets(string1,50,stdin);
    if(p = strchr(string1,'\n'))
        *p = '\0';
    printf("string length is %d\n",count_str(string1));
    return 0;
}
int count_str(char const *str){
    int count = 0;
    char const *last_address = str;
    char const *first_address = str;
    while(*last_address != '\0')
        {
            last_address++;
        }
    //last_is the addrress of null first is address of forst element
    //difference is the amount of char
    count = (last_address - first_address) / sizeof(str[0]); //for char every char move by 1 bits unlike int which is 4
    return count; //not including the null

}






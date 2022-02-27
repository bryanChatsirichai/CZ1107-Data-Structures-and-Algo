#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processString(char *str,int *totalVowels,int *totalDigits);
int main()
{
    char str[50],*p;
    int vowels = 0,digits = 0;
    printf("Enter the sting: !\n");
    fgets(str,80,stdin);
    if(p = strchr(str,'\n'))
        *p = '\0';
    processString(str,&vowels,&digits);
    printf("Total vowels = %d\n", vowels);
 printf("Total digits = %d\n", digits);
    return 0;
}
void processString(char *str,int *totalVowels,int *totalDigits){
    int i;
    while(*str != '\0' ){
        if (*str == 65 || *str == 69 || *str == 73 || *str == 79 || *str == 85) //uppercase
            *totalVowels+=1;

        else if(*str == 97 || *str == 101 || *str == 105 || *str == 111 || *str == 117) //lowercase
            *totalVowels+=1;

        else if(*str >= 48 && *str<= 57) //digits
            *totalDigits+=1;

        str++;

}
}

#include <stdio.h>
#include <stdlib.h>

int stringcmp(char *str1, char *str2);
int main()
{
    char str1[80], str2[80];
    int result;
    printf("Enter source string:\n");
    gets(str1);
    printf("Enter target string:\n");
    gets(str2);
    result = stringcmp(str1,str2);
    switch(result){
    case 0://equal
    printf("stringcmp():equal\n");
    break;
    case 1: //str1 > str 2
        printf("stringcmp():greater than\n");
            break;
    case -1://str1 < str2
    printf("stringcmp():less than\n");
            break;
    }
    return 0;
}
int stringcmp(char *str1, char *str2){ //think as str1 - str2 to determin positive or negative
    while(1){//loop will continue until hit 1 of the return condition
        if(*str1 == '\0' && *str2 == '\0')
            return 0;
        else if(*str1 == '\0' )
            return -1;
        else if(*str2 == '\0' )
            return 1;

        else if(*str1 > *str2 )
            return 1;
        else if(*str1 < *str2 )
            return -1;
        else
        {
            //move the pointer position to the next address or index
            str1++;
            str2++;
        }

    }
}



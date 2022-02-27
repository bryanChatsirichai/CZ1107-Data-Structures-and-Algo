#include <stdio.h>
#include <stdlib.h>

int countString(char ar[]);
void combine(char *result,char *target,char *source);
int compair(char *str1, char *str2);
int main()
{
    char string1[100];
    char stringcat1[50];
    char stringcat2[50];
    char result[100];
    char str1[50];
    char str2[50];
    printf("Enter a string\n");
    gets(string1);
    printf("Length if string1 is %d\n",countString(string1));
    printf("Enter string target string\n");
    gets(stringcat1);
    printf("Enter string source string\n");
    gets(stringcat2);
    combine(result,stringcat1,stringcat2);
    printf("New string is\n%s\n",result);
    printf("Enter str1\n");
    gets(str1);
    printf("Enter str2\n");
    gets(str2);
    printf("compair result = %d\n",compair(str1,str2));

    return 0;
}
int countString(char ar[]){ //ar is a pointer variable
    int count;
    count = 0;
    while(*ar != '\0'){
        count+=1;
        ar++; //increment

    }
return count;

}
void combine(char *result,char *target,char *source){
    int  i,count;
    //get the index of the null char;
    i = 0;
    while(target[i] != '\0')
        {   printf("index %d\n",i);
            result[i] = target[i];
            i++;
        }
    //append source to target
    while(*source != '\0')
    {
        result[i] = *source;
        source++;
        i++;
    }

    result[i] = '\0'; //last index at null to end string

}
int compair(char *str1, char *str2){
    while(1)
    { //think of str1 - str2
        if(*str1 == '\0' && *str2 == '\0')
            return 0; //same

        else if(*str1 == '\0')
            return 1;

        else if (*str2 == '\0')
            return -1;

        else if (*str1 > *str2)
            return 1;

        else if(*str1 < *str2)
            return -1;
        else
        {   //if they same but not at null go to the next char
            str1++;
            str2++;
        }

    }
}


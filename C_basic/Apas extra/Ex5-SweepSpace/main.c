#include <stdio.h>
#include <stdlib.h>

char *sweepSpace(char *sentence); //return a pointer to char
char *sweepSpace2(char *sentence);
int main()
{
    char str[80];
    printf("Enter the string:\n");
    gets(str); //no newline char is appended for gets
    printf("SweepSpace1() %s\n",sweepSpace(str));
    printf("sweepSpace2(): %s\n", sweepSpace2(str));
    return 0;
}
char *sweepSpace(char *sentence){
    int i = 0,len = 0, j = 0;

    while(sentence[i] != '\0') //get length of string
    {
        len+=1;
        i++;
    }

    for(i = 0;i < len;i++)
    {
        if(sentence[i] != ' ' )
        {
            sentence[j] = sentence[i]; //j will control the position while i will give the char
            j++; //if got add then j is increase else not
        }

    }
    sentence[j] = '\0'; //append Null to end the string
    return sentence;
}
char *sweepSpace2(char *sentence){
        int i = 0,len = 0, j = 0;

    while(*(sentence+i) != '\0') //get length of string
    {
        len+=1;
        i++;
    }

    for(i = 0;i < len;i++)
    {
        if(*(sentence+i) != ' ' )
        {
            *(sentence + j) = *(sentence + i); //j will control the position while i will give the char
            j++; //if got add then j is increase else not
        }

    }
    *(sentence + j) = '\0'; //append Null to end the string
    return sentence;



}

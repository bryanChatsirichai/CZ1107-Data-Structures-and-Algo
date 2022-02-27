#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
void strIntersect(char *str1, char *str2, char *str3);
int main()
{
    char str1[SIZE],str2[SIZE],str3[SIZE];
    printf("Enter str1: \n");
    scanf("%s",str1);
    printf("Enter str2: \n");
    scanf("%s",str2);
    strIntersect(str1,str2,str3);
    if (*str3 == '\0') //no common letters only null char in the char array
       printf("strIntersect(): null string\n");
    else
        printf("strIntersect(): %s\n", str3);
 return 0;
}
void strIntersect(char *str1, char *str2, char *str3){
    char common;
    int i = 0,j = 0;
    int index = 0;
    while ( *(str1 + i) != '\0')
    {
        while( *(str2 + j) != '\0')
        {
            if(*(str1 + i)== *(str2 + j))
            {
                str3[index] = *(str2 + j);
                printf("before exit %c\n",str3[index]);
                index++;
            }
            j++;
        }
        j = 0; //reset j count;
        i++;
    }

    str3[index] = '\0'; //last know index is after end of loop thus add null char

}

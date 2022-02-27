#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char *ptr,*p;
    int n,i;
char word[100] = "helo";
    for(i = 0; i < 100;i++)
    {
        printf("(ptr+%d) = %d and *(ptr+%d) = %c\n" ,i,(word+i),i,*(word+i));
        if(word[i] == '\0')
            printf("null\n");
    }
    printf("the string is\n%s",ptr);
    return 0;
}

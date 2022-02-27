#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char *ptr,*p;
    int n,i;
    printf("Enter the size of a string\n");
    scanf("%d",&n);
    ptr = (char *)calloc(n ,sizeof(char)); //dynamic allocation n*bytyes
    //Thus can store n characters
    //calloc safer as if malloc extra size not use could be garbage value
    printf("Enter a string\n");
     getchar();//clear buffer
        //scanf("\n");
      //scanf("%s",ptr);
    fgets(ptr,n,stdin);
        if(p = strchr(ptr,'\n'))
        *p = '\0'; //remove \n from fgets
    for(i = 0; i < n;i++)
    {
        printf("(ptr+%d) = %d and *(ptr+%d) = %c\n" ,i,(ptr+i),i,*(ptr+i));
    }
    printf("the string is\n%s",ptr);
    free(ptr);
    return 0;
}

#include <stdio.h>
#include <string.h>

int longWordLength(char *s);
int main()
{
    char str[80];
    printf("Enter a string: \n");
    gets(str);
    printf("longWordLength(): %d\n", longWordLength(str));
    return 0;
}
int longWordLength(char *s)
{
int i,count=0,max=0;
  while(*s != '\0')
    {
    if((*s >= 'a') && (*s <= 'z') || (*s >='A') && (*s <= 'Z')){
        printf(" brfotr count is %d\n",count);
       count++;
        printf(" after count is %d\n",count);}

    else
        count = 0; //reset

    if(count>max)
        max = count;

    s++; //iterate true sting

    }

   return max;
}

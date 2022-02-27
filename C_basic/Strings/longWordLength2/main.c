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
int i=0,count=0,max=0;
  for(i;i<strlen(s);i++) //end before NULL
    {
    if((*(s+i) > 64) && (*(s+i)< 91) || (*(s+i) > 96) && (*(s+i) < 123))
    {
        //printf(" brfotr count is %d\n",count);
       count++;
        //printf(" after count is %d\n",count);
    }

    else
        count = 1; //reset

    if(count>max)
        max = count;

    }
    //cause WHILE LOOP ends at '\0' so need to -1
   return max;
}

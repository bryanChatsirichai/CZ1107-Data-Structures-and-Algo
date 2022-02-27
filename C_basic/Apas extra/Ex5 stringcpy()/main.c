#include  <stdio.h>

char *stringncpy(char *s1,char *s2,int n);
int main()
{
     char sourceStr[40], targetStr[40],*target;
     int length;
     printf("Enter the string: \n");
     gets(sourceStr); //no \n;
     printf("Enter the number of characters:\n");
     scanf("%d",&length);
     target = stringncpy(targetStr,sourceStr,length);
     printf("stringcpy(); %s\n",target);
     return 0;


} //copy s2 to s1
char *stringncpy(char *s1,char *s2,int n){
     int i,j;
     i = 0;
     j = 0;
    for(i = 0;i < n;i++) //stop before n index.If exceed will be padded with \0
    {
        if(s2[i] != '\0')
        {
        printf("inside i %d\n",i);
        s1[i] = s2[i];
        }
        else
            {
            printf("break\n");
            break;
        }
    }
printf("outside i %d\n",i);
    s1[i] = '\0'; //append Null at last index
    printf("outside i end %d\n",i);
    //i++;//start at the next index for looping to fill till N
    if(i < n)
    {
    printf("i < n\n");
    j = i;
    for(j; j < n;j++) // if array pointed by s2 if less than n fill up the rest till n with Null
     {
        printf("loop j end %d\n",j);
        s1[j] = '\0';
     }
    }
return s1;

}

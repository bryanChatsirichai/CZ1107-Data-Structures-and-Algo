#include <stdio.h>
#include <string.h>
void processString(char *str, int *totVowels, int *totDigits);
int main()
{
   char str[50], *p;
   int totVowels, totDigits;

   printf("Enter the string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n'))
        *p = '\0'; //end of fgets replace to null
   processString(str, &totVowels, &totDigits);
   printf("Total vowels = %d\n", totVowels);
   printf("Total digits = %d\n", totDigits);
   return 0;
}
void processString(char *str, int *totVowels, int *totDigits)
{

	int digit=0,vowels=0,i=0;

	while(*(str+i)!='\0')
    {
        //char variables are represented by their ASCII integer value
        if(str[i]>='0' && str[i]<='9')
        {
            digit++;
        }
        else if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
        {
            vowels+=1;
        }
        else if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
        {
            vowels+=1;
        }
        i++;
    }

    *totVowels = vowels;
    *totDigits = digit;
}

#include <stdio.h>
#include <string.h>
void maxCharToFront(char *str);
int main()
{
   char str[80], *p;

   printf("Enter a string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0';
   printf("maxCharToFront(): ");
   maxCharToFront(str);
   puts(str);
   return 0;
}
void maxCharToFront(char *str)
{   int count=0,pos=0,i;
    char max, *ptr;
    max = *(str+0); //set as 1st char in str
    while(str[count] != '\0')
    {

        if(max < *(str+count))//same char size no count only less than
        {   if(max != *(str+count))
                max = *(str+count);//Set p to be the biggest char by  ascii
            pos = count; //position set to current  count only when condition met else remain at previous highest
        }
         count++;
    }

    printf("max is %c\n",max);
    printf("pos is %d\n",pos);
    ptr = strchr(str,max); //returns pointer to first intace of char
    printf("ptr is %s\n",ptr);
    printf("char ptr is %c\n",ptr[0]);


    for(i= pos ;  i> 0; i--) // i > 0 as there is nothing to shift up to 0 position
    {

        str[i] = str[i-1]; //shift all char before position up by 1
        printf("pos is %d\n",i);
    }
    str[0] = max;
}


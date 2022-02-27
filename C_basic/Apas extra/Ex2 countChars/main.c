#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dcount,ccount;
    char ch;
    dcount = 0;
    ccount = 0;
    printf("Enter your characters ('#' to end)\n");

    while(ch != '#')
    {
      if(ch >= 48 && ch <= 57) //0~9 ascii
            dcount+=1;
      else if(ch >= 65 && ch<=90) //capital letters
        ccount+=1;

    else if (ch >= 97 && ch<=122) //lowercase letters
        ccount+=1;

        scanf("%c",&ch);
    }
    printf("The number of digits: %d\n",dcount);

    printf("The number of letters: %d\n",ccount);
    return 0;
}

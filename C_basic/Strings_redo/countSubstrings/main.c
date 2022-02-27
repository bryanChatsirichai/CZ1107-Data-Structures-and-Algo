#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int countSubstring(char str[], char substr[]);
int main()
{
    char str[80], substr[80], *p;
    int result;

    printf("Enter the string \n");
    fgets(str,80,stdin);
    if(p = strchr(str,'\n'));
        *p = '\0';
    printf("Enter the sub string \n");
    fgets(substr,80,stdin);
    if(p = strchr(substr,'\n'));
        *p = '\0';
    result = countSubstring(str,substr);
    printf("countSubstring(): %d",result);
    return 0;
}
int countSubstring(char str[],char substr[]){
    int count,i,j,sub_len,total;
    sub_len = strlen(substr);
    total = 0;
    j = 0;
    count = 0;
    for(i = 0; i < strlen(str) ; i++ )
    {
        if(str[i] == substr[j])
        {
            count+=1;
            if (count ==  sub_len)
                { //total substr increment and reset sub str index
                    total += 1;
                    count = 0;
                    j = 0;
                }
            j++; //sub sting move to next letter
        }
        else
        {
            // sub string fails reset test conditon
            j = 0;
            count = 0;
            if(str[i] == substr[j]) //retest sub string from index 0  where fail
                {
                count+=1;           //abcabcdabcde
                j++;                  //abcde
                }

        }
    }
    return total;

}

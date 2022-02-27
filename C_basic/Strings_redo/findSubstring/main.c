#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int findSubstring(char *str,char *substr);
int main()
{
    int result;
    char str[40],substr[40],*p;
    printf("Enter the string: \n");
    fgets(str,40,stdin);
    if( p = strchr(str,'\n'))
        *p = '\0';
        printf("Enter the sub string: \n");
    fgets(substr,40,stdin);
    if( p = strchr(substr,'\n'))
        *p = '\0';
    result = findSubstring(str,substr);
    if (result == 1)
        printf("findSubstring(): Is a substring\n");
    else if ( result == 0)
        printf("findSubstring(): Not a substring\n");
    else
        printf("findSubstring(): An error\n");
 return 0;

}
int findSubstring(char *str,char *substr){
    int count,sub_len;
    int i = 0, j = 0;
    int result = 0;
    count = 0;
    sub_len = strlen(substr);
    for(i = 0 ; i < strlen(str) ; i++) //i++ at the end of loop body
    //strlen(str) stops before NULL
    {
        if(substr[j] == str[i])
        {

            count+=1;
            j++;

            if(count == sub_len)
                return 1;
        }


        else //broke the match or no match
        {   //reset substring index 0 to compair at index it fail
            j = 0; //reset back to sub string index 0 to check all
            count = 0; //reset back
            if (substr[j] == str[i]) //abbab
                {                    //bab
                    count+=1; //start from index it fail and test substring first letter
                    j++;
                }
        }
        printf("count %d\n",count);
        printf("index %d\n",i);

    }
    return result;
}

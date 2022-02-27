#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char *str);
int main()
{
    char str[50];
    printf("Enter a string to reverse\n");
    gets(str);
    reverse(str);
    printf("%s\n",str);
    return 0;
}
void reverse(char *str){
    int str_len,i;
    char temp;
    str_len = strlen(str);
    printf("string len is %d\n",str_len);

    for(i = 0; i< str_len / 2; i++){ //swap front and back until middle
        printf("i is %d\n",i);
        temp = str[str_len -1 - i];  //last index of char is n-1
        str[str_len-1-i] = str[i];
        str[i] = temp;
    }
        //str[str_len+1] = '\0'; the \0 in the original is left not touch since we did str_len -1


}

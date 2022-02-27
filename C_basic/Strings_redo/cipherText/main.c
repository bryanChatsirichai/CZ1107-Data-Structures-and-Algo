#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void cipher(char *s);
void decipher(char *s);
int main()
{
    char str[80];
    char *p;
    int choice;

    printf("Select one of the following options: \n");
    printf("1: cipher() \n");
    printf("2: decipher() \n");
    printf("3: exit() \n");
    do{
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch(choice){

        case 1:
            //getchar();
            printf("Enter the string: \n");
            scanf("\n");
            fgets(str, 80, stdin);
            if (p=strchr(str,'\n')) *p = '\0';
            printf("To cipher: %s -> ", str);
            cipher(str);
            printf("%s\n", str);
        break;
        case 2:
             printf("Enter the string: \n");
             //getchar();
             scanf("\n");
             fgets(str, 80, stdin);
             if (p=strchr(str,'\n')) *p = '\0';
             printf("To decipher: %s -> ", str);
             decipher(str);
             printf("%s\n", str);
             break;
             default:
             break;
        }
        }while(choice < 3);
    return 0;
}
void cipher(char *s){
    int i=0;
    while(*s != '\0')
    {

        if(*s == 'z')
            *s = 'a';

        else if (*s == 'Z')
            *s = 'A';

        else if (*s >= 'A' && *s < 'Z')
            *s = *s + 1;

        else if (*s >= 'a' && *s < 'z')
            *s = *s + 1;
        s++;
    }
}

void decipher(char *s){
    int i=0;
    while(*s != '\0')
    {

        if(*s == 'a')
            *s = 'z';

        else if (*s == 'A')
            *s = 'Z';

        else if (*s > 'A' && *s <= 'Z')
            *s = *s - 1;

        else if (*s > 'a' && *s <= 'z')
            *s = *s - 1;
        s++;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50
void display(char ptr[][SIZE],int n);
void sort_strings(char ptr[][SIZE],int n);
int main()
{

    int n,i;
    char nameptr[10][SIZE]; //each element in nameptr hold a pointer to an char stings
    char *p,test_char;
    printf("Input number of strings\n");
    scanf("%d",&n);
    printf("Enter %d strings\n",n);
    getchar();
    for(i=0 ; i < n; i++)
        {
        /*  nameptr + 0 points to the 0th string or 0th 1-D array.
            *(nameptr + 0) + 0 points to the 0th character of 0th 1-D array (address of char)
            *(*(nameptr + 0) + 0 ) points to the 0th character of 0th 1-D array (char value) */

        //The function fgets() reads all the characters up to and including the newline character.
        //Thus no \n in buffer thus no need getchar();
        fgets(nameptr[i],25,stdin);
        if(p = strchr(nameptr[i],'\n'))
        *p = '\0';
        //gets(nameptr[i]); also can
        printf("name is %s\n",nameptr[i]);
        //test_char =  getchar();
       printf("%c is taken\n",test_char);
         //scanf("%s",nameptr[i]);//scanf here no need getchar
        }

    sort_strings(nameptr,n);
    display(nameptr,n);
    return 0;
}

void display(char ptr[][SIZE],int n)
{   int i;
    for(i=0 ; i < n; i++)
        printf("%s\n",ptr[i]);
}
void sort_strings(char ptr[][SIZE],int n){
    int i,j;
    char temp[50];
    for(i = 0; i < n - 1 ; i++ ) //last index is n-1
    {
        // Last i elements are already in place
        //printf("i is %d\n",i);
      /* n-1-i after every i iteration the last number index will
        be like a group 'bubble' to behind thus no need to compaire again  */
        for(j = 0; j < n - 1 - i;j++) // note not to access ptr[n] as out of the array
        {// n-1 is the last indec

            //str1 - str2
            if(strcmp(ptr[j],ptr[j+1]) > 0 ) //swap if str1 > str 2
            {   //printf("strcmp %d\n",strcmp(ptr[j],ptr[j+1]));
                //bubble swap
                //printf("len of ptr[j] is %d len of ptr[j+1] is %d\n",strlen(ptr[j]),strlen(ptr[j+1]));
                strcpy(temp,ptr[j]);
                strcpy(ptr[j],ptr[j+1]);
                strcpy(ptr[j+1],temp);
            }

        }


    }
}

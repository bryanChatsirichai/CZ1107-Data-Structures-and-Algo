#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

void findMinMaxStr(char word[][40], char *first, char *last,int size );
int main()
{
    int size,i;
    char word[SIZE][40];
    char first[40],last[40]; //these are array
    printf("Enter size:\n");
    scanf("%d",&size);
    printf("Enter %d words: \n", size);
    for(i = 0;i <size;i++)
        scanf("%s",word[i]);
    findMinMaxStr(word,first,last,size);
    printf("First word = %s, Last word = %s\n", first, last);
    return 0;
}
void findMinMaxStr(char word[][40], char *first, char *last,int size ){
    int i,min,max;
    //set as default max and min
    min = word[0][0];
    max = word[0][0];
    strcpy(first,word[0]); //
    strcpy(last,word[0]);

    for(i=0;i<size;i++)
    {

      if (min > word[i][0])
      {
          strcpy(first,word[i]);
          min = word[i][0];

      }
      if(max < word[i][0])
      {
        strcpy(last,word[i]);
        max = word[i][0];

        }
    }
}


/*
{

      int i;
    strcpy(first,word[0]);
    strcpy(last,word[0]);
    for(i=0;i<size;i++)
    {
        if(strcmp(word[i],first) < 0)
            strcpy(first,word[i]);
        if(strcmp(word[i],last) > 0)
        strcpy(last,word[i]);
    }
	/*end_edit*/



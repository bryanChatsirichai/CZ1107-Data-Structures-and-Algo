#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10
void readNames(char nameptr[][80], int *size);
int findTarget(char target[],char nameptr[][80], int size);
void printNames(char nameptr[][80], int size);
int main()
{   char nameptr[SIZE][80];
    char t[40],*p;
    int choice, size,result;
    size = 0;
   printf("Select one of the following options: \n");
   printf("1: readNames()\n");
   printf("2: findTarget()\n");
   printf("3: printNames()\n");
   printf("4: exit()\n");
   do{
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch(choice){
case 1:
        readNames(nameptr,&size);
        break;

case 2:
        printf("Enter target name:\n");
        scanf("\n");
        //getchar();
        //clear buffer
        fgets(t,80,stdin);
        if(p = strchr(t,'\n'))
            *p = '\0';
        result = findTarget(t,nameptr,size);
        printf("findTarget():%d\n",  result);
        break;
case 3:

        printNames(nameptr,size);
        break;

        }



   }while(choice < 4);
    return 0;
}

void readNames(char nameptr[][80], int *size){
       int i;
    printf("Enter size:\n");
    scanf("%d",size);
    printf("Enter %d names:\n",*size);
    scanf("\n");
    //getchar();
    for(i = 0;i< *size;i++) //size in this func is address
    {
        scanf("%s",nameptr[i]); //2d array of strings
    }


}

int findTarget(char target[],char nameptr[][80], int size){
    int i,index;

    index = -1; //set default fail
    for (i = 0; i < size;i++)
    {
        if( strcmp(*(nameptr+i),target) == 0) //means string same
        {
            index = i;
            return index;
        }
    }

    return index;
}
void printNames(char nameptr[][80], int size){
    int i;
    for(i=0 ;i< size;i++)
    {
        printf("%s ",nameptr[i]);
    }
    printf("\n");

}

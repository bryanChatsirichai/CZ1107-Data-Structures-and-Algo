#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
void readNames(char nameptr[][80], int *size);
int findTarget(char *target, char nameptr[][80],int size);
void printNames(char nameptr[][80], int size);
int main()
{
   int choice,size,result;
   char nameptr[SIZE][80];
   char t[40];
   char *p;
   printf("Select one of the following options: \n");
   printf("1: readNames()\n");
   printf("2: findTarget()\n");
   printf("3: printNames()\n");
   printf("4: exit()\n");
   do{
    printf("Enter your choice: \n");
    scanf("%d",&choice);
    switch(choice){

    case 1:
        readNames(nameptr,&size);
        break;
    case 2:

         printf("Enter target name: \n");
          //getchar(); // remove \n buffer after switch
         scanf("\n");
         fgets(t,40,stdin);
         if(p = strchr(t,'\n'))
            *p = '\0';
         result = findTarget(t,nameptr,size);
         printf("findTarget(): %d\n",  result);
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
    char *p;
    printf("Enter size:\n");
    scanf("%d",size);
    //scanf("\n");
    getchar(); // remove \n buffer after switch
    //getchar(); // remove \n buffer after switch
    printf("Enter %d names:\n",*size);
    for(i = 0; i< *size; i++)
    {
        //fgets(nameptr[i],80,stdin);
        //if(p = strchr(nameptr[i],'\n'))
            //*p = '\0';
            scanf("%s",(nameptr+i));

    }
    //getchar();

}
int findTarget(char *target, char nameptr[][80],int size){
    int i;

    for(i = 0;i < size ; i++){
        if(strcmp(target,nameptr[i]) == 0 )
            return i;
    }
    return -1;
}
void printNames(char nameptr[][80], int size){
    int i;
    //getchar();
    //scanf("\n");
    for(i = 0;i < size ;i++)
        printf("%s ",nameptr[i]);
    printf("\n");
}

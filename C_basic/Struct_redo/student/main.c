#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50
typedef struct{
    int id;
    char name[50];
}Student; //tag
void inputStud(Student *s, int size);
void printStud(Student *s, int size);
int removeStud(Student *s, int *size, char *target);
int main()
{   /** variable declearation **/
    int size = 0 , choice , result;
    Student s[SIZE]; //structure array Student of 50 elemenent
    // Student variable s is pointer constant to the base address of the array
    char *p;
    char target[50];

    /** main body **/
    printf("Select one of the following options: \n");
    printf("1: inputStud()\n");
    printf("2: removeStud()\n");
    printf("3: printStud()\n");
    printf("4: exit()\n");
    do{
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){

    case 1:
        printf("Enter size:\n");
        scanf("%d",&size);
        printf("Enter %d students\n",size);
        getchar(); //clear \n
        inputStud(s,size);
        break;


    case 2:
        printf("Enter name to be remove:\n");
        scanf("\n");
        //getchar();
        fgets(target,50,stdin);
        if(p = strchr(target,'\n'))
            *p = '\0';
        result = removeStud(s,&size,target);
         if (result == 0)
             printf("Successfully removed\n");
         else if (result == 1)
             printf("Array is empty\n");
         else if (result == 2)
             printf("The target does not exist\n");
         else
             printf("An error has occurred\n");

        break;

    case 3:
        printStud(s,size);
        break;


    }
    }while(choice < 4);






    return 0;
}

void inputStud(Student *s, int size){
    int i;
    char *p;
    for(i = 0; i < size; i++){
        printf("Student ID:\n");
        scanf("%d",&(s[i].id));
        printf("Student Name:\n");
        getchar();
        fgets((s+i)->name,50,stdin);
            if(p = strchr((s+i)->name,'\n'))
                *p = '\0';
    }

}
void printStud(Student *s, int size){
    int i=0;
    if(size > 0){
    printf("The current student list:\n");
    for(i = 0 ;i < size ;i++)
    {
        printf("Student ID: %d Student Name: %s\n",(s+i)->id,(s+i)->name);

    }
    }
    else if(size <= 0)
        printf("The array is empty\n");

}
int removeStud(Student *s, int *size, char *target){
    int i,check,index;

    if(*size == 0){ //array empty
        return 1;
    }
    else //array not empty

    {   /*check for any match*/
        for(i = 0; i < *size  ;i++)
        {
            check = strcmp((s+i)->name,target);
             printf("Strcmp result %d\n",check);
            if(check == 0)
                {
                    index = i; //index to remove and shift forward
                    break;
                }

        }
    }
    if(check == 0) //means got match
    {
        //printf("Remove\n");
       // printf("index is %d\n",index);
        for(index;index< (*size) - 1;index++) //shift and delete
        { //size - 1 so wont overshot if remove at last index
            //printf("s[index] %s\n",s[index].name);
            s[index] = s[index + 1];

        }
        (*size)--; //removed student count -1
        return 0;
    }
    else //target not in arrays
        return 2;


}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct{
    char name[40];
    char tel[40];
    int id;
    double salary;
}Employee;

int readin(Employee *emp);
int search(Employee *emp,int size,char *target);
int addEmployee(Employee *emp,int size,char *target);
int removeEmp(Employee *emp,int size,char *target);
void printEmp(Employee *emp,int size);
int main()
{
   Employee emp[MAX]; //emp array of Employee data type
   //emp base address of array
   int choice,size,result;
   char *p;
   char target[50];

     printf("Select one of the following options: \n");
     printf("1: readin() \n");
     printf("2: search() \n");
     printf("3: addEmployee() \n");
     printf("4  removeEmp()\n");
     printf("5: print() \n");
     printf("6: exit() \n");
   do{
      printf("Enter your choice: \n");
      scanf("%d",&choice);
      switch(choice){
  case 1:
        size = readin(emp);
        break;
  case 2:
        printf("Enter search name: \n");
        //getchar();
        scanf("\n");
        fgets(target,50,stdin); //remove \n
        if(p = strchr(target,'\n'))
            *p = '\0';
        result = search(emp,size,target);
        if (result == -1)
        {
            printf("The list is empty!\n");
        }
        else if(result == 0)
            printf("Name not found!\n");
        break;
  case 3:
        printf("Enter new name:\n");
        getchar(); //clear buffer
        fgets(target,50,stdin); //remove \n
        if(p = strchr(target,'\n'))
            *p = '\0';
        result = search(emp,size,target); //check if name already have?
        if(result != 1) //result not 1 name not in list
            size = addEmployee(emp,size,target); //add emp and update size
        else
        {
            printf("The new name has already existed in the database\n");
        }
            break;

  case 4:
        printf("Enter name to remove\n");
        scanf("\n");
             fgets(target,50,stdin); //remove \n
            if(p = strchr(target,'\n'))
            *p = '\0';
        result = search(emp,size,target); //check if name already have?
        if(result == 1) //name is in list
            {
                size = removeEmp(emp,size,target); //add emp and update size
                printf("name has been removed\n");
            }
        else if (result == -1)
        {
            printf("The list is empty!\n");
        }
        else
        {
            printf("Name to be remove not found!\n");
        }
          break;

  case 5:
        printEmp(emp,size);
        break;
      }




   }while(choice < 6);

    return 0;
}
int readin(Employee *emp){
    int i;
    i = 0; //default
    getchar();
    printf("Enter name\n");
    gets((emp+0)->name);
    while(strcmp(emp[i].name,"#") != 0 ) //not # contuinue
    {
        printf("Enter tel:\n");
        gets((emp + i)->tel);
        printf("Enter id:\n");
        scanf("%d",&emp[i].id);
        printf("Enter salary:\n");
        scanf("%lf",&(emp + i)->salary);

        i++;

        getchar();
        printf("Enter name\n");
        gets((emp+i)->name);
    }
    return i;
}
void printEmp(Employee *emp,int size){
    int i;
    printf("The current employee list:\n");
    for(i = 0;i<size;i++)
    {
        printf("%s %s %d %.2f\n",emp[i].name,emp[i].tel,emp[i].id,emp[i].salary);
    }


}
int search(Employee *emp,int size,char *target){
    //return 1 if have elso 0
    int i,index;
    index = -1; //default assume no have
    if(size == 0)
    {
       return -1;
    }
    for(i = 0; i < size;i++)
    {
        if(strcmp(emp[i].name,target) == 0)
        {
            //have
            index = i;
            printf("Employee found at index location: %d\n",index);
            printf("%s %s %d %.2f\n",emp[i].name,emp[i].tel,emp[i].id,emp[i].salary);
            return 1;
        }
    }

    return 0; //if exit loop here mean no have
}
int addEmployee(Employee *emp,int size,char *target){
    if(size >= 3 )
    {
        printf("Array full\n");
        //return 0 set array back to size 0;
        return 0;
    }
        strcpy(emp[size].name,target);
        printf("Enter tel:\n");
        gets((emp + size)->tel);
        printf("Enter id:\n");
        scanf("%d",&emp[size].id);
        printf("Enter salary:\n");
        scanf("%lf",&(emp + size)->salary);

        printf("Added at position: %d\n",size);

        return size+=1; //return new size
}
int removeEmp(Employee *emp,int size,char *target){
    int i,index;
    index = -1; //default

    for(i=0; i< size;i++)
    {
        if(strcmp( (*(emp+i)).name,target ) == 0 )
            {   //get index to remove
                index = i;
                break;
            }
    }
    if(index >= 0) //means found something
    {
        //size - 1 so wont overshot if remove at last index
        for(index;index < (size - 1) ; index++)
        {
            //assign every thing down by 1 after 'remove' target
            emp[index] = emp[index + 1];
        }

    }

    return (--size);

}

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void insert(int max, int *size, int ar[], int num);
void iremove(int *size, int ar[], int num);
void initialize(int *size, int ar[]);
void display(int size, int ar[]);

int main()
{
    int option = 0; //default
    int num,size=0;
    int ar[MAX];
   printf("Please select an option: \n");
   printf("(1) Initialize the array \n");
   printf("(2) Insert an integer \n");
   printf("(3) Remove an integer \n");
   printf("(4) Display the numbers stored in the array \n");
   printf("(5) Quit \n");
   do{
   printf("Enter your choice: \n");
   scanf("%d",&option);
   switch(option){
   case 1:
        initialize(&size,ar);
    break;
   case 2:
        printf("Enter an integer: \n");
        scanf("%d", &num);
        insert(MAX,&size,ar,num);
    break;
    case 3:
        printf("Enter the integer to be removed: \n");
        scanf("%d", &num);
        iremove(&size,ar,num);
        break;
    case 4:
        display(size,ar);
        break;

    default:
        break;
   }


    }while(option < 5);

    return 0;
}
void initialize(int *size, int ar[]){
    int num,total,i;
    printf("Enter the total number of integers (MAX=10):\n");
    scanf("%d",&total);
    printf("Enter the integers:\n");
    *size = 0; //set to 0 during initialize
    for(i = 0; i < total; i++) //first time will 1 by 1 use insert with loop
    {
        scanf("%d", &num);                             // initialize call again will reset array
        insert(MAX,size,ar,num);
    }

}

void insert(int max, int *size, int ar[], int num){

    int i,j,temp;
    if(*size == MAX)
        printf("The array is full\n");
    else
    {
        ar[*size] = num;
        (*size)++;
    }

    //sort array in ascending order
    for(i = 0;i < *size;i ++)
    {
        for(j = i+1;j< *size ;j++)
        {
            if(ar[i] > ar[j]) //swap number using iteration
            {
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }

}

void iremove(int *size, int ar[], int num){
    int i,index,temp,remove;
    remove = 0; //default nth remove
    if(*size == 0)
        printf("The array is empty\n");
    else{
        for(i = 0;i<*size;i++) //index of first appearence to remove
        {
            if(num == ar[i])
            {
            index = i;
            remove = 1; //remove activated
            break; //quit at first index
            }
        }
        if(remove == 1)
        {
            for(i = index;i<*size-1;i++) //start at index to be remove
            //number to be remove
            {
                ar[i] = ar[i+1];
            }
            printf("The integer is removed\n");
            (*size)--;
        }
        else
        printf("The number is not in the array\n"); //reach here means number to remove not in array
    }

}
void display(int size,int ar[]){
    int i;
    printf("The %d numbers on the array:\n",size);
    for(i=0;i<size;i++)
        printf("%d ",ar[i]);

    printf("\n");

}

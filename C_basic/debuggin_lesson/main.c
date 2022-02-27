#include <stdio.h>
#include <stdlib.h>

int main()
{
   // program is to see if user entered number
   // is present in array or not?

   int flag = 0; //if zero number not found
   int key = 0; // to store user enter value
   int  int_array[] = {12,15,18,19,20}; //array in which number is search
   printf("Enter a value to be searched\n");
   scanf("%d",&key);
   for(int i = 0;i<sizeof(int_array)/sizeof(int_array[0]);i++)
   {
    if(key == int_array[i]){
        flag=1;
        break;
    }
   }
   if(flag == 1)
   {
       printf("YES\n");
   }
   else
   {
       printf("N0\n");
   }


   return 0;
}

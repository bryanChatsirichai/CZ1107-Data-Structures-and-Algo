#include <stdio.h>
#include <stdlib.h>

int main()
{
    int height,i,j,count;
   printf("Enter the height\n");
   scanf("%d",&height);
   printf("pattern\n");
   for(i = 1;i <= height;i++)
   {
       count = i;
       if(count > 3)
       {
           count = count % 3;
           if( count == 0) //0 mod 3
            count = 3;
       }
       for(j = 0;j < i;j++)
       {
          printf("%d",count);

       }
       printf("\n");


   }
    return 0;
}

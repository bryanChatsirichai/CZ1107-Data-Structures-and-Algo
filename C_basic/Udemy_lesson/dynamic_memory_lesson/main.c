#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    char *ptr2;
    int n,i;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    ptr =(int *) malloc(n * sizeof(int));

    //ptr = malloc(n * sizeof(int));
    //ptr = (int *)ptr; //have to  type cast evantually
    printf("Enter %d numbers\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",ptr+i);
    }
    printf("Array nums are\n");
    printf("ptr points to %d\n",ptr);
        for(i=0;i<n;i++)
    {
        printf("adress is %d and num atr %d\n",(ptr+i),(ptr[i]));
    }
    ptr2 = (char *)calloc(20,sizeof(char));
    printf("enter string\n");
    scanf("%s",ptr2);
            for(i=0;i<20;i++)
    {
        printf("adress is %d and char %c\n",(ptr2+i),(ptr2[i]));
        if(ptr2[i] == '\0')
            printf("Null\n");
    }
     char *long_ptr2 = (char*)realloc(ptr2,2*20*sizeof(char));
     //char *long_ptr2 = (char*)realloc(NULL,2*10*sizeof(char)); //equivalent to malloc, create a new block not extending or copy
    //realloc can copy to new memory location ptr2 to long_ptr2 but here i did scanf instead
    free(ptr2); //deallocate ptr2 after making long_ptr2
    ptr2 = NULL;//after free adjust pointer to null safer
    printf("enter string\n");
    scanf("%s",long_ptr2);
            for(i=0;i<20;i++)
    {
        printf("address is %d and char %c\n",(long_ptr2+i),(long_ptr2[i]));
        if(long_ptr2[i] == '\0')
            printf("Null\n");
    }
    return 0;
}

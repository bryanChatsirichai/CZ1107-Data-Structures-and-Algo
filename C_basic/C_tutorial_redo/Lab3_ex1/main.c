#include <stdio.h>
#include <stdlib.h>
int findAr1D(int size,int *ar, int target);
int main()
{   int ar[20];
    int size,i,target,result;
    printf("Enter array size\n");
    scanf("%d",&size);
    printf("Enter %d data: \n", size);
    for(i = 0;i<size;i++)
        {
            scanf("%d",&ar[i]);
        }
    printf("Enter the target number: \n");
    scanf("%d", &target);
    result = findAr1D(size,ar,target);
    if(result == -1)
          printf("findAr1D(): Not found\n");
   else
      printf("findAr1D(): %d", result);

    return 0;
}
int findAr1D(int size,int *ar, int target){
    int i,index;
    index = -1; //default no have
    for(i = 0; i < size;i++)
        if(ar[i] == target)
            index = i;
    return index;
}

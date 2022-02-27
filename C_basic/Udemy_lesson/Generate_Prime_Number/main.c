#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ary[100] = {0};
    int i,j,index,check,count=0;
    index = 0;
    for(i = 1;i<=100;i++)
    {   //printf("i is %d\n",i);
        count = 0;
        for(j = 1; j <= i/2 ;j++) // prime can only divide by itself or by 1
       //for(j = 1; j <= i/2 ;j++) //same logic but divide by 2, 1 x 2 same as 2 x1
        {
            check  = i%j;
            //printf("i is %d\n",i);
            //printf("number %d has factor j is %d\n",i,j);
            if(check == 0)
            {
                count++;

            }
        }

        //count = 2
        if(count == 1 && i != 1) //j loop thru and exit normally
        {// j == i means factors are 1 and num only
            //prime number only has facotr 1 and itself
            ary[index] = i;
            index +=1;
        }

    }
    for(i = 0;i<index;i++)
        printf("Prime number %d\n",ary[i]);


    return 0;
}

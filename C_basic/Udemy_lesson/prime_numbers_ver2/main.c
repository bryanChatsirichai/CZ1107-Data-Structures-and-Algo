#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int ary[100] = {1,2};
    int i,j,index,check;
    index = 2;
    bool isPrime;
    for(i = 3;i<=100;i++)
    {
        //printf("i is %d\n",i);
        isPrime  = true;
        if(i % 2 == 0) //even numbers cannot be prime
            continue;

        for(j = 1; isPrime && i / ary[j] >= ary[j];j++) //check if the prime number not in the array already
        { //test ensure that the value of i does not exceed the squareroot of primes
            if( i % ary[j] == 0) //here when num greater than squaroot of

                {
                    //printf("in loop i is %d\n",i);
                    isPrime = false;
                    }
                    //printf("in loop i is %d\n",i);
        }
        if(isPrime == true) //j loop thru and exit normally
        {// j == i means factors are 1 and num only
//printf("outside loop i is %d\n",i);
            ary[index] = i;
            index ++;
        }

    }


      for(i = 0;i<index;i++)
        printf("prime number %d\n",ary[i]);
    return 0;
}

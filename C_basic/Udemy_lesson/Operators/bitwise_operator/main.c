#include <stdio.h>
#include <stdlib.h>

int main()
{   //not these are 4 byte thus 32bits
   unsigned int a = 60; //0011 1100
   unsigned int b = 13; //0000 1101
   printf("%d\n",a&b); // 0000 1100 12
   printf("%d\n",a|b); // 0011 1101 61
   printf("%d\n",a^b);//xor 0011 0001 49
   printf("%d\n",~10);//Note 2's compliment
   //step1 1100 0011 invert all
   //step 2 two compliment 1 011 1101
   // note 1st digit is 1 thus negative
   printf("%d\n",a<<2);//1111 0000
   printf("%d\n",a>>2);// 0000 1111
   printf("%d\n",b<<2);//0011 0100
   printf("%d\n",b>>2);// 0000 0011
    return 0;
}


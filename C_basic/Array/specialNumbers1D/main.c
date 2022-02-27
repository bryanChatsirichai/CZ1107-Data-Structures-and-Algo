void specialNumbers1D(int ar[], int num, int *size);
int main()
{
 int a[20],i,size=0,num;

 printf("Enter a number (between 100 and 999): \n");
 scanf("%d", &num);
 specialNumbers1D(a, num, &size);
 printf("specialNumbers1D() ");
 for (i=0; i<size; i++)
 printf("%d ",a[i]);
 return 0;
}
void specialNumbers1D(int ar[], int num, int *size)
{
 int i,j=0,temp,special,base,digit,power=1;
 for(base = 100; base<=num; base++)
 {
     special=0;
     temp = base;
     for(i=0; i<3 ;i++)
     {

         digit = temp%10;
         special = special +(digit * digit * digit);
         temp = temp/10;
     }
     if(special==base)
     {
         ar[j] = special;
         j++;

     }
 }
        *size = j; //dereference the address
}

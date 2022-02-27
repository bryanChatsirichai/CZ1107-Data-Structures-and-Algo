#include <stdio.h>
#include <stdlib.h>


struct account{
    char bank[20];
    int current;
    int saving;

}john;
int sum(int x , int y); //passing struct member as argument)
int add(struct account money); //passing struct as argument;
int main()
{
    //struct account john;

    printf("Enter bank name\n");
   scanf("%s",john.bank);
    printf("Enter current amount\n");
    //getchar();
   scanf("%d",&john.current);
    printf("Enter savingt amount\n");
    scanf("%d",&john.saving);
    printf("Bank used is %s\n",john.bank);
    printf("Total amount in bank is %d\n",sum(john.current,john.saving));
    printf("add %d\n",add(john));
    return 0;
}
int sum(int x , int y){

    return(x+y);

}
int add(struct account money){
    return money.saving + money.current;
    }


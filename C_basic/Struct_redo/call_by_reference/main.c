#include <stdio.h>
#include <stdlib.h>
struct account{
    char bank[20];
    float current;
    float saving;

};
float sum(struct acc * money);
int main()
{
    struct account john;
    struct account *ptr = &john;
    printf("Enter bank name:\n");
    scanf("%s",john.bank);
    printf("Enter current\n");
    scanf("%f",&john.current);
    printf("Enter saving\n");
    scanf("%f",&john.saving);
    printf("at bank %s you have total %.2f\n",john.bank,sum(ptr));
    return 0;
}
float sum(struct account *money){

    return money->current + (*money).saving;



}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct account{

    struct n { //nested struct
    char lastName[10];
    char firstName[10]
    }names; //strcut n is a memeber of struct account;

    int accountNum;
    double balance;
};

void nextCustormer(struct account *acct);
void printCustomer(struct account *acct);
int main()
{
    int flag = 0; //default
    struct account record; //create a structe variable of type account
    struct account *ptr; //pointer to struct account
    ptr = &record;
    do{
       nextCustormer(ptr);
        if (( strcmp(record.names.firstName,"End") == 0) &&
            (strcmp(record.names.lastName,"Customer") == 0))
        {
            flag = 1;
        }
        if (flag != 1)
        {
            printCustomer(ptr);
        }
    printf("flog is %d\n",flag);
    }while(flag != 1);
    return 0;
}
void nextCustormer(struct account *acct){

    printf("Enter names (firstName lastName):\n");
    scanf("%s %s",acct->names.firstName,(*acct).names.lastName);
    if (( strcmp(acct->names.firstName,"End") == 0) && (strcmp(acct->names.lastName,"Customer") == 0))
            return; //quit fucntion if enter this
    printf("Enter account number:\n");
    scanf("%d",&acct->accountNum);
    printf("Enter balance:\n");
    scanf("%lf",&acct->balance);

}
void printCustomer(struct account *acct){
    printf("Customer record:\n");
    printf("%s %s %d %.2f\n",acct->names.firstName,acct->names.lastName,acct->accountNum,acct->balance);


}

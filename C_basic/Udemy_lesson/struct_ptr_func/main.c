#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item{
    char *itemName; //pointer to char
    int quantity;
    float price;
    float amount; //quantity mutiply price

};

void readItem(struct item *p);
void printItem(struct item *p);

int main()
{
   struct item itm;
   struct item *ptr_itm;
   ptr_itm = &itm;
   readItem(ptr_itm);
   printItem(ptr_itm);
    return 0;
}
 void readItem(struct item *p){
    char *i;
    p->itemName = (char *)malloc(sizeof(char) * 30); //allocate memory dynamictly
    printf("Enter product name\n");
    fgets(p->itemName,30,stdin);
    if(i = strchr(p->itemName,'\n'))
        *i = '\0';
    printf("Enter price\n");
    scanf("%f",&p->price);
    printf("Enter quantity\n");
    scanf("%d",&((*p).quantity));

    p->amount = p->quantity * p->price;

 }
void printItem(struct item *p){
    printf("\nName: %s\n",p->itemName);
    printf("Price: %.2f\n",(*p).price);
    printf("Quantity: %d\n",p->quantity);
    printf("Total Amount: %.2f\n",p->amount);


}

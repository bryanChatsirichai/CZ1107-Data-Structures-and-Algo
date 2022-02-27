#include <stdio.h>
#include <stdlib.h>

int main()
{
    int list,category;
    float list_discount,total,tax;
    printf("Please enter the list price: \n");
    scanf("%d",&list);
    printf("Car (1600 c.c. & below) & Taxi: COE = 70,000\n");
    printf("Car (above 1600 c.c.): COE = 80,000\n");
    printf("Goods Vehicle & Bus: COE = 23,000\n");
    printf("Motorcycle - COE: 600\n");
    printf("Please enter the category:\n");
    scanf("%d",&category);
    switch(category)
    {
        case 1:
            list_discount = (float)list * 0.9;
            if(list_discount > 100000)
                list_discount = list_discount *1.10;
            tax = list_discount * 0.03;
            total = tax + list_discount + 70000;
            if(total)
            break;
        case 2:
            list_discount = (float)list * 0.9;
            if(list_discount > 100000)
                list_discount = list_discount *1.10;
            tax = list_discount * 0.03;
            total = tax + list_discount + 80000;
            break;
        case 3:
            list_discount = (float)list * 0.9;
            if(list_discount > 100000)
                list_discount = list_discount *1.10;
            tax = list_discount * 0.03;
            total = tax + list_discount + 23000;
            break;
        case 4:
            list_discount = (float)list * 0.9;
            if(list_discount > 100000)
                list_discount = list_discount *1.10;
            tax = list_discount * 0.03;
            total = tax + list_discount + 600;
            break;
        default:
            printf("Error\n");
            break;
    }
    printf("Total price is %.2f\n",total);

    return 0;
}

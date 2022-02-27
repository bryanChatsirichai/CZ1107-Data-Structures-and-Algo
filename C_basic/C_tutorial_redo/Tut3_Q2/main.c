#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void getFrequency(int histogram[],int numbers);
void printFrequency(int histogram[],int numbers);
int main()
{
    int nums;
    int histogram[10]; //Every 10 digit is consider 1 array 0~9, 10~20;
    printf("Enter the amount of random numbers\n");
    scanf("%d",&nums);
    srand(time(NULL));
    getFrequency(histogram,nums);
    printFrequency(histogram,nums);
    return 0;
}
void getFrequency(int histogram[],int numbers){
    int i,random_num,index;
     for( i = 0;i < 10;i++) //set array index 0 to 9 base value 0
     {
         histogram[i] = 0; //set array all index value is 0
     }


    for( i = 0;i < numbers;i++)
    {
        random_num = rand();
        random_num = random_num % 100; //range will be 0 ~ 99
        //printf("%d\n",random_num);
        index = random_num / 10; //index is base on number value
        histogram[index]++; //increment count by 1 every time number is in that range

    }

}
void printFrequency(int histogram[],int numbers){
    int i,j,row,min,max;

    for(i=0;i<10;i++) //print the rows
    {
        printf("%d - %d |",min=i*10,max=i*10 + 9);
        for(j=0;j<histogram[i];j++)
        {

            putchar('*');
        }
        //printf("amoutn is %d\n",histogram[i]);
        putchar('\n');
    }


}

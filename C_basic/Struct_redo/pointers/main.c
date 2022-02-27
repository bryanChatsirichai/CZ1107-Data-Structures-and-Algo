#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    char *name;
    int *row;
    char gender;
    int marks[5];

}std; //change struct student to std


int main()
{   int *ptr;
    int row = 5;
    std std1 = {"Bryan",&row,'M',{90,80,70,60,50}};
    std std_ary[10];
    std *ptr_ary1 = std_ary; //ptr to & of 1st element if the structure array
    std (*ptr_ary2)[10] = &std_ary;// Pointer to an array of 10 struct student
    std *ptrstd1;
    ptrstd1 = &std1; //pointer to a structure
    /*ptrStu1 stores the base address of stu1, which is the
    base address of the first member
    of the structure. Incrementing by 1 would
    increase the address by sizeof(stu1) bytes.*/
    printf("size of pointer ptr is %d\n",sizeof(ptr));
    printf("address %d\n",ptrstd1);
    printf("address of first member is %d\n",&std1.name); //8
    printf("address of secoond member is %d\n",&std1.row); //8
    printf("address of third member is %d\n",&std1.gender);//1 +3(pad)
    printf("address of fourth member is %d\n",&std1.marks);//20
    printf("\n");
    printf("size of struct %d\n",sizeof(std1)); //40
    printf("address %d\n",ptrstd1+1); //&ptrstd + sizeof(std)

    printf("char in name is %c\n",*((std1.name)+2));
    printf("%s is in row %d\n",std1.name,*(std1.row));
    printf("\n");

    printf("Name w.o using ptrStd1 : %s\n", std1.name);
    printf("Name using ptrStd1 and * : %s\n", (*ptrstd1).name);
    //. higher precedence than *
    printf("Name using ptrStd1 and -> : %s\n", ptrstd1->name);
    printf("\n");

    printf("addres of pointer to first element is std array %d\n",ptr_ary1);
    printf("addres of pointer to first element is std array %d\n",ptr_ary1+1); //points to the next struct element in the array plus sizeof struct 40

    printf("addres of pointer to entire array with 10 struct elements is std array %d\n",ptr_ary2);
    printf("addres of pointer to entire array with 10 struct elements is std array %d\n",ptr_ary2+1); //40 x 10
    //pointer to whole array and pointer arithmatic relative to base type of the pointer.

    return 0;
}

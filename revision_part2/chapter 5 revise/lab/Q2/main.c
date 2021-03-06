#include <stdio.h>
#include <stdlib.h>

#define SIZE 80 //The limit of expression length

typedef struct _stackNode{
    double item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, double item);
int pop(Stack *sPtr);
double peek(Stack s);
int isEmptyStack(Stack s);

double exePostfix(char*);

int main()
{
    char postfix[SIZE];

    printf("Enter a postfix expression:\n");
    gets(postfix);

    printf("The answer is %.2lf.\n",exePostfix(postfix));

    return 0;
}


double exePostfix(char* postfix)
{
	double x,y,z,sum = 0;
	char temp;
	Stack s;
	s.head = NULL;
	s.size = 0;
	while(*postfix != '\0')
    {
        //printf("%c",*postfix);
        if(*postfix >= '0' && *postfix <='9')
        {
            push(&s,*postfix);
        }
        else
        {
            //postfix
            x = peek(s) - 48;
            pop(&s);
            y = peek(s) - 48;
            pop(&s);
            //y operate x
            if(*postfix == '+')
            {
                sum = y + x;
            }
            else if(*postfix == '-')
            {
                sum = y - x;
            }
            else if(*postfix == '*')
            {
                sum = y * x;
            }
            else if(*postfix == '/')
            {
                sum = y / x;
            }
            push(&s,sum + 48);
        }
        postfix++;
    }
    return sum;
}

void push(Stack *sPtr, double item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

double peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

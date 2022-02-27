#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

double exePrefix(char*);

int main()
{
    char prefix[SIZE];

    printf("Enter a postfix expression:\n");
    gets(prefix);

    printf("The answer is %.2lf.\n",exePrefix(prefix));

    return 0;
}


double exePrefix(char* prefix)
{
	double x,y,z,sum = 0;
	char temp;
	Stack s;
	s.head = NULL;
	s.size = 0;
	int m = strlen(prefix) / 2;
	int j = strlen(prefix) -1;
	for(int i=0;i<m;i++)
    {
        temp = prefix[i];
        prefix[i] = prefix[j];
        prefix[j] = temp;
        j--;
    }
    printf("%s\n",prefix);
	while(*prefix != '\0')
    {
        if(*prefix >= '0' && *prefix <='9')
        {
            push(&s,*prefix);
        }
        else
        {
            //postfix
            x = peek(s) - 48;
            pop(&s);
            y = peek(s) - 48;
            pop(&s);
            //y operate x
            if(*prefix == '+')
            {
                sum = x + y;
            }
            else if(*prefix == '-')
            {
                sum = x - y;
            }
            else if(*prefix == '*')
            {
                sum = x * y;
            }
            else if(*prefix == '/')
            {
                sum = x / y;
            }
            push(&s,sum + 48);
        }
        prefix++;
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

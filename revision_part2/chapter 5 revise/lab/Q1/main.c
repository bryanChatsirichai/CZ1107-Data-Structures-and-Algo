#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 80 //The limit of expression length

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

void in2Post(char*, char*);
int precedence(char c);
int main()
{
    char infix[SIZE];
    char postfix[SIZE];

    printf("Enter an infix expression:\n");
    gets(infix);

    in2Post(infix,postfix);
    printf("The postfix expression is \n");
    printf("%s\n",postfix);
    return 0;
}
int precedence(char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '(' || c == ')')
        return 3;
}
void in2Post(char* infix, char* postfix)
{
    Stack s;
    s.head = NULL;
    s.size = 0;
    int i = 0,j = 0;
    char temp;
   while(*infix != '\0')
   {

       if((*infix >= '0' && *infix <= '9') || (*infix >= 'a' && *infix <= 'z'))
       {

           postfix[i] = *infix;

           i++;
       }
       else if(*infix == ')')
       {
           push(&s,*infix);
       }
       else if(*infix == '(')
       {
           while(peek(s) != ')')
           {
               temp = peek(s);

               postfix[i] = temp;
               i++;
               pop(&s);
           }
           pop(&s);
       }
       else
       {

           while(!isEmptyStack(s) && peek(s) != '(' && precedence(peek(s)) >= precedence(*infix))
           {
               temp = peek(s);
               postfix[i] = temp;
               i++;
               pop(&s);
           }
           push(&s,*infix);
       }
       infix++;
   }
    while(!isEmptyStack(s))
    {
        temp = peek(s);
        pop(&s);
        postfix[i] = temp;
        i++;
    }
    postfix[i] = '\0';


}




void push(Stack *sPtr, char item){
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

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

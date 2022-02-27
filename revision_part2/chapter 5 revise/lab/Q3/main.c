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

void in2Pre(char*, char*);
int precedence(char c);
void reverse(char * string);
int main()
{
    char infix[SIZE];
    char prefix[SIZE];

    printf("Enter an infix expression:\n");
    gets(infix);
    reverse(infix);
    printf("infix reverse %s\n",infix);
    in2Pre(infix,prefix);
    reverse(prefix);
    printf("The prefix expression is \n");
    printf("%s\n",prefix);

    return 0;
}
void reverse(char * strng)
{
    int mid, i,j;
    char temp;
    mid = strlen(strng) / 2; //stop till middle
    j = strlen(strng) - 1; //start last indec
    i = 0;
    for(i;i<mid;i++,j--)
    {
        temp = strng[i];
        strng[i] = strng[j];
        strng[j] = temp;

    }
    return;
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
void in2Pre(char* infix, char* prefix)
{
    Stack s;
    s.head = NULL;
    s.size = 0;
    int i = 0;
    char   temp;
    while(*infix != '\0')
    {
        temp = *infix;
        printf("temp is %c\n",temp);
        if((temp >= '0' && temp <= '9') ||  (temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z'))
        {
            prefix[i] = temp;
            i++;
        }
        else if(temp == ')')
        {
            push(&s,temp);
        }
        else if(temp == '(')
        {
            while(peek(s) != ')')
            {
                prefix[i] = peek(s);
                pop(&s);
                i++;
            }
            pop(&s);
        }
        else
        {
            while(!isEmptyStack(s) && peek(s) != ')' && precedence(peek(s)) > precedence(temp))
            {
                prefix[i] = peek(s);
                pop(&s);
                i++;
            }
            push(&s,temp);
        }

        infix++;
    }
    while(!isEmptyStack(s))
    {
        prefix[i] = peek(s);
        i++;
        pop(&s);
    }
    printf("i is %d\n",i);
    prefix[i] = '\0';

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 80 //The size of the array

enum ExpType {OPT,OPERAND};

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

typedef struct _listnode
{
    int  item;
    enum ExpType type;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item,enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);


void in2PreLL(char* infix, LinkedList *inExpLL);
int precedence(char c);
void printExpLL(LinkedList inExpLL);
void reverse(char *str);
int main()
{
    char infix[SIZE];

    //printf("Enter an infix expression:\n");
    gets(infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    in2PreLL(infix, &inExpLL);

    printExpLL(inExpLL);

    removeAllNodes(&inExpLL);
    return 0;
}
int precedence(char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
}
void in2PreLL(char* infix, LinkedList *inExpLL)
{
    ///no need read in reverse as string to LL already in reverse
    Stack s;
    s.head = NULL;
    s.size = 0;
    LinkedList ll2;
    ListNode *tempnode = NULL;
    ll2.head = NULL;
    ll2.size = 0;
    int i = 1,power = 10,sum = 0,num;
    char temp;
    if(infix == NULL)
        return;
    else
    {
      while(*infix != '\0')
      {
          temp = *infix;
          if(*infix >= '0' && *infix <= '9')
          {
              sum = 0;
              while(*infix >= '0' && *infix <= '9')
              {
                  sum = sum * power + *infix - 48;
                  infix++;
              }
              printf("sum is %d\n",sum);
              insertNode(&ll2,sum,OPERAND);
          }
          else
          {
              insertNode(&ll2,temp,OPT);
              infix++;
          }

      }
    }
    printExpLL(ll2);
    tempnode = ll2.head;
    while(tempnode != NULL)
    {
        if(tempnode->type == OPERAND)
        {   printf("option0\n");
            num = tempnode->item;
            insertNode(inExpLL,num,OPERAND);
            tempnode = tempnode->next;
        }
        else
        {
            if(tempnode->item == ')')
            {   printf("option1\n");
                push(&s,tempnode->item);
                tempnode = tempnode->next;
            }
            else if(tempnode->item == '(')
            {    printf("option2\n");
                while(peek(s) != ')')
                {
                    insertNode(inExpLL,peek(s),OPT);
                    pop(&s);
                }
                pop(&s);
                tempnode = tempnode->next;
            }
            else
            {
                 printf("option3\n");
                while(!isEmptyStack(s) && tempnode->item !=')' && precedence(peek(s)) > precedence(tempnode->item))
                {
                    insertNode(inExpLL,peek(s),OPT);
                    pop(&s);
                }
                push(&s,tempnode->item);
                tempnode = tempnode->next;
            }

        }
    }
    while(!isEmptyStack(s))
    {
        insertNode(inExpLL,peek(s),OPT);
        pop(&s);
    }
}

void printExpLL(LinkedList inExpLL)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    while(temp!= NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item);
        else
            printf(" %c ",(char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if(newNode==NULL) exit(0);

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head=newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr) {
    if(LLPtr==NULL || LLPtr->size==0){
        return 0;
    }
    else{
       ListNode *temp = LLPtr->head;
       LLPtr->head = LLPtr->head->next;

       free(temp);
       LLPtr->size--;
       return 1;
    }
}

int isEmptyLinkedList (LinkedList ll) {
    if(ll.size==0) return 1;
    else return 0;
}

void removeAllNodes(LinkedList *LLPtr)
{
	while(deleteNode(LLPtr));
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

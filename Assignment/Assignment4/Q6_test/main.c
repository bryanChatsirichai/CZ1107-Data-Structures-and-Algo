#include <stdio.h>
#include <stdlib.h>

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
int getPriority(char C);

void in2PreLL(char* infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExp);

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
    printExpLL(inExpLL);

    return 0;
}
int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}
void in2PreLL(char* infix, LinkedList *inExpLL)
{
    Stack s;
    s.head = NULL;
    s.size = 0;
    ListNode  *temp;
    LinkedList inExpLL2;
    inExpLL2.head = NULL;
    inExpLL2.size = 0;
    char *ptrstr;
    int num = 0, power = 10;
    if(infix == NULL)
        return;
    else
    {
        ptrstr = infix;
        while(*ptrstr != '\0') //insert the infix in reverse
        {    //printf("num is %d\n",num);
            if(*ptrstr >= '0' && *ptrstr <= '9')
            {
                num = num * power + (*ptrstr - 48);
                if (*(ptrstr + 1) < '0' || *(ptrstr + 1) > '9')
                {
                    //printf("num befire insert is %d\n",num);
                    insertNode(inExpLL,num,OPERAND);
                    num = 0;
                    power = 10;
                }
            }
            else
            {
                if(*ptrstr == '(')
                   insertNode(inExpLL,')',OPT);
               else if(*ptrstr == ')')
                   insertNode(inExpLL,'(',OPT);
                else
                    insertNode(inExpLL,*ptrstr,OPT);
            }
            ptrstr++;
        }
    }
    printf("before\n");
    printExpLL(*inExpLL);
    temp = inExpLL->head;
    while(temp!=NULL)
    {
        if(temp->type == OPERAND)
        {
            insertNode(&inExpLL2,temp->item,OPERAND);
        }
        else if (temp->item == '(')
        {
            push(&s,temp->item);
        }
        else if (temp->item == ')')
        {
            while(peek(s) != '(')
            {   //printf("test\n");
                insertNode(&inExpLL2,peek(s),OPT);
                pop(&s);
            }
            pop(&s); //remove '('
            //printf("test\n");
        }
        else
        {
            while(!isEmptyStack(s) && peek(s) != '(' && getPriority(peek(s)) > getPriority(temp->item)   ) //infix to prefix assosiativity and precedence different from infix to postfix
            {   //if have same precedence check associtivity left to right just push to stack
                //for infix to postfix if same precedence and associtivity left to right pop out top of stack then check new top and see if need push
                insertNode(&inExpLL2,peek(s),OPT);
                pop(&s);
            }

            push(&s,temp->item);
        }

        temp = temp->next;
        //printf("temp next\n");
    }

    while(!isEmptyStack(s))
    {
        if(peek(s) != '(' && peek(s) != ')')
        {
            insertNode(&inExpLL2,peek(s),OPT);
            pop(&s);
        }
        else
        {
            pop(&s);
        }
    }
    //printf("before quit\n");
    //printExpLL(inExpLL2);
    removeAllNodes(inExpLL);
    inExpLL->head = inExpLL2.head;
    inExpLL->size = inExpLL2.size;
    inExpLL2.head = NULL;
    //printExpLL(*inExpLL);

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

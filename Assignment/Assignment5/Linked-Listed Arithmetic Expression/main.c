#include <stdio.h>
#include <stdlib.h>

#define SIZE 80 //The size of the array

enum ExpType {OPT,OPERAND}; //opt symbol operand is number

typedef struct _listnode
{
    int  item;
    enum ExpType type; //type instatiation
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item, enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);

void expressionLL(char* infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExpQ, int seed);

int main()
{

    char infix[SIZE];
    printf("Enter an infix expression:\n");
    gets(infix);
    //printf("%s\n",infix);
    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    expressionLL(infix, &inExpLL);

    int seed;
    //printf("Enter a seed: \n");
    scanf("%d",&seed);
    printExpLL(inExpLL,seed);

    removeAllNodes(&inExpLL);
    return 0;
}


void expressionLL(char* infix, LinkedList *inExpLL)
{
    char *ptrstr;
    int num = 0, power = 10;
    if(infix[0] == '\0')
        return;
    else
    {
        ptrstr = infix;
        while(*ptrstr != '\0')
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
                insertNode(inExpLL,*ptrstr,OPT);
            }
            ptrstr++;
        }
    }
    ///reverse the linked list
    ListNode *r,*p,*q;

    if(inExpLL->head == NULL || inExpLL->size <= 1)
        return;
    else
    {
        r = NULL;
        p = NULL;
        q = inExpLL->head;
        while(q != NULL)
        {
            r = p;
            p = q;
            q = q->next;
            p->next = r;
        }
        inExpLL->head = p;
    }


}

void printExpLL(LinkedList inExpLL, int seed)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    while(temp!= NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item+ seed);
        else
            printf(" %c ",(char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if(newNode==NULL) exit(0); //if unable to malloc

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head=newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr) {
    if(LLPtr==NULL || LLPtr->size==0){ //Queue is empty or NULL pointer
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

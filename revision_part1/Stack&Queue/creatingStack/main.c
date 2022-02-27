#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;
}ListNode;

typedef struct _linkedlist{
    int size;
    ListNode *head;
    ListNode *tail;
}LinkedList;

typedef struct _stack{
    LinkedList ll;
}Stack;

///LinkList functions///
void insertNode(LinkedList *ll,int index, int value);
void removeNode(LinkedList *ll,int index);
void printList(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);

///Stack function///
void push(Stack *s,int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

int main()
{
    int popItem,peekItem,value;
    Stack s;
    s.ll.size = 0;
    s.ll.head = NULL;
    s.ll.tail = NULL;
    printf("Enter value\n");
    scanf("%d",&value);
    while(value != -1)
    {
        push(&s,value);
        printf("Enter value\n");
        scanf("%d",&value);
    }
    while(!isEmptyStack(&s))
    {
        peekItem = peek(&s);
        printf("Peek item is %d\n",peekItem);
        popItem = pop(&s);
        printf("pop item is %d\n",popItem);
    }
    return 0;
}
int isEmptyStack(Stack *s){
    //empty return 1
    // not empty return 0
    if((s->ll).size == 0)
        return 1;
    else
        return 0;
}

void push(Stack *s,int item){
    insertNode(&(s->ll),0,item);
    return;
}
int peek(Stack *s){
    int value;
    value = ((s->ll).head)->item;
    return value;
}

int pop(Stack *s){
    //pop from the top which is the head
    //first in last out
    int value;
    value = ((s->ll).head)->item;
    removeNode(&(s->ll),0);
    return value;
}
void printList(LinkedList *ll){
    ListNode *temp;
    if(ll->head == NULL)
    {
        printf("Empty nothing to print\n");
        return;
    }
    else
    {
        temp = ll->head;
        while(temp != NULL)
        {
            printf("%d ",temp->item);
            temp = temp->next;
        }
        printf("\n");
        return;
    }
}
ListNode *findNode(LinkedList *ll, int index){
    ListNode *temp;
    if(ll->head == NULL)
        return NULL;
    else
    {
        temp = ll->head;
        while(index != 0)
        {
            if(temp == NULL)
            {
                printf("Overshot\n");
                return NULL;
            }
            temp = temp->next;
            index--;
        }
        return temp;
    }
}
void insertNode(LinkedList *ll,int index, int value){
    ListNode *pre,*cur,*temp;
    //printf("Size is %d\n",ll->size);
    if(ll == NULL || index < 0 || index > ll->size + 1)
    {
        printf("Error insert\n");
        return;
    }
     // If empty list or inserting first node, need to update head pointer
    if(ll->head == NULL || index == 0)
    {
        cur = ll->head;
        temp = malloc(sizeof(ListNode));
        temp->item = value;
        temp->next = cur;
        ll->head = temp;
        if(ll->size == 0)
        {   //first time set head and tail same
            //if add at index 0 tail will not change
            ll->tail = ll->head;
        }
        ll->size++;
        return;
    }
    // Inserting as new last node
    if(index == ll->size)
    { //adding at tail
       temp = malloc(sizeof(ListNode));
       temp->next = NULL;
       temp->item = value;
       //connect to the new node after tail
        pre = ll->tail; //old tail
        cur = ll->tail->next; //after the old tail should be Null here
        pre->next = temp;
        temp->next = cur;
        ll->tail = temp;
        ll->size++;
       return;
    }
    if((pre = findNode(ll,index - 1 ))!= NULL)
        { //get the node before where we going to insert
            cur = pre->next; //node after the pre
            //new npde between pre and cur
            temp = malloc(sizeof(ListNode));
            pre->next = temp;
            temp->next = cur;
            temp->item = value;
            ll->size++;
            return;
        }
}
void removeNode(LinkedList *ll,int index){
    ListNode *pre,*cur,*temp;
    if(ll->head == NULL || index >= ll->size )
    {
        printf("Stack Empty nothing to remove or overshot\n");
        return;
    }
    if(index == 0)
    { // If removing first node, need to update head pointer
        temp = ll->head; //to be remove
        cur = ll->head->next;
        ll->head = cur; //shift head to next node if any
        ll->size--;
        if(ll->size == 0)
        {
            ll->tail = NULL;
        }
        free(temp);
        return;
    }

   // Find the nodes before and after the target position
    // Free the target node and reconnect the links
    if((pre = findNode(ll,index - 1)) != NULL)
    {
        // Removing the last node, update the tail pointer
        if(index == ll->size -1)
        {
            temp = ll->tail; //to be remove last node
            ll->tail = pre; //shift tail pointer behind;
            ll->tail->next = NULL;
            free(temp);

        }
        else
        {
            temp = pre->next; //to be remove
            cur = temp->next; //after temp
            //temp is between pre and cur to be remove
            pre->next = cur;
            free(temp);

        }
        ll->size--; //update size
        return;

    }

}

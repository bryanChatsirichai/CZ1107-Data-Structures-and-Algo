#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;
}listNode;

typedef struct _linkedlist{
    int size;
    listNode *head;
    listNode *tail;
}LinkedList;

typedef struct{
    LinkedList ll;
}Queue;

///Linked list functions///
void insertNode(LinkedList *ll,int index,int item);
void removeNode(LinkedList *ll,int index);
void printLinkList(LinkedList *ll);
listNode *findNode(LinkedList *ll,int index);

///Queue Functions///
void enqueue(Queue *q,int item);
int dequeue(Queue *q);
int isEmptyQueue(Queue *q);
int peek(Queue *q);

int main()
{
    Queue q;
    q.ll.head = NULL;
    q.ll.tail = NULL;
    q.ll.size = 0;

    int item;
    printf("Enter item -1 quit\n");
    scanf("%d",&item);
    while(item != -1)
    {
        enqueue(&q,item);
        printf("Enter item -1 quit\n");
        scanf("%d",&item);
    }

    while(!isEmptyQueue(&q))
    {
        printf("Peek is %d\n",peek(&q));
        printf("dequeue item is %d\n",dequeue(&q));
    }
    return 0;
}
void enqueue(Queue *q,int item){
     //queue is first in first out
    insertNode(&(q->ll),q->ll.size,item);
    return;
}
int dequeue(Queue *q){
    //queue is first in first out
    int item;
    item = q->ll.head->item;
    removeNode(&(q->ll),0);
    return item;
}
int peek(Queue *q){
    int item;
    item = q->ll.head->item;
    return item;
}
int isEmptyQueue(Queue *q){
    if((q->ll).size == 0)
        return 1;
    else
        return 0;
}
void printLinkList(LinkedList *ll){
    listNode *temp;
    if(ll->head == NULL)
    {
        printf("Nothing to diplay\n");
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
    }
    return;
}
listNode *findNode(LinkedList *ll,int index){
    listNode *temp;
    if(ll->head == NULL)
    {
        printf("Empty nothing find\n");
        return NULL;
    }
    else if(index < 0 || index >= ll->size  )
    {
        printf("index out of range\n");
        return NULL;
    }
    else
    {
        temp = ll->head;
        while(index != 0)
        {
            if(temp == NULL)
                return NULL;
            temp = temp->next;
            index--;
        }
        return temp;
    }
    return NULL;
}
void insertNode(LinkedList *ll,int index,int item){
    listNode *temp,*cur,*pre;
    if(index < 0 || index > ll->size + 1)
    {
        printf("index out of range cant be inserted\n");
        return;
    }
    else if(index == 0  || ll->head == NULL)
    {
        cur = ll->head;
        temp = malloc(sizeof(listNode));
        temp->next = cur;
        temp->item = item;
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
    else if(index == ll->size)
    {
        pre = ll->tail; //previous tail
        temp = malloc(sizeof(listNode)); //mew tail
        temp->item = item;
        temp->next = NULL;
        pre->next = temp; //connect the new last node
        ll->tail = pre->next; //tail updated to new last node
        ll->size++;
        return;
    }
    // Find the nodes before and at the target position
	// Create a new node and reconnect the links
    else if((pre = findNode(ll,index - 1)) != NULL)
    {
        cur = pre->next;
        //new node between pre and cur
        temp = malloc(sizeof(listNode));
        temp->item = item;
        pre->next = temp;
        temp->next = cur;
        ll->size++;
        return;
    }
}
void removeNode(LinkedList *ll,int index){
    listNode *temp,*cur,*pre;
    if(ll->head == NULL)
    {
        printf("Empty nothing to remove\n");
        return;
    }
    else if(index < 0 || index >= ll->size )
    {
        printf("Index out of range cannot remove node\n");
        return;
    }
    else if(index == 0)
    {
        temp = ll->head; //to be remove
        cur = ll->head->next;
        ll->head = cur; //shift head to next node or null
        free(temp);
        ll->size--;
        if(ll->size == 0)
        {   //if last node remove head and tail are Null
            ll->tail = NULL;
        }
        return;
    }
    // Find the nodes before and after the target position
	// Free the target node and reconnect the links
    else if((pre = findNode(ll,index - 1)) != NULL)
    {
        // Removing the last node, update the tail pointer
        if(index == ll->size - 1)
        {
            //pre will be the new tail after removing last node
            temp = pre->next;
            ll->tail = pre;
            ll->tail->next = NULL; //after remove last node the new tail points to NUll
            free(temp);
        }
        else
        { //index not at 0 or last node
            temp = pre->next; //to be remove
            cur = temp->next;
            //temp is between pre and cur
            //temp to be remove
            pre->next = cur;
            free(temp);
        }
        ll->size--; //update the size after removing
    }
    return;
}

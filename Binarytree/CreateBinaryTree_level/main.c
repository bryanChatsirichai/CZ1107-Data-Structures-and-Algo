#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    struct _node *lchild;
    int data;
    struct _node *rchild;
    struct _node *next;
}ListNode;

typedef struct _linkedlist{
    int size;
    ListNode *head;
    ListNode *tail;
}LinkedList;

typedef struct _queue{
    LinkedList ll;

}Queue;

void enqueue(Queue *q,int value);
ListNode *dequeue(Queue *q);
int isEmpty(Queue *q);
ListNode *peek(Queue *q);

void insertNode(LinkedList *ll,int index,int value);
void display(LinkedList *ll);
ListNode *findNode(LinkedList *ll,int index);
ListNode * removeNode(LinkedList *ll,int index);

void create(Queue *q,LinkedList *root);
void preOrder(ListNode *cur);
int main()
{;
    ListNode *x;
    Queue q;
    q.ll.size = 0;
    q.ll.head = NULL;
    q.ll.head = NULL;

    LinkedList root;
    root.size = 0;
    root.head = NULL;
    root.tail = NULL;




    create(&q,&root);
    printf("root node value is %d\n",root.head->data);
    preOrder(root.head);
    return 0;
}
void preOrder(ListNode *cur){
    if(cur == NULL)
        return;
    else
    {
        printf("%d\n",cur->data);
        preOrder(cur->lchild);
        preOrder(cur->rchild);
    }

}



void create(Queue *q,LinkedList *root){
    int value;
    ListNode *p,*t,*c,*x;
    printf("Enter the root value: ");
    scanf("%d",&value);
    if(value == -1)
        return;
    enqueue(q,value); //the first node will be the root node

    root->head = q->ll.head;
    while( !isEmpty(q))
    { //if queue is not empty
        p = dequeue(q);
         //printf("queue head address %d\n",p);
        printf("Enter left child: ");
        scanf("%d",&value);
        if(value != -1)
            {
                enqueue(q,value)
                c = dequeue(q);
                p->lchild = c;
                p->rchild = NULL;

            }
        //p = dequeue(q);
        printf("Enter right child: ");
        scanf("%d",&value);
        if(value != -1)
            {
                enqueue(q,value)
                x = peek(q);
                p->rchild = x;
                p->rchild = NULL;

            }


    }

}
ListNode *peek(Queue *q){
    return (q->ll.head);

}


void enqueue(Queue*q,int value){
    insertNode(&(q->ll),q->ll.size,value);
}
ListNode *dequeue(Queue *q){
    return removeNode(&(q->ll),0);

}
int isEmpty(Queue *q){
    if(q->ll.size == 0)
    {
        printf("queue is empty\n");
        return 1; //empty
    }
    else
    {
        printf("Queue size is %d\n",q->ll.size);
        return 0;
    }

}

ListNode *findNode(LinkedList *ll,int index){
    ListNode *temp;
    if(ll->head == NULL || index < 0 || index > ll->size + 1)
        {
            printf("Error findNode\n");
            return NULL;
        }
    temp = ll->head;
    while(index > 0)
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
void display(LinkedList *ll){
    ListNode *temp;
    if(ll->head == NULL)
    {
        printf("list is empty");
        return;
    }
    temp = ll->head;
    printf("Current list nodes are: ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
printf("\n");
return;
}
void insertNode(LinkedList *ll,int index,int value){
    ListNode *pre,*cur,*temp;
    if(ll == NULL || index < 0 || index > ll->size + 1)
        return;
// If empty list or inserting first node, need to update head pointer
    if(ll->head == NULL || index == 0)
    {
        cur = ll->head;
        ll->head = malloc(sizeof(ListNode));
        if(ll->size == 0)
            ll->tail = ll->head;
        ll->head->data = value;
        ll->head->next = cur;
        ll->size++;
        return;
    }
    // Inserting as new last node
    if(index == ll->size)
    {
        pre = ll->tail;
        cur = pre->next;
        temp = malloc(sizeof(ListNode));
        temp->data = value;
        pre->next = temp;
        ll->tail = temp;
        ll->tail->next = cur;
        ll->size++;
        return;
    }
    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    if((pre = findNode(ll,index - 1)) != NULL)
    {
        if(pre)
        cur = pre->next;
        temp = malloc(sizeof(ListNode));
        temp->data = value;
        pre->next = temp;
        temp->next = cur;
        ll->size++;
        return;
    }


}
ListNode * removeNode(LinkedList *ll,int index){
   ListNode *pre,*cur,*temp;

// Highest index we can remove is size-1
    if(ll->head == NULL || index < 0 || index > ll->size + 1 )
    {
        printf("Error to remove node\n");
        return NULL;
    }
    // If removing first node, need to update head pointer
    if(index == 0)
    {
        temp = ll->head;
        ll->head = temp->next;
        //free(temp);
        ll->size--;
        if(ll->size == 0)
        {
            ll->tail = NULL;
        }
        return temp;
    }
    // Find the nodes before and after the target position
    // Free the target node and reconnect the links
    if ((pre = findNode(ll, index-1)) != NULL)
    {
        if(ll->size ==  index)
        {
            temp = ll->tail;
            ll->tail = pre;
            ll->tail = NULL;
            //free(temp);
            //return temp;
        }
        else
        {
            temp = pre->next;
            pre->next = temp->next;
        }
        ll->size--;
        return temp;

    }
}

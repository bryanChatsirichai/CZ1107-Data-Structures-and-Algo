#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    struct _node *lchild;
    struct _node *data;
    struct _node *rchild;
    struct _node *next;
    int value;
}ListNode;

typedef struct _linkedlist{
    int size;
    ListNode *head;
    ListNode *tail;
}LinkedList;

typedef struct _queue{
    LinkedList ll;

}Queue;

void enqueue(Queue *q,ListNode *node);
ListNode* dequeue(Queue *q);
int isEmpty(Queue *q);
ListNode* peek(Queue *q);

void insertNode(LinkedList *ll,int index,ListNode *node);
void display(LinkedList *ll);
ListNode *findNode(LinkedList *ll,int index);
void removeNode(LinkedList *ll,int index);

void create(Queue *q,ListNode **root);
void preOrder(ListNode *cur);
int main()
{
    Queue q;
    q.ll.size = 0;
    q.ll.head = NULL;
    q.ll.tail = NULL;

 printf("creating binary tree outside \n");
    ListNode *root;
    root = NULL;


    create(&q,&root);
    preOrder(root);
    return 0;
}
void preOrder(ListNode *cur){
    if(cur == NULL)
    {
        //printf("tree is empty");
        return;
    }

    else
    {
        printf("%d\n",cur->value);
        preOrder(cur->lchild);
        preOrder(cur->rchild);

    }

}



void create(Queue *q,ListNode **root){
    printf("creating binary tree\n");

    int value;
    ListNode *p,*t;
    printf("Enter the root value: ");
    scanf("%d",&value);
    if(value == -1)
        return;

    *root = malloc(sizeof(ListNode));
    (*root)->value = value;
    (*root)->lchild = NULL;
    (*root)->rchild = NULL;
    enqueue(q,*root); //the first node will be the root node

    while( !isEmpty(q))
    { //if queue is not empty
        p = dequeue(q);

        printf("Enter left child of %d: ",p->value);
        scanf("%d",&value);
        if(value != -1)
            {
                t = malloc(sizeof(ListNode));
                t->value = value;
                p->lchild = t;
                t->lchild = t->rchild = NULL;
                enqueue(q,t);
            }

        printf("Enter right child of %d: ",p->value);
        scanf("%d",&value);
        if(value != -1)
            {
                t = malloc(sizeof(ListNode));
                t->value = value;
                p->rchild = t;
                t->lchild = t->rchild = NULL;

                enqueue(q,t);

            }


    }
    return;

}
ListNode *peek(Queue *q){

    ListNode *value;
    value = (q->ll.head)->data;
    return value;

}


void enqueue(Queue*q,ListNode *node){
    insertNode(&(q->ll),q->ll.size,node);
}
ListNode *dequeue(Queue *q){
    ListNode *value;
    value = (q->ll.head)->data;
    removeNode(&(q->ll),0);
    return value;
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
        //printf("%d ",temp->data);
        temp = temp->next;
    }
printf("\n");
return;
}
void insertNode(LinkedList *ll,int index,ListNode *node){
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
        ll->head->data = node;
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
        temp->data = node;
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
        temp->data = node;
        pre->next = temp;
        temp->next = cur;
        ll->size++;
        return;
    }


}
void removeNode(LinkedList *ll,int index){
   ListNode *pre,*cur,*temp;

// Highest index we can remove is size-1
    if(ll->head == NULL || index < 0 || index > ll->size + 1 )
    {
        printf("Error to remove node\n");
        return;
    }
    // If removing first node, need to update head pointer
    if(index == 0)
    {
        temp = ll->head;
        ll->head = temp->next;
        free(temp);
        ll->size--;
        if(ll->size == 0)
        {
            ll->tail = NULL;
        }
        return ;
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
            free(temp);
            return ;
        }
        else
        {
            temp = pre->next;
            pre->next = temp->next;
        }
        ll->size--;
        return;

    }
}

#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BtNode;

typedef struct _qnode{
    BtNode *data; //address of tree node
    struct _qnode *next; //connect as a link list to other qNode
}qNode;

typedef struct _queue{
    qNode *head;
    qNode *tail;
    int size;
}Queue;

void preOrder(BtNode *cur);

void createTree(Queue *q,BtNode **root);

void enqueue(Queue *q,BtNode *tree);
BtNode *dequeue(Queue *q);
BtNode *peek(Queue *q);
int isQueueEmpty(Queue *q);

void printNode(Queue *q);
void insertqNode(Queue *q,BtNode *tree,int index);
qNode *findNode(Queue *q,int index);
void removeNode(Queue *q,int index);

int main()
{
  Queue q;
  q.size = 0;
  q.head = NULL;
  q.tail = NULL;

  BtNode *root;
  root = NULL;
  createTree(&q,&root);
  preOrder(root);

    return 0;
}
void preOrder(BtNode *cur){
    if(cur == NULL)
        return;
    else
    {
        printf("%d\n",cur->item);
        preOrder(cur->left);
        preOrder(cur->right);
    }

}
void createTree(Queue *q,BtNode **root){

    printf("Creating binary tree\n");
    int item; //btNode value
    qNode p; //qNode able take address of BtNode
    BtNode *t; //BtNode pointer
    printf("Enter the item Number\n");
    scanf("%d",&item);
    if(item == -1)
        return; //stop making new BtNodes
    *root = malloc(sizeof(BtNode)); //the main root node created
    (*root)->item = item; //set item to root node
    (*root)->left = NULL;
    (*root)->right = NULL;
    enqueue(q,*root);
    while(!isQueueEmpty(q))
    {
      p.data = dequeue(q); //address of BtNode first time is the main root node
      printf("Enter left child of %d: ",p.data->item);
      scanf("%d",&item);
      if(item != -1)
      {
          //Left side of BtNode
          t = malloc(sizeof(BtNode));
          t->item = item;
           p.data->left = t; //connect the BtNodes to left child
          t->left = t->right = NULL; //set use left and right to Null
          enqueue(q,t); //insert the BtNode address to the queue
      }
      printf("Enter right child of %d: ",p.data->item);
      scanf("%d",&item);
      if(item != -1)
      {printf("debug \n");
           //Right side of BtNode
          t = malloc(sizeof(BtNode));
          t->item = item;
          p.data->right = t; //connect the BtNodes to right child
          t->left = t->right = NULL; //set use left and right to Null
          enqueue(q,t); //insert the BtNode address to the queue
      }
    }
}
int isQueueEmpty(Queue *q){
    if(q->size == 0)
    {
        return 1; //empty return 1
    }
    else
    {
        return 0; //not empty return 0;
    }
}
BtNode *peek(Queue *q){
    BtNode *address;
    address = q->head->data;
    return address; //return address of the BtNode
}
BtNode *dequeue(Queue *q){
    BtNode *adress;
    adress = q->head->data;
    removeNode(q,0);
    return adress; //return address of the BtNode
}
void enqueue(Queue *q,BtNode *tree){
    insertqNode(q,tree,q->size);
}
void printNode(Queue *q){
    qNode *temp;
    if(q->head == NULL)
    {
        printf("List empty\n");
        return;
    }
    temp = q->head;
    while(temp != NULL)
    {
        printf("treeNode address is %d num is %d\n",temp->data,temp->data->item);
        temp = temp->next;
    }
printf("\n");
}
qNode *findNode(Queue *q,int index){
    qNode *temp;
    temp = q->head;
    if(q->head == NULL)
    {
        printf("Empty nothing to be found\n");
        return NULL;
    }
    while(index > 0)
    {
        temp = temp->next;
        if(temp == NULL)
        {
            printf("overshot\n");
            return NULL;
        }
        index--;

    }
return temp;
}
void insertqNode(Queue *q,BtNode *tree ,int index){
    qNode *pre,*cur,*temp;

    if(q == NULL || index < 0 )
    {
        printf("Insert qNode error 1\n");
        return;
    }
    if(q->head == NULL || index == 0) //insert from front
    {   printf("insert 1\n");
        cur = q->head;
        temp = malloc(sizeof(qNode));
        temp->next = cur;
        temp->data = tree;
        q->head = temp;
        if(q->size == 0)
        {
            q->tail = q->head;
        }
        q->size++;
        return;
    }
    // Inserting as new last node
    if(index == q->size)
    {   printf("insert 2\n");
        pre = q->tail;
        cur = pre->next;
        temp = malloc(sizeof(qNode));
        pre->next = temp;
        temp->next = cur;
        temp->data = tree;
        q->tail = temp;
        q->size++;
        return;
    }
	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
    if ((pre = findNode(q, index - 1)) != NULL){
            printf("insert \n");
        cur = pre->next;
        temp = malloc(sizeof(qNode));
        temp->data = tree;
        temp->next = cur;
        pre->next = temp;
        q->size++;
        return;

    }
}
void removeNode(Queue *q,int index){
    qNode *pre,*cur,*temp;
    if(q->head == NULL || index < 0 || index >= q->size)// Highest index we can remove is size-1
    {
        printf("Nothing to remove\n");
        return;
    }
    if(index == 0)// If removing first node, need to update head pointer
    {
        printf("remove option 1\n");
        temp = q->head;
        q->head = temp->next;
        free(temp);
        q->size--;
        if(q->size == 0)
        {
            q->tail = NULL;
        }
        return;
    }

    // Find the nodes before and after the target position
	// Free the target node and reconnect the links
    if ((pre = findNode(q, index - 1)) != NULL){

        if(index == q->size - 1)
        {printf("remove option 2\n");
            temp = q->tail;
            q->tail = pre;
            free(temp);
            q->tail->next = NULL;

        }
        else
        {printf("remove option 3\n");
            temp = pre->next;
            cur = temp->next;
            pre->next = cur;
            free(temp);

        }
        q->size--;
        return;

    }
}

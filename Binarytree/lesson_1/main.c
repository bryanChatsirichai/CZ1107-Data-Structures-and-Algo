#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
    int item;
    struct _btnode *left;
    struct _btnode *right;


}BTNode;

typedef struct _queueNode{
    BTNode *node;
    struct _queueNode *nextptr;
}qNode;

typedef struct _Queue{
    qNode *head;
    qNode *tail;
    int size;
}queue;



int max_side(int l,int r);
void TreeTraverse(BTNode *cur);
void PreOrder(BTNode *cur);
void InOrder(BTNode *cur);
void PostOrder(BTNode *cur);
int CountNode(BTNode *cur);
void findgrandchildren(BTNode *cur,int c,int k);
int NodeHeight(BTNode *cur);


void enqueue(queue *q,BTNode node);
void dequeue(queue *q);
void isEmpty(queue *q);

int main()
{




   BTNode root;
   root.item = 70;
   root.left = malloc(sizeof(BTNode));
   root.left->item = 31;
   root.left->right = NULL;
   root.left->left  =  malloc(sizeof(BTNode));
   root.left->left->item = 14;
   root.left->left->left = NULL;
   root.left->left->right = malloc(sizeof(BTNode));
   root.left->left->right->item = 23;
   root.left->left->right->left = NULL;
   root.left->left->right->right = NULL;


   root.right = malloc(sizeof(BTNode));
   root.right->item = 93;
   root.right->left = malloc(sizeof(BTNode));
   root.right->left->item = 73;
   root.right->left->left = NULL;
   root.right->left->right = NULL;

   root.right->right  =  malloc(sizeof(BTNode));
   root.right->right->item = 94;
   root.right->right->left = NULL;
   root.right->right->right = NULL;
   printf("Pre-Order\n");
   PreOrder(&root);
   printf("In-Order\n");
   InOrder(&root);
    printf("Post-Order\n");
    PostOrder(&root);
    printf("Total number of nodes %d\n",CountNode(&root));
    printf("grandchildren\n");
   findgrandchildren(&root,0,1); //c increment after passing every edge
    NodeHeight(&root);

    queue q;
    q.size = 0
    q.node = NULL;


    return 0;
}
int max_side(int l,int r){
    if(l >= r)
        return l;
    else
        return r;
}
void enqueue(queue *q,BTNode node){




}
void TreeTraverse(BTNode *cur){
    if(cur == NULL)
        return;
    else
    {
        printf("%d\n",cur->item);
        TreeTraverse(cur->left);
        TreeTraverse(cur->right);
        return;
    }
}
void PreOrder(BTNode *cur){
    if(cur == NULL)
        return;
    else
    {
        printf("%d\n",cur->item);
        TreeTraverse(cur->left);
        TreeTraverse(cur->right);
        return;
    }
}
void InOrder(BTNode *cur){
    if(cur == NULL)
        return;

    else{
        InOrder(cur->left);
        printf("%d\n",cur->item);
        InOrder(cur->right);
        return;


    }


}
void PostOrder(BTNode *cur){
    if(cur ==NULL)
        return;
    else{
        PostOrder(cur->left);
        PostOrder(cur->right);
        printf("%d\n",cur->item);
            return;
    }
}
int CountNode(BTNode *cur){
    int r,l;
    if(cur == NULL)
        return 0;
    else{
       l =  CountNode(cur->left);
       r = CountNode(cur->right);
        return l + 1 + r; // returning 1 to the node above
    }
}
void findgrandchildren(BTNode *cur,int c,int k){
    if(cur == NULL)
        return;
    if(c == k)
    {
        printf("%d\n",cur->item);
    }
    if(c < k)
    {
        findgrandchildren(cur->left,c+1,k);
        findgrandchildren(cur->right,c+1,k);
    }

}
int NodeHeight(BTNode *cur){
    int l,r,c;

    if(cur == NULL)
        return -1;
    else{

       l =  NodeHeight(cur->left);
       r = NodeHeight(cur->right);
       c = max_side(l,r) + 1;
       printf("Node %d is height is %d\n",cur->item,c);
        return c;
    }
}

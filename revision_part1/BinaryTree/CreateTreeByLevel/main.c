#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
    int item;
    struct _btnode *left;
    struct _btnode *right;
}btNode;

typedef struct _qnode{
//stores the btnode in a linked list way
    btNode *data; //address of tree node
    struct _qnode *next; //connect as a link list to other qNode
}qNode;

typedef struct _queue{
    //queue structure
    int size;
    qNode *head;
    qNode *tail;
}Queue;

///Functions///
void printNode(Queue *q);
void insertqNode(Queue *q,btNode *tree_node,int index);
qNode *findNode(Queue *q,int index);
void removeNode(Queue *q,int index);

///Queue functions///
int isQueueEmpty(Queue *q);
void enqueue(Queue *q,btNode *tree_node);
//returns the address of the btnode
btNode *peek(Queue *q);
btNode *dequeue(Queue *q);

///Binary Tree functions///
void createTree(Queue *q,btNode **Ptr_root);//use double pointer as we want to change the root not the local var pointer
void preOrder(btNode *root);
void inOrder(btNode *root);
void postOrder(btNode *root);
int smallestValue(btNode *node);
int hasGreatGrandchild(btNode *node);
int isBST(btNode *node, int min, int max);
int main()
{
    Queue q;
    q.size = 0;
    q.head = NULL;
    q.tail = NULL;

    btNode *root;
    root = NULL; //root pointer after creating should point to a btnode which is the main root
    createTree(&q,&root);
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    printf("smallest value in the tree is %d\n",smallestValue(root));
    hasGreatGrandchild(root);
    if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");
    return 0;


    return 0;
}

int isBST(btNode *node, int min, int max){
	if(node == NULL)
        return 1; //consider empty tree a bst
        //if is a bst will traverse till leaf node and return 1 upwards
    if(node->item < max && node->item > min)
    {   //if wrong will return  back up 0;
        //due to and condition one 0 will return 0 all the way back up and stop the recursion;
        //printf("node %d\n",node->item);
        return (isBST(node->left,min,node->item) && (isBST(node->right,node->item,max)));
    }
    else //node->item >= max || node->item <= min) //the node's value should belong to (min, max).
        return 0;
}

int hasGreatGrandchild(btNode *node){
    /*The depth of a node is the number of edges from the node to the tree's root node.
    A root node will have a depth of 0.

    The height of a node is the number of edges on the longest path from the node to a leaf.
    A leaf node will have a height of 0. */
    //node has height of 1 from leaf node has child
    //node has height of 2 from leaf node has grandchild
    //node has height of 3 from leaf node has great grandchild.
    int l,r,height;

    if(node == NULL)
        return -1; //to offset so leaf node heigh
    else
    {
        l = hasGreatGrandchild(node->left);
        r = hasGreatGrandchild(node->right);
        if(l >= r)
            height = l + 1;
        else if(l < r)
            height = r + 1;
        if(height >= 2)
        {
            printf("node %d has a great grand child\n",node->item);
        }
        return height;
    }
}

int smallestValue(btNode *node) {
	int l, r,min;
    if(node == NULL)
        return 10000000; //finding smallest so null return big number to not affect the search
    else
    {   //check return value from left and right child and the node itself
        //return the smallest upward
        l = smallestValue(node->left);
        r = smallestValue(node->right);
        min = node->item;
        //must use if cannot else if
        //suppose l < min but r can still be < l
        //so check all
        if(l < min)
            min = l;
        if(r < min)
            min = r;
        return min;
    }
}

void preOrder(btNode *root){
    if(root == NULL)
        return;
    else
    {
        printf("%d ",root->item);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(btNode*root){
    if(root == NULL)
        return;
    else
    {
        inOrder(root->left);
        printf("%d ",root->item);
        inOrder(root->right);
    }
}
void postOrder(btNode *root){
    if(root == NULL)
        return;
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->item);
    }

}
void createTree(Queue *q,btNode **ptr_root){//use double pointer as we want to change the root not the local var pointer
    btNode *temp,*p;
    int item;
    printf("creating binary tree by level\n");
    printf("Enter item value (-1) to quit\n");
    scanf("%d",&item);
    if(item == -1)
        return;
    else
    {
        //creating the root
        temp = (btNode *)malloc(sizeof(btNode));
        temp->item = item;
        temp->left = temp->right = NULL;
        *ptr_root = temp;
        enqueue(q,temp);
        while(!isQueueEmpty(q))
        {
            //stop when queue empty as no child nodes being created
            //temp to keep track of creating new node
            //q to keep track of the parent node of the new node for connection
            /*after root node we will do by level if the child node has left and right child node as well
            we will create them dynamically and store them in the stack.
            Since stack is first in first out it will mimic by level ,after asking all nodes at current level
            if have left or right we will go to the next level */
            p = dequeue(q);
            printf("Enter %d left child value (-1) to quit\n",p->item);
            scanf("%d",&item);
            if(item != -1)
            {
                temp = (btNode*)malloc(sizeof(btNode));
                temp->item = item;
                temp->left = temp->right = NULL;
                p->left = temp;
                enqueue(q,temp);

            }
            printf("Enter %d right child value (-1) to quit\n",p->item);
            scanf("%d",&item);
            if(item != -1)
            {
                temp = (btNode*)malloc(sizeof(btNode));
                temp->item = item;
                temp->left = temp->right = NULL;
                p->right = temp;
                enqueue(q,temp);
            }
        }
    }
}
int isQueueEmpty(Queue *q){
    if(q->size == 0)
        return 1;//empty return 1
    else
        return 0;//not empty return 0;
}
void enqueue(Queue *q,btNode *tree_node){
    //recall queue is first in first out
    //enqueue the address of the tree_nodes
    insertqNode(q,tree_node,q->size);
    return;
}
btNode *dequeue(Queue *q){
    //recall queue is first in first out
    //dequeue the address of the tree_nodes
    btNode *btNode_address;
    btNode_address = q->head->data;
    removeNode(q,0);
    return btNode_address;
}
btNode *peek(Queue *q){
    btNode *btNode_address;
    btNode_address = q->head->data;
    return btNode_address;
}
void printNode(Queue *q){
    qNode *temp;
    if(q->head == NULL && q->size == 0)
    {
        printf("Empty queue linklist has no qnodes\n");
    }
    else
    {
        temp = q->head;
        printf("Adress of btnodes are\n");
        while(temp != NULL)
        {
             printf("treeNode address is %d num is %d\n",temp->data,temp->data->item);
            temp = temp->next;
        }
        return;
    }
}
qNode *findNode(Queue *q,int index){
   qNode *temp;

    if(q->head == NULL)
    {
        printf("Empty cannot find anything\n");
        return NULL;
    }
    else if(index < 0 || index >= q->size )
    {
        printf("index out of range cannot find\n");
        return NULL;
    }
    else
    {
        temp = q->head;
        while(index != 0)
        {
           if(temp == NULL)
                {
                    printf("overshot\n");
                    return NULL;
                }
           temp = temp->next;
           index--;
        }
        return temp;
    }
return NULL;
}
void insertqNode(Queue *q,btNode *tree_node,int index){
    qNode *pre,*cur,*temp;
    if(index < 0 || index > q->size + 1)
    {
        printf("Insert error\n");
        return;
    }
    else if(q->head == NULL || index == 0)
    {
        cur = q->head;
        temp = malloc(sizeof(qNode));
        temp->next = cur;
        temp->data = tree_node;
        q->head = temp;
        if(q->size == 0)
        {   //if only 1 node
            q->tail = q->head;
        }
        q->size++;
        return;
    }
    else if(index == q->size )
    {   //insert at last node
        // need update tail pointer
        temp = malloc(sizeof(btNode));
        temp->data = tree_node;
        temp->next = NULL;
        pre = q->tail;
        pre->next = temp;
        q->tail = pre->next;
        q->size++;
        return;
    }
        // Find the nodes before and at the target position
	// Create a new node and reconnect the links
    else if((pre = findNode(q,index - 1)) != NULL)
    {
        cur = pre->next;
        temp = malloc(sizeof(btNode));
        temp->data = tree_node;
        temp->next = cur;
        pre->next = temp;
        q->size++;
        return;
    }
}
void removeNode(Queue *q,int index){
    qNode *pre,*cur,*temp;
    if(q->head == NULL || q->size <= 0)
    {
        printf("Empty nothing remove\n");
        return;
    }
    else if(index < 0 || index >= q->size)
    {
        printf("index out of range cannot remove\n");
        return;
    }
    else if(index == 0)
    {
        //update heat to next node
        temp = q->head;
        cur = temp->next;
        q->head = cur;
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
    else if((pre = findNode(q,index - 1)))
    {
         //pre will be the new tail after removing last node
        if(index == q->size - 1)
        {
             temp = q->tail;
             pre->next = NULL;
             q->tail = pre;
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
        q->size--; //update size
        return;
    }
}

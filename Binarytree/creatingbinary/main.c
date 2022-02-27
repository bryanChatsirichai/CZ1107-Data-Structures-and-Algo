#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
 struct Node *lchild;
 int data;
 struct Node *rchild;
}Node;

Node *crete(); //create the binary tree
void preOrder(Node *cur);

int main()
{
    Node *ptrRoot;
    ptrRoot = NULL;
    ptrRoot = crete(); //return the address of the root node
    preOrder(ptrRoot);
}
Node *crete(){
    int data;
    Node *newNode; //'local' variable
    newNode = (Node*)malloc(sizeof(Node)); //type cast
    printf("Enter data: (-1 for no node)");
    scanf("%d",&data);
    if(data == -1)
    {
        return NULL;
    }
        newNode->data = data; //set the data of the node
        printf("Enter left child of %d ",data);
        newNode->lchild = crete();
        printf("Enter right child of %d ",data);
        newNode->rchild = crete();
        return newNode;
}
void preOrder(Node *cur){
    if(cur == NULL)
        return;
    else
    {
        printf("%d\n",cur->data);
        preOrder(cur->lchild);
        preOrder(cur->rchild);
    }


}

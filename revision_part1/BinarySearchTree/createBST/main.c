#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int main()
{
    int item;

    BTNode *root;
    root = NULL;


    printf("Insert node (-1) quit\n");
    scanf("%d",&item);
    while(item != -1)
    {
        insertBSTNode(&root,item);
        printf("Insert node (-1) quit\n");
        scanf("%d",&item);
    }
    printBSTInOrder(root);
    return 0;
}

void printBSTInOrder(BTNode *node){
    if(node == NULL)
        return;
    else
    {
        printBSTInOrder(node->left);
        printf("%d ",node->item);
        printBSTInOrder(node->right);
    }
}

void insertBSTNode(BTNode **node, int value){

    BTNode *r,*p,*t;
    if(*node == NULL)
    {
        p = malloc(sizeof(BTNode));
        p->item = value;
        p->left = p->right = NULL;
        *node = p;
        return;
    }
    else
    {
        r = NULL; //tail behind t
        t = *node;
        while(t != NULL)
        {
            r = t;
            if(t->item == value)
                return;

            else if(value < t->item)
            {
                t = t->left;
            }
            else if(value > t->item)
            {
                t = t->right;
            }
        }

        if(t == NULL)//means can insert
        {
            p = malloc(sizeof(BTNode));
            p->item = value;
            p->left = p->right = NULL;
            if(p->item < r->item)
                r->left = p;
            else
                r->right = p;
        }
        return;
    }

}

//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMin(BTNode *p);

///////////////////////////////////////////////////////////////////////

int main(){
	int i=0;

	BTNode *root=NULL;

	//question 1
	do{
		printf("input a value you want to insert(-1 to quit):");

		scanf("%d",&i);
		if (i!=-1)
			insertBSTNode(&root,i);
	}while(i!=-1);

	//question 2
	printf("\n");
	printBSTInOrder(root);

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");

	//test findmin
	printf("The min in bst is %d\n",findMin(root)->item);


	//question 4
	do{
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&i);
		if (i!=-1)
		{
			root=removeBSTNode(root,i);
			printBSTInOrder(root);
		}
	}while(i!=-1);


	return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{
    BTNode *t;
	if(*node == NULL)
    {
        t = malloc(sizeof(BTNode));
        t->item = value;
        t->left = t->right = NULL;
        *node = t;
        return;
    }
    else
    {
        if(value == (*node)->item)
        {
            printf("item already inside\n");
            return;
        }

        else if(value < (*node)->item)
        {
            insertBSTNode(&((*node)->left),value);
        }
        else   if(value > (*node)->item)
        {
            insertBSTNode(&((*node)->right),value);
        }
    }
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
    BTNode *t;
	if(node == NULL)
        return;
    else
    {
        printBSTInOrder(node->left);
        printf("%d ",node->item);
        printBSTInOrder(node->right);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{//return 1 if the BT is a BST, and 0 otherwise.
	BTNode *temp;

	if(node == NULL)
        return 1;
    else
    {
        if(node->item > min && node->item < max)
        {
            return ( (isBST(node->left,min,node->item)) && (isBST(node->right,node->item,max)));
        }
        else
            return 0;
    }

}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value)
{
    BTNode *temp = NULL,*p = NULL;
    if(node == NULL)
        return NULL;
    else if(value < node->item)
        node->left = removeBSTNode(node->left,value);
    else if(value > node->item)
        node->right = removeBSTNode(node->right,value);
    else//found
    {
        //case 1, no child
        if(node->left == NULL && node->right == NULL)
        {
             printf("case 1\n");
            temp = node;
            node = NULL;
            free(temp);
        }
        //case 2, 1 child
        else if(node->left != NULL && node->right == NULL)
        {
            printf("case 2a\n");
            temp = node;
            node = node->left;
            free(temp);
        }
        else if(node->left == NULL && node->right != NULL)
        {
            printf("case 2a\n");
            temp = node;
            node = node->right;
            free(temp);
        }
        //case 3 ,2 child
        else if(node->left != NULL && node->right != NULL)
        {
           //find min in right subtree
            printf("case 3\n");
           temp = findMin(node->right);
           node->item = temp->item;
           node->right = removeBSTNode(node->right,temp->item);

        }
    }
    return node;//if node is not modify in any of the 3 case is returns the same address like not doing anything

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *findMin(BTNode *p)
{   //min has no left child as if have means have something smaller than it
    if(p->left == NULL)
       return p;
    else
    {
        findMin(p->left);
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

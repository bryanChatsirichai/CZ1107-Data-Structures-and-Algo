#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMax(BTNode *p);

int main()
{
    int item;

    BTNode *root;
    root = NULL;

    //question 1
    printf("Insert node (-1) quit\n");
    scanf("%d",&item);
    while(item != -1)
    {
        insertBSTNode(&root,item);
        printf("Insert node (-1) quit\n");
        scanf("%d",&item);
    }
	//question 2
	printf("\n");
	printBSTInOrder(root);

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");

    //question 4
    printf("max is %d\n",findMax(root)->item);

	do{
        printBSTInOrder(root);
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&item);
		if (item != -1)
		{
			root = removeBSTNode(root,item);
			//printBSTInOrder(root);
		}
	}while(item!=-1);
//printBSTInOrder(root);
    return 0;
}

BTNode *removeBSTNode(BTNode *node, int value){
    //return pointer to root node as root may change
    //what we pass to function is local copy of root address/
    //if root address change we need return it back
    BTNode *temp,*p;
    if(node == NULL)
        {
            printf("Item cannot be found\n");
            return NULL;
        }

	if (value < node->item) //go left tree
		 {  printf("go left\n");
		     node->left = removeBSTNode(node->left, value);
		 }
	else if (value > node->item) //go right tree
		 {  printf("go right\n");
		     node->right = removeBSTNode(node->right, value);
		 }
    else //(node->item == value)
    {
    //found a match
    //the recursive return will be modify if needed
    //if node cant be found and deleted will just set them the same

      ///case 1 no child///
      if(node->left == NULL && node->right == NULL)
      {
          printf("case 1\n");
          temp = node;
          free(temp);
          node = NULL;
      }
      ///case 2 one child///
      else if(node->left == NULL)
      {
           printf("case 2a\n");
           temp = node;
           node = node->right;
           free(temp);
      }
      else if(node->right == NULL)
      {
           printf("case 2b\n");
           temp = node;
           node = node->left;
           free(temp);
      }
      ///case 3 two children///
      /*
      find max in left tree/subtree
      copy the value in targeted node
      deleted duplicate from left subtree
      */
      else if(node->left != NULL && node->right != NULL)
      {
          printf("case 3\n");
          p = findMax(node->left);
          node->item = p->item;
          node->left = removeBSTNode(node->left,p->item);

      }
    }
    return node;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *findMax(BTNode *p)
{   /*if a tree or subtree has a min value it wont have a left child
    as if have a left child there something smaller.
    For max case it wont have a right child. */
    if(p->right != NULL)
        findMax(p->right);
    else
        return p;
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


    if(*node == NULL)
    {
        *node = malloc(sizeof(BTNode));
        (*node)->left = (*node)->right = NULL;
        (*node)->item = value;
        return;
    }
    else
    {
        if(value == (*node)->item) //value will not be inserted
        {
            printf("Already exists in the BST\n");
            return;
        }

        else if(value < (*node)->item) //value is smaller than the node
        {
            insertBSTNode(&(*node)->left,value);
        }
        else if(value >  (*node)->item)//value is larger than the node
        {
            insertBSTNode(&(*node)->right,value);
        }
    }

}
int isBST(BTNode *node, int min, int max)
// the item stored in node has to be smaller than max and larger than min
{//check if its a bst
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

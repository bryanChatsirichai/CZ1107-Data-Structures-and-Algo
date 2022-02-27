#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200 //The number digit limitation

typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

typedef struct _node{
     BTNode* item;
     struct _node *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void deleteTree(BTNode **root);

void createExpTree(BTNode** root,char* prefix);
void printTree(BTNode *node);
void printTreePostfix(BTNode *node);
double computeTree(BTNode *node);

void push(Stack *sPtr,  BTNode* item);
int pop(Stack *sPtr);
BTNode *peek(Stack s);
int isEmptyStack(Stack s);

int main()
{
    char prefix[SIZE];
    BTNode* root=NULL;

    printf("Enter an prefix expression:\n");
    gets(prefix);

    createExpTree(&root, prefix);

    // printf("The Infix Expression:\n");
    printTree(root);
    printf("\n");
    //printf("The Postfix (Reverse Polish) Expression:\n");
    printTreePostfix(root);
    printf("\n");
    //printf("Answer ");
    printf("%.2f\n", computeTree(root));
    deleteTree(&root);
    return 0;
}

void createExpTree(BTNode** root,char* prefix)
{
 Stack s;
 s.head = NULL;
 s.size = 0;
 char *ptrstr;
 ptrstr = prefix;
 int power = 10;
 int num = 0;
 BTNode *temp,*new_node;
 if(*prefix == '\0')
    return;

 while(1)
 {


     if(*root == NULL)
     {
         new_node = malloc(sizeof(BTNode));
         new_node->left = NULL;
         new_node->right = NULL;
         //new_node->item = *ptrstr;
         *root = new_node;
     }

    else
     {

             //printf("num is %d\n",num);
             while(*ptrstr != '\0')
             {
                 if(*ptrstr >= '0' && *ptrstr <= '9')
                 {
                     num = (num * power) + (*ptrstr - 48);
                        if (*(ptrstr + 1) < '0' || *(ptrstr + 1) > '9')
                        {
                            //insert the number
                           //printf("num is %d\n",num);

                            //reset the number
                            //power = 10;
                            //num = 0;
                            break;
                        }

                 }
                 else if(*ptrstr != ' ')
                 {
                    num = *ptrstr;
                    break;
                    //printf("operator is %c\n",num);
                    //num = 0;
                 }
                ptrstr++;
            }
            //printf("operator is %d\n",num);
            (*root)->item = num;
            //printf("root item is %c\nss",(*root)->item);
            if(*ptrstr != '+' && *ptrstr != '-' && *ptrstr != '/' && *ptrstr != '*')
                {
                   return;

                }

                createExpTree(&(*root)->left,ptrstr + 1);
            while(*ptrstr >= '0' && *ptrstr <= '9')
            {   printf("adding \n");
                ptrstr++;
            }
                createExpTree(&(*root)->right, ptrstr + 1);
                return;


     }

    }
 }

void printTree(BTNode *node){
    if(node == NULL)
        return;
    else
    {
        if(node->left == NULL && node->right == NULL)
            printf("%d",node->item);
        else
            printf("%c",node->item);
        printTree(node->left);
        printTree(node->right);
    }
}


void printTreePostfix(BTNode *node){
   //Write your code here

}

double computeTree(BTNode *node){
//Write your code here
}

void push(Stack *sPtr, BTNode *item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

BTNode *peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

void deleteTree(BTNode **root){
    BTNode* temp;
    if(*root !=NULL)
    {
        temp = (*root)->right;
        deleteTree(&((*root)->left));
        free(*root);
        *root = NULL;
        deleteTree(&temp);
    }
}

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

void reverseStack(Stack *s,Stack *s2);
char* insertnodes(Stack *s,BTNode **root,char *prefix);


Stack s;
Stack s2;


int main()
{
    char prefix[SIZE];
    BTNode* root=NULL;



    printf("Enter an prefix expression:\n");
    gets(prefix);

    createExpTree(&root, prefix);

    //printf("stack size is %d\n",s.size);
    //printf("s top is %d\n",s.head->item->item);

     //printf("Reverse\n");
    reverseStack(&s,&s2);
    //printf("After reverse\n");

     //printf("stack size is %d\n",s2.size);
     //printf("s2 top is %d\n",s2.head->item->item);



    insertnodes(&s2,&root,prefix);
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

void reverseStack(Stack *s,Stack *s2)
{

    BTNode *temp;
    while(!isEmptyStack(*s))
    {
        //printf("test\n");
        temp = peek(*s);
        pop(s);
        //printf("temp is %d\n",temp->item);
        push(s2,temp);
    }
    //printf("s size is empty %d\n",s->size);

}


char* .(Stack *s2,BTNode **root,char* prefix)
{

    int power = 10;
    int num = 0;
    int is_num = -1;

    if(*prefix == '\0')
        return '\0';
    while(1)
    {
        char *q = '\0';
        if(*root == NULL)
        {
            *root = peek(*s2);
            pop(s2);

        }
        else
        {


            while(*prefix != '\0')
                     {
                         if(*prefix >= '0' && *prefix <= '9')
                         {
                             num = (num * power) + (*prefix - 48);
                                if (*(prefix + 1) < '0' || *(prefix + 1) > '9')
                                {

                                   //printf("num is %d\n",num);
                                   is_num = 1;
                                   break;
                                    //power = 10;
                                   // num = 0;
                                }

                         }
                         else if(*prefix != ' ')
                         {
                            //num = *prefix;
                            //printf("operator is %c\n",num);
                            is_num = 0;
                            break;
                            //num = 0;
                         }
                        prefix++;
                    }

                if(is_num == 1)
                {
                    return prefix;
                }
                else
                {


                   q = insertnodes(s2,&(*root)->left,prefix + 1);
                    //printf("between\n");
                    //if(q == '\0')
                        //printf("yes\n");
                   q = insertnodes(s2,&(*root)->right,q + 1);
                        //if(q == '\0')
                            //printf("yes2\n");

                   return q;
                }

        }

    }
}
void createExpTree(BTNode** root,char* prefix)
{
 char *ptrstr;
 ptrstr = prefix;
 int power = 10;
 int num = 0;
 BTNode *temp,*new_node;
 if(*prefix == '\0')
    return;


             //printf("num is %d\n",num);
            while(*ptrstr != '\0')
             {
                 if(*ptrstr >= '0' && *ptrstr <= '9')
                 {
                     num = (num * power) + (*ptrstr - 48);
                        if (*(ptrstr + 1) < '0' || *(ptrstr + 1) > '9')
                        {

                           //printf("num is %d\n",num);
                           temp = malloc(sizeof(BTNode));
                           temp->item = num;
                           temp->left = temp->right = NULL;
                           push(&s,temp);
                            power = 10;
                            num = 0;
                        }

                 }
                 else if(*ptrstr != ' ')
                 {
                    num = *ptrstr;
                    temp = malloc(sizeof(BTNode));
                    temp->item = num;
                    temp->left = temp->right = NULL;
                    //printf("operator is %c\n",num);
                    push(&s,temp);
                    num = 0;
                 }
                ptrstr++;
            }



}

void printTree(BTNode *node){
    if(node == NULL)
        return;
    else
    {
        printTree(node->left);
        if(node->left == NULL && node->right == NULL)
            printf("%d ",node->item);
        else
            printf("%c ",node->item);


        printTree(node->right);
    }
}


void printTreePostfix(BTNode *node){
    if(node ==  NULL)
        return;
    else
    {
        printTreePostfix(node->left);
        printTreePostfix(node->right);
        if(node->left == NULL && node->right == NULL)
            printf("%d ",node->item);
        else
            printf("%c ",node->item);
    }
}

double computeTree(BTNode *node){
    double l,r;
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return node->item;
    else
    {
        l = computeTree(node->left);
        r = computeTree(node->right);
        if(node->item == 42) // mutiply
            return l * r;
        else if(node->item == 43) //addition
            return l + r;
        else if(node->item == 45) //subtraction
            return l - r;
        else if(node->item == 47) //division
            return l / r;
    }
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

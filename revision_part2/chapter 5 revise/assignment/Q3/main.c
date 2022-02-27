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
char * myfunc(BTNode **root,char *prefix,Stack *s);

void reverseStack(Stack *s, Stack *s2);
Stack s;
Stack s2;

int main()
{
    char prefix[SIZE];
    BTNode* root=NULL;

    printf("Enter an prefix expression:\n");
    gets(prefix);

    createExpTree(&root, prefix);
    reverseStack(&s,&s2);
    //reverseStack2(&s); //cannot work
    printf("\n");
    //printf("top is %d\n",peek(s)->item);
    //pop(&s);
    //printf("top is %d\n",peek(s)->item);
    myfunc(&root,prefix,&s2);

    printf("The Infix Expression:\n");
    printTree(root);
    printf("\n");

    printf("The Postfix (Reverse Polish) Expression:\n");
    printTreePostfix(root);
    printf("\n");

    printf("Answer ");
    printf("%.2f\n", computeTree(root));
    deleteTree(&root);
    return 0;
}

char *myfunc(BTNode **root,char *prefix,Stack *s)
{
    char *p = NULL;
    if(*prefix == '\0')
        return '\0';
    else
    {
        BTNode *newnode;
        while(1)
        {
            //around 2 loop per recursion 1 to insert another to go to the else
            //think of insert node then update position along the string
            if(*prefix == ' ')
            {
                prefix++;
            }
            if(*root == NULL)
            {
                newnode = peek(*s);
                pop(s);
                *root = newnode;

            }
            else
            {
                if(*prefix >= '0' && *prefix <= '9')
                {
                    while(*(prefix+1) >= '0' && *(prefix+1) <= '9')
                    {
                        prefix++;
                    }
                    return prefix; //update
                }

                p = myfunc(&(*root)->left,prefix + 1,s);

                p = myfunc(&(*root)->right,p + 1,s);

                return p;
            }
        }
    }


}


void reverseStack(Stack *s, Stack *s2)
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


void createExpTree(BTNode** root,char* prefix)
{
    char *ptrstr;
    ptrstr = prefix;
    int power = 10;
    int num = 0;
    BTNode *temp,*new_node;
    if(*prefix == '\0')
        return;
    while(*prefix != '\0')
    {
        if(*prefix >= '0' && *prefix <= '9')
        {
            num = 0;
            while(*prefix >= '0' && *prefix <= '9')
            {
                num = (num * power * 1) + (*prefix - 48);
                prefix++;
            }
            new_node = malloc(sizeof(BTNode));
            new_node->left = NULL;
            new_node->right = NULL;
            new_node->item = num;
            push(&s,new_node);
        }
        else if(*prefix == ' ')
        {
            //ignore space
            prefix++;
        }
        else
        {
            new_node = malloc(sizeof(BTNode));
            new_node->left = NULL;
            new_node->right = NULL;
            new_node->item = *prefix;
            push(&s,new_node);
            prefix++;
        }
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
   if(node == NULL)
   {
       return;
   }
   else
   {
       printTreePostfix(node->left);
       printTreePostfix(node->right);
       if(node->left == NULL && node->right == NULL)
       {
           printf("%d ",node->item);
       }
       else
       {
           printf("%c ",node->item);
       }

   }

}

double computeTree(BTNode *node){
    //postfix
    double sum,left,right;
    int symbol;
    if(node == NULL)
    {
        return 0;
    }
    else if(node->left == NULL && node->right == NULL)
    {
        return node->item;
    }
    else
    {
        left = computeTree(node->left);
        right = computeTree(node->right);
        symbol = node->item;
        if(symbol == '+')
            sum = left + right;

        else if(symbol == '-')
            sum = left - right;

        else if(symbol == '*')
            sum = left * right;

        else if(symbol == '/')
            sum = left / right;

        return sum;

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

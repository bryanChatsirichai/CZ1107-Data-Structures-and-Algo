#include <stdio.h>
#include <stdlib.h>

typedef struct _arraynode
{
    int *itemArray; // pointer to array of integers
    int sizeArray;
    struct _arraynode *next;
}ArrayNode;

typedef struct _arraylist{
   int size; //the size of a possible sequence
   ArrayNode *head;
} ArrayList;

typedef struct _listnode
{
    int item;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int sum; //the number of possible sequences
   int size;
   ListNode *head;
} LinkedList;

// You should not change the prototypes of these functions
//////LinkedList///////////////////////////////////////////
int insertNode(LinkedList *ll, int index, int coin);
int removeNode(LinkedList *ll, int index);
ListNode *findNode(LinkedList ll, int index);
void removeAllItems(LinkedList *ll);
void printLL(LinkedList* ll);
void insertArrayList(ArrayList* al,int num,int size,int alsize,int k);
///////////////////////////////////////////////////

void sumToC(LinkedList* ll, int C, ArrayList* al);
int main()
{
    int C;
    printf("Enter a number:\n");
    scanf("%d",&C);

    LinkedList ll;
    ll.head = NULL;
    ll.sum = 0;
    ll.size = 0;
    ArrayList al;
    al.head = NULL;
    al.size = 0;

    sumToC(&ll,C,&al);

	//printing all possible sequences

    ArrayNode* temp;
    int i,j;
    temp = al.head;
    for(i=0;i<al.size;i++){

        for(j=0;j<temp->sizeArray;j++)
        {

            printf(" %d ",temp->itemArray[j]);
        }

        printf("\n");

        temp = temp->next;
    }

    return 0;
}

void printLL(LinkedList* ll)
{
    if(ll->head == NULL)
        return;
    else
    {
        ListNode *temp;
        temp = ll->head;
        while(temp != NULL)
        {
            printf("%d ",temp->item);
            temp = temp->next;
        }
        printf("\n");
    }
}
void insertArrayList(ArrayList* al,int num,int size,int alsize,int k)
{
    ArrayNode *temp;
    temp = al->head;
    int i = 1;
    if(al == NULL)
        return;
    while(i<alsize)
    {
        printf("i is %d alsize is %d\n",i,alsize);
        temp = temp->next;
        printf("next\n");
        i++;
    }
    printf("before\n");
    if(al->head == NULL)
    {

        printf("create1\n");
        temp = malloc(sizeof(ArrayNode));
        temp->sizeArray = size;
        temp->itemArray = malloc(sizeof(int)*size);
        al->head = temp;
        al->head->next = NULL;
    }
    else if(temp ==  NULL)
    {

        printf("create2\n");
        temp = malloc(sizeof(ArrayNode));
        temp->sizeArray = size;
        temp->next = NULL;
        temp->itemArray = malloc(sizeof(int)*size);

    }

    temp->itemArray[k] = num;
}


void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   ListNode *temp ,*temp2;
   ArrayNode *ptr_array_node;
   int i = 1;
   int j;
   int k;
   int total = 0,index;
   int sum = 0,count = 1;
    ptr_array_node = al->head;

   for(i;i<=C;i++)
   {
       j = i;
       index = 0;
       sum = 0;
       count = 1;
       for(j;j<=C;j++)
       {
           insertNode(ll,index,j);
           index++;
       }
       temp = ll->head;
       while(ll->size != 0)
       {
           printf("%d->",temp->item);
           sum = sum + temp->item;
           if(sum == C)
           {
                total++;
               printf("count %d\n",count);
               printf("found\n");
                temp2 = ll->head;
                al->size++;
                  printf("size of al list %d\n",al->size);
                for(k = 0;k<count;k++)
                {
                    insertArrayList(al,temp2->item,count,al->size,k);
                    printf("insert %d \n",temp2->item);
                    temp2 = temp2->next;
                }
                if(ll->size >=2)
               {
                   removeNode(ll,1);
               }
                else
               {
                   removeNode(ll,0);
               }
               sum = 0;
               temp = ll->head;
               count = 1;
               printf("\n");
               continue;
           }
           else if(sum > C)
           {

               if(ll->size >=2)
               {
                   removeNode(ll,1);
                   temp = ll->head;
               }
               else
               {
                   removeNode(ll,0);
               }
               sum = 0;
               count = 1;
                printf("\n");
               continue;
           }
           else if(ll->size == 1)
           {
               printf("last node\n");
              if(sum == C)
              {
                  printf("count %d\n",count);
                  al->size++;
                  count = 1;
                  printf("size of al list %d\n",al->size);
                printf("found\n");
                for(k = 0;k<count;k++)
                {
                    insertArrayList(al,temp2->item,count,al->size,k);
                    printf("insert %d ",temp2->item);
                    temp2 = temp2->next;
                }
              }
            removeNode(ll,0);

           }
           temp = temp->next;
            count++;
       }

        printf("\nnext starting\n");
      // printLL(ll);
       removeAllItems(ll);
   }
}
///////////////////////////////////////////////////////
int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size)
		return 0;

        if (index == 0){
		cur = ll->head;
		ll->head = (ListNode*) malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->sum += value;
		ll->size++;
		return 1;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->sum += value;
		ll->size++;
		return 1;
	}

	return 0;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index > ll->size)
		return 0;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		ll->sum -= ll->head->item;
		free(ll->head);
		ll->head = cur;
		ll->size--;
		return 1;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(*ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return 0;

		cur = pre->next;
		ll->sum -= cur->item;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 1;
	}

	return 0;
}

ListNode *findNode(LinkedList ll, int index){

	ListNode *temp;

	if (index < 0 || index >= ll.size)
		return NULL;

	temp = ll.head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL){
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
	ll->sum =0;
}


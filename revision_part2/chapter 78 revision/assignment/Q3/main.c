#include <stdio.h>
#include <stdlib.h>

typedef struct _arraynode
{
    int *itemArray;
    int sizeArray;
    struct _arraynode *next; ///array of pointers to LL
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
///////////////////////////////////////////////////

void sumToC(LinkedList* ll, int C, ArrayList* al);

void myfunc(LinkedList* ll, int C, ArrayList* al,int arr[],int length_arr,int index);
void printLL(LinkedList *ll);
void insert(LinkedList *ll,ArrayList *al);

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
            printf(" %d ",temp->itemArray[j]);
        printf("\n");
        temp = temp->next;
    }

    return 0;
}

void insert(LinkedList *ll,ArrayList *al)
{
    ListNode *temp;
    if(ll->head == NULL)
        return;
    else if(al->head == NULL)
    {
        //first time
        ArrayNode *anode;
        int *num_arr;
        anode = malloc(sizeof(ArrayNode));
        num_arr = malloc(sizeof(int)*(ll->size));
        al->head = anode;
        anode->next = NULL;
        anode->sizeArray = ll->size;
        anode->itemArray = num_arr;
        temp = ll->head;
        int i = 0;
        while(temp != NULL)
        {
            num_arr[i] = temp->item;
            temp = temp->next;
            i++;
        }
        return;
    }
    else
    {
        //not the first insertion
        int i = 0 ,*num_arr;
        ArrayNode *anode,*new_anode;
       anode = al->head;
        while(anode->next != NULL)
        {

            anode = anode->next;
        }
        new_anode = malloc(sizeof(ArrayNode));
        num_arr = malloc(sizeof(int)*(ll->size));
        new_anode->next = NULL;
        new_anode->sizeArray = ll->size;
        new_anode->itemArray = num_arr;
        anode->next = new_anode;

        temp = ll->head;
        while(temp != NULL)
        {
            num_arr[i] = temp->item;
            temp = temp->next;
            i++;
        }
        return;

    }
}

void myfunc(LinkedList* ll, int C, ArrayList* al,int arr[],int length_arr,int index)
{
    if(C == 0)
    {
       //printLL(ll);
        insert(ll,al);
        al->size++;
        return;
    }
    else if(C < 0)
    {
        return; //backtrack
    }
    else
    {
        int remainder;


        for(index;index<length_arr;index++)
        {
            remainder = C - arr[index];
            //printf("remainder is %d\n",remainder);
            insertNode(ll,ll->size,arr[index]);
            myfunc(ll,remainder,al,arr,length_arr,index + 1); //check as far as possible

            ///backtrack
           //remainder = C + arr[index]; //add back to check with next index
           //printf("remainder2 is %d\n",remainder);
            removeNode(ll,ll->size-1); //remove last node
            //printf("%d\n",C-arr[index + 1]);
            if(C - arr[index + 1] < 0)
                {
                    //printf("no point continue backtrack\n");
                    return;
                }
        }

    }
}

void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   int i,count = 1;
   int *arr = malloc(sizeof(int)*C); //create list of int from 1 to C
   for(i=0;i<C;i++)
   {
       arr[i] = count;
       count++;
   }
   int length = C;
   printf("length is %d\n",C);
   myfunc(ll,C,al,arr,length,0);

   return;




}
///////////////////////////////////////////////////////
void printLL(LinkedList *ll)
{
    if(ll->head == NULL)
        return;
    else
    {
        ListNode *temp = ll->head;
        while(temp != NULL)
        {
            printf("%d ",temp->item);
            temp = temp->next;
        }
        printf("\n");
    }
}

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


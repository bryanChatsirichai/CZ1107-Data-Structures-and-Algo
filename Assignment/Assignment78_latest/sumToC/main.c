#include <stdio.h>
#include <stdlib.h>

typedef struct _arraynode
{
    int *itemArray;
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
///////////////////////////////////////////////////

void printLL(LinkedList *ll);
void sumToC(LinkedList* ll, int C, ArrayList* al,int start,int arr[],int length);
void insertAL(ArrayList* al,LinkedList *ll);
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

    int arr[C];
    int k,length_of_array = C;
    int num = 1;
    for(k = 0;k<C;k++)
    {
        arr[k] = num;
        num++;
    }
     sumToC(&ll,C,&al,0,arr,length_of_array);
    printf("before printing\n");
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
void printLL(LinkedList * ll)
{
    ListNode *temp;
    if(ll->head == NULL)
        return;
    else
    {
        temp = ll->head;
        while(temp != NULL)
        {
            printf("%d ",temp->item);
            temp = temp->next;
        }
        printf("\n");
    }
    return;
}
void insertAL(ArrayList* al,LinkedList *ll)
{

    if(al->head == NULL)
    {
        ArrayNode *anode;
        anode = malloc(sizeof(ArrayNode));
        anode->itemArray = malloc(sizeof(int)*(ll->size));
        anode->sizeArray = ll->size;
        ListNode *temp;
        temp = ll->head;
        int index = 0;
        while(temp != NULL)
        {
            //printf("temp num %d\n",temp->item);
            anode->itemArray[index] = temp->item;
            temp = temp->next;
            //printf("index %d\n",index);
            printf("inserted %d\n",anode->itemArray[index]);
            index = index + 1;

        }
        al->head = anode;
        anode->next = NULL;
        return;
    }
    else
    {
        ArrayNode *anode,*temp_anode;
        anode = al->head;
        temp_anode = malloc(sizeof(ArrayNode));
        temp_anode->itemArray = malloc(sizeof(int)*(ll->size));
        temp_anode->sizeArray = ll->size;
        ListNode *temp;
        temp = ll->head;
        int index = 0;
        while(temp != NULL)
        {
            //printf("temp num %d\n",temp->item);
            temp_anode->itemArray[index] = temp->item;
            temp = temp->next;
            //printf("index %d\n",index);
            printf("inserted %d\n",temp_anode->itemArray[index]);
            index = index + 1;
        }
        temp_anode->next = NULL;
        anode = al->head;
        while(anode->next != NULL)
        {
            anode = anode->next;
        }
        anode->next = temp_anode;
        return;

    }
}

void sumToC(LinkedList* ll, int C, ArrayList* al,int start,int arr[],int length)
{
    if(C == 0)
    {   //subset of numbers able to form C
        //insert to arraylist
        printLL(ll);
        al->size++;
        insertAL(al,ll);


        return;
    }
    else if(C < 0)
    {
        return;
    }
    else
    {
        int i = start,remainder;
        for(i;i<length;i++)
           {
                insertNode(ll,ll->size,arr[i]);
                remainder = C - arr[i];
                sumToC(ll,remainder,al,i+1,arr,length);
                removeNode(ll,ll->size-1);
           }
            if(C - arr[i + 1] < 0)
            {
                //if overshot and fail means next number will fails as i+1 > i, thus no point recursive calling
                //C - i > c - (i+1)
                return;
            }

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


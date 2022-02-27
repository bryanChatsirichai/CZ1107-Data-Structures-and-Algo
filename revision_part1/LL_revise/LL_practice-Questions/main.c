////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////


typedef struct _listnode{
	int num;
	struct _listnode *next;
} ListNode;
typedef struct _linkedlist{
	ListNode *head;
	int size;
} LinkedList;
typedef struct _dbllistnode{
	int num;
	struct _dbllistnode *pre;
	struct _dbllistnode *next;
} DblListNode;

////////////////////////////////////////////////////////////////////
////////////
int removeNode(ListNode **ptrHead, int index);
int removeNode2(LinkedList *ll, int index);
int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList);
int duplicateReverse(ListNode *head, ListNode **ptrNewHead);

void printList(ListNode *head);
ListNode * findNode(ListNode *head, int index);
int insertNode(ListNode **ptrHead, int index, int value);


// these are for the practice questions
int moveMaxToFront(ListNode **ptrHead);
int concatenate(ListNode **ptrHead1, ListNode *head2);
int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2);
int combineAlternating2(ListNode **ptrHead, ListNode *head1, ListNode *head2);
int insertDbl(DblListNode **ptrHead, int index, int value);
void printDblList(DblListNode *head);
void removeDblList(DblListNode **ptrhead,int index);

////////////////////////////////////////////////////////////////////
////////////

int main()
{
	int i;
	ListNode *head = NULL;
	ListNode *dupRevHead = NULL;
	ListNode *oddHead = NULL;
	ListNode *evenHead = NULL;
	ListNode *list1Head = NULL, *list2Head = NULL;
	ListNode *combAltHead = NULL;
	DblListNode *dblHead = NULL;
	LinkedList llist;
	int size = 0;

	//build a linked list
	if (insertNode(&head, 0, 6) == 0) size++;
	if (insertNode(&head, 0, 4) == 0) size++;
	if (insertNode(&head, 0, 2) == 0) size++;
	printf("After inserting 3 values.");
	printList(head);


	//removeNode(): question 1
	if (removeNode(&head, 3) == 0) size--;//this one can't be removed.
	if (removeNode(&head, 1) == 0) size--;
	if (removeNode(&head, 0) == 0) size--;

	printf("\nafter remove using removeNode(), ");
	printList(head);

	//insert some nodes
	if (insertNode(&head, 2, 3) == 0) size++; // this one can't be inserted.
	if (insertNode(&head, 1, 1) == 0) size++;
	if (insertNode(&head, 0, 0) == 0) size++;

	printf("\nafter insert, ");
	printList(head);

	//removeNode2(): question 2
	llist.head = head;
	llist.size = size;
	removeNode2(&llist, 2);
	removeNode2(&llist, 0);
	removeNode2(&llist, 0);
	head = llist.head;


	printf("\nafter remove using removeNode2(), ");
	printList(llist.head);
	// empty linked list now

	//split(): question 3
	for (i = 1; i <10; i++)//build a new linked list
		insertNode(&head, 0, i);
	printf("\n\ninsert 1-9 to the linked list,");
	printList(head);
	printf("split the current list, results:\n");
	split(head, &evenHead, &oddHead);
	printf("the even list");
	printList(evenHead);
	printf("\nthe odd list");
	printList(oddHead);

	//duplicateReverse(): question 4
	printf("\n");
	printList(head);
	duplicateReverse(head, &dupRevHead);
	printf("After duplicateReverse(),");
	printList(dupRevHead);

	////////////////////////////////////////////////////////////////////////
	//the following are for the PRACTICE QUESTIONS

	printf("\n\nNow for the practice questions");

	//1.moveMaxToFront()
	printf("\n************** moveMaxToFront *******************\n");
	printList(dupRevHead);
	moveMaxToFront(&dupRevHead);
	printf("after moveMaxToFront()");
	printList(dupRevHead);

	//2. concatenate()
	printf("\n************** concatenate() *******************\n");
	concatenate(&head, dupRevHead);
	printf("concatenate(current list, duplicate reverse list)\n  ");
	printList(head);

	//3.combineAlternating()
	printf("\n************** combineAlternating() *******************\n");
	for (i = 3; i > 0; i--)				//build linked list 1
		insertNode(&list1Head, 0, i);
	for (i = 13; i > 10; i--)			//build linked list 2
		insertNode(&list2Head, 0, i);
	printf("List 1:");
	printList(list1Head);
	printf("List 2: ");
	printList(list2Head);
	combineAlternating(&combAltHead, list1Head, list2Head);
	printf("After combineAlternating(): ");
	printList(combAltHead);
    combineAlternating2(&combAltHead, list1Head, list2Head);
	printf("After combineAlternating2(): ");
	printList(combAltHead);

	//4. insertDbl()
	printf("\n************** insertDbl() *******************\n");
	printf("insertDbl()\nDoubly-linked list: ");
	insertDbl(&dblHead, 0, 10);
	insertDbl(&dblHead, 0, 20);
	insertDbl(&dblHead, 1, 30);
	insertDbl(&dblHead, 2, 40);
	printDblList(dblHead);
	removeDblList(&dblHead,0); //remove by index number
    removeDblList(&dblHead,12);
     removeDblList(&dblHead,2);

	printDblList(dblHead);
	return 0;
}

////////////////////////////////////////////////////////////////////
////////////

void printList(ListNode *head){
	ListNode *cur = head;

	if (cur == NULL)
		return;

	printf("the current linked list is:\n");
	while (cur != NULL){
		printf("%d ", cur->num);
		cur = cur->next;
	}
	printf("\n");
}

void printDblList(DblListNode *head){
	//get the last node on first loop
	//last node points to null but a null can point back to last node
	//tail pointer is use to get the last node upon exiting first loop


	DblListNode *tail = NULL;
	if (head == NULL)
        return;
	while (head != NULL){
		printf("%d ", head->num);
        tail = head;
		head = head->next;
	}
	printf("\n");
	/*
	printf("Reversing Double Linked list: ");
    while(tail != NULL)
    {
        printf("%d ",tail->num);
        tail = tail->pre;
    }
    printf("\n");
    */
}

ListNode * findNode(ListNode *head, int index){
	if (head == NULL || index < 0) return NULL;
	while (index > 0){
		head = head->next;
		if (head == NULL)
			return NULL;
		index--;
	}
	return head;
}


int insertNode(ListNode **ptrHead, int index, int value){
	ListNode *pre, *cur;
	// If empty list or inserting first node, need to update head pointer
	if (*ptrHead == NULL || index == 0){
		cur = *ptrHead;
		*ptrHead = malloc(sizeof(ListNode));
		(*ptrHead)->num = value;
		(*ptrHead)->next = cur;
		return 0;
	}
	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ptrHead, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->num = value;
		pre->next->next = cur;
		return 0;
	}
	return -1;
}

////////////////////////////////////////////////////////////////////
////////////

int removeNode(ListNode **ptrHead, int index){
    ListNode *pre,*cur,*temp;

    //check if list is empty
    if(*ptrHead == NULL)
        return -1;

    // If removing first node, need to update head pointer
    if(index == 0)
    {
        temp = *ptrHead;
        (*ptrHead) = temp->next;
        free(temp);
        return 0;
    }
    if((pre = findNode(*ptrHead,index - 1)) != NULL)
    {
        if(pre->next == NULL)
            return -1;
        temp = pre->next;
        cur = temp->next;
        pre->next = cur;
        free(temp);
        return 0;
    }

    return -1; //if somehow nothing is remove
}

////////////////////////////////////////////////////////////////////////////////
////////////

int removeNode2(LinkedList *ll, int index) {

	ListNode *pre,*cur,*temp;
	if(ll == NULL || index < 0 || index >= ll->size)
        return -1;
    if(index == 0)
    {
        temp = ll->head;
        ll->head = temp->next;
        free(temp);
        ll->size--;
        return 0;
    }
    if((pre = findNode(ll->head,index - 1))!= NULL)
    {
        if(pre->next == NULL)
            return -1;
        else
        {
            temp = pre->next;
            cur = temp->next;
            pre->next = cur;
            free(temp);
            ll->size--;
            return 0;
        }
    }
    return -1;
}



int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList)
{
    ListNode *pre,*cur,*temp;
    int evenSize = 0 , oddSize = 0;
    if(head == NULL)
        return -1 ; //main LL is empty
    else
    {
        temp = head; //iterate the linklist once
        while(temp != NULL)
        {
            if(temp->num % 2 == 0)
            {
                //num is even
                insertNode(ptrEvenList,evenSize,temp->num);
                evenSize++; //increase to the next index
            }
            else
            {
                //num is odd
                insertNode(ptrOddList,oddSize,temp->num);
                oddSize++;
            }
            temp = temp->next;
        }
    }
    return 0;
}

int duplicateReverse(ListNode *head, ListNode **ptrNewHead){
    ListNode *pre,*cur,*temp;
    if(head == NULL)
        return -1; //list is empty nothing to duplicate
    else
    {
        temp = head;
        //iterate the main LL once
        while(temp != NULL)
        {
            insertNode(ptrNewHead,0,temp->num);
            temp = temp->next;
        }
    }
    return 0;
}

////////////////////////////////////////////////////////////////////
////////////

int moveMaxToFront(ListNode **ptrHead){
    ListNode *pre,*cur,*temp,*maxNode,*premaxNode;
    if(*ptrHead == NULL)
        return -1; //list is empty
    else if((*ptrHead)->next == NULL)
        return 0; //list only 1 node
    else
    {
        //set cur to point to the first node
        cur = *ptrHead;
        //set first node to be the max
        maxNode = cur;
        pre = NULL; //tail behind the cur
        while(cur != NULL)
        {
            if(maxNode->num < cur->num)
            {
                maxNode = cur;
                premaxNode = pre;
            }
            pre = cur;
            cur = cur->next;
        }

        cur = maxNode->next;
        premaxNode->next = cur;
        maxNode->next = *ptrHead;
        *ptrHead = maxNode;

        return 0;

    }
}


int concatenate(ListNode **ptrHead1, ListNode *head2){

	ListNode *temp;
	// Both lists empty, let's return a -1 error value
	if (*ptrHead1 == NULL && head2 == NULL)
		return -1;
    //second list is empty
    if(head2 == NULL)
        return -1;
    //first empty but second not
    //set first to just point to second list
    if(*ptrHead1 == NULL && head2 != NULL)
        {
            *ptrHead1 = head2;
            return 0;
        }
    // Traverse the first list to get to the last node
	// Notice we check for the value of the next pointer for the current node

	temp = *ptrHead1;
	while(temp->next !=  NULL)
    {
        //temp should be at the last node of first list
        temp = temp->next;
    }
    temp->next = head2;
    return 0;

}
int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2){
    int count = 0; //keep even head 1 odd head 2
    ListNode *sort,*temp,*ptr1,*ptr2;
    //both empty
    if(head1 == NULL && head2 == NULL)
        return -1;
    if(head1 != NULL && head2 == NULL)
    {
        //if only 1 list has node
        *ptrHead = head1;
        return 0;
    }
    if(head1 == NULL && head2 != NULL)
    {
        //if only 1 list has node
        *ptrHead = head2;
        return 0;
    }
    else
    {
        ptr1 = head1;
        ptr2 = head2;
        (*ptrHead) = ptr1; //set headptr;
        ptr1 = ptr1->next;
        sort = (*ptrHead); //new list control thus head pointer remains at first node
        count++;
        while(ptr1 != NULL && ptr2 != NULL)
        {
            if(count % 2 == 0)
            {
                sort->next = ptr1; //connection
                sort = ptr1; //shift newhead forward
                ptr1 = ptr1->next; //shift to next in list1

            }
            else if(count % 2 != 0)
            {
                sort->next = ptr2; //connection
                sort = ptr2; //shift newhead forward
                ptr2 = ptr2->next; //shift to next in list2
            }
            count++; //alternate control
        }

        //if one of the list end early append the rest to the end
        if(ptr1 == NULL)
        {
            sort->next = ptr2;
        }
        if(ptr2 == NULL)
        {
            sort->next = ptr1;
        }

        return 0;
    }

    return -1; //nothing happen
}
int combineAlternating2(ListNode **ptrHead, ListNode *head1, ListNode *head2){
    //malloc instead of playing pointer
    ListNode *temp;
    if (head1 == NULL && head2 == NULL)
        return -1;
	// If both remaining lists are empty, we're done
	// We know that at least one of the lists has a remaining node inside this while loop
	// Check in pairs each cycle: List #1, then List #2
    while(head1 != NULL || head2 != NULL)
    {
        if(*ptrHead == NULL) //base case
        {
            if(head1 != NULL)
            {
                *ptrHead = malloc(sizeof(ListNode));
                (*ptrHead)->num = head1->num;
                (*ptrHead)->next = NULL;
                temp = (*ptrHead);
                head1 = head1->next;
            }
             if(head2 != NULL)
            {
                temp->next = malloc(sizeof(ListNode));
                temp = temp->next;
                temp->num = head2->num;
                temp->next = NULL;
                head2 = head2->next;
            }
        }
        else
        {
            if(head1 != NULL)
            {
                temp->next = malloc(sizeof(ListNode));
                temp = temp->next;
                temp->num = head1->num;
                temp->next = NULL;
                head1 = head1->next;
            }
            if(head2 != NULL)
            {
                temp->next = malloc(sizeof(ListNode));
                temp = temp->next;
                temp->num = head2->num;
                temp->next = NULL;
                head2 = head2->next;
            }
        }


    }
    return 0;
}

int insertDbl(DblListNode **ptrHead, int index, int value){
    DblListNode *temp,*pre,*cur;
    if(index == 0 || *ptrHead == NULL)
    {// If empty list or inserting first node, need to update head pointer
        temp = malloc(sizeof(DblListNode));
        temp->num = value;
        temp->next = (*ptrHead);
        temp->pre = NULL;
       if(*ptrHead != NULL)
       {    //suppose headnode already exit
           (*ptrHead)->pre = temp;
       }
        (*ptrHead) = temp;
        return 0;
    }
    // Find the nodes before and at the target position
	// We don't have a version of findNode that accepts DblListNode inputs
	// For now, duplicate the findNode() code in here
    else
    {
        pre = *ptrHead;
        while(index > 1) //need off set get pre node
        {
            pre = pre->next;
            index--;
        }
        if(pre != NULL)
        {
            cur = pre->next;
            //connecting new node
            temp = malloc(sizeof(DblListNode));
            temp->num = value;
            temp->next = cur;
            temp->pre = pre;

            //setting the bi direction
            //the case where insert node at last index
            //temp points to null but a null cant point back to last node;
            if(cur!= NULL)
               {  //node after temp points back to temp

                cur->pre = temp;
               }
            pre->next = temp;
            return 0;

        }
    }
}

void removeDblList(DblListNode **ptrhead,int index)
{
    DblListNode *pre,*cur,*temp;
    int count = 0;
    if(*ptrhead == NULL)
    {
        printf("empty nothing remove\n");
        return;
    }
    if(index == 0)
    {
        temp = *ptrhead; //to be remove
        printf("To be remove %d\n",temp->num);
        (*ptrhead) = (*ptrhead)->next; //head points to next node or null is no more nodes
        if((*ptrhead) != NULL)
        {   //if after remove at index 0 there is another node to take it place
            //if head is Null it cant point to somewhere
            (*ptrhead)->pre = NULL;
        }
        //printf("head now is %d\n",(*ptrhead)->num);
        free(temp);
        //if index 0 the only node head points top NUll list is empty
    }
    else
    {
        temp = *ptrhead; //node to be remove at this index
        for(int i = 0;i < index ;i++)
        {
            temp = temp->next;

            if(temp == NULL)
            {
                printf("Overshot\n");
                return;
            }
        }
        printf("to be remove %d\n",temp->num);
        pre = temp->pre; //before removed node
        cur = temp->next;//after removed node
        //break removed node connection
        temp->next = NULL;
        temp->pre = NULL;
        pre->next = cur;
        //if last node remove it is Null thus cannot point to anything
        if(cur != NULL)
        {
            cur->pre = pre;
        }
        free(temp);
    }
return;
}
///////////////////////////////////////

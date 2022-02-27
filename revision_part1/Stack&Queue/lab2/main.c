//////////////////////////////////////////////////////////////////////////////////////////////

#include "stdio.h"
#include <stdlib.h>

//////////////////////////////////   linked list //////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
	int size;
	ListNode *head;
	ListNode *tail;
} LinkedList;

////////////////////////////////// stack    //////////////////////////////////////////////
typedef struct stack{
	LinkedList ll;
} Stack;

//////////////////////////////////// queue ////////////////////////////////////////////

typedef struct _queue{
	LinkedList ll;
} Queue;

////////////////////////////////////////////////////////////////////////////////
void printList(ListNode *head);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

//////////////////////////////////////////////////

void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

//////////////////////////////////////////////////

void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int isEmptyQueue(Queue *s);

///////////////////////////////////////////////////////////////
// four questions
void removeUntil(Stack *s, int value);
void recursiveReverse(Queue *q);
int palindrome(char *word);
int balanced(char *expression);

//////////////////////////////////////////////////////////////////
/////

int main()
{
	Stack s;
	Queue q;
	int item[] = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };
	int i;
	char *word1 = "MadaM";
	char *word2 = "Superman in the sky";

	//for question 1
	//initialize the stack
	s.ll.head = NULL;
	s.ll.size = 0;
	s.ll.tail = NULL;

	for (i = 0; i<11; i++)
		push(&s, item[i]);

	printList(s.ll.head);
	removeUntil(&s, 5);
	printList(s.ll.head);

	//for question 2
	//initialize the queue
	q.ll.head = NULL;
	q.ll.size = 0;
	q.ll.tail = NULL;

	for (i = 0; i<10; i++)
		enqueue(&q, i);
	printList(q.ll.head);
	recursiveReverse(&q);
	printList(q.ll.head);

	//for question 3
	printf("%d\n",palindrome(word1)); //*word1="A man a plan a canal Panama";
	printf("%d\n",palindrome(word2));// *word2="Superman in the sky";


	//for question 4
	if (balanced("()")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	if (balanced("[()]")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	if (balanced("{[]()[]}")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	if (balanced("[({{)])")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	return 0;
}

////////////////////////////////////////////////////////////////
//Question 1

void removeUntil(Stack *s, int value){
    int check;
    while(!isEmptyStack(s))
    {
        check = peek(s);
        if(check != value)
            pop(s);
        else
            break;
    }
    return;
}

////////////////////////////////////////////////////////////
//Question 2

void recursiveReverse(Queue *q){
    int item;
    if(isEmptyQueue(q))
       return;
    else
    {
        item = dequeue(q);
        recursiveReverse(q);
        enqueue(q,item);
    }

}

////////////////////////////////////////////////////////////
//Question 3

int palindrome(char *word){
    //word is pass by reference pointer local
    //stack is filo
    //queue fifo
    int length = 0;
    char top,bottom; //top be stack bottom be queue
    Stack s;
    s.ll.head = NULL;
    s.ll.tail = NULL;
    s.ll.size = 0;
    Queue q;
    q.ll.head = NULL;
    q.ll.tail = NULL;
    q.ll.size = 0;

    while(*word != '\0')
    {   //printf("char is %c\n",*word);
        if(*word != ' ') //ignore space
        {
            push(&s,*word);
            enqueue(&q,*word);
        }
        word++; //increase word to next indec
        length++;
    }

    //Stack and queue both contain the same words
    //so using pop is from the top and dequeue from the front
    //we just need to compaired half each for even length half+1 for odd length;
    //but since both contain same word the odd is correct so check half from top and bottom only
    length = length / 2; //floor division
    while(length != 0)
    {
        top = pop(&s);
        bottom = dequeue(&q);
        if(bottom != top)
        {
            return -1; //half way exit means fail
        }
        length--;

    }
    return 0; //reach here means pass
}



////////////////////////////////////////////////////////////
//Question 4

int balanced(char *expression){
    //balance return 1 not balance return
    //use stack as filo the top of the stack when push must equal the mirror
	Stack s;
	char symbol;
     s.ll.head = NULL;
     s.ll.tail = NULL;
     s.ll.size = 0;
     printf("%s\n",expression);
     //balance return 1 not balance return
    //use stack as filo the top of the stack when push must equal the mirror
     //push in 1 side of the symbol when seen
     //when the mirror image is seen
     //pop the stack is top must be == to the mirror to be balance else fail
     //the pused top must be the mirror of what is being checked
    while(*expression != '\0')
    {
        if(*expression == '(' || *expression == '[' || *expression == '{')
            {
                push(&s,*expression);
            }
        else if(*expression == ')')
        {
            symbol = pop(&s);
            if(symbol != '(')
            {
                return -1;
            }
        }
        else if(*expression == ']')
        {
            symbol = pop(&s);
            if(symbol != '[')
            {
                return -1;
            }
        }
        else if(*expression == '}')
        {
            symbol = pop(&s);
            if(symbol != '{')
            {
                return -1;
            }
        }
        expression++;
    }
    if(isEmptyStack(&s)) //pop out all if mirror thus return 0
        return 0;
    else
        return -1;

}

////////////////////////////////////////////////////////////////////////////////

void push(Stack *s, int item){
	insertNode(&(s->ll), 0, item);
}

int pop(Stack *s){
	int item;

	item = ((s->ll).head)->item;
	removeNode(&(s->ll), 0);
	return item;
}

int peek(Stack *s){
	return ((s->ll).head)->item;
}

int isEmptyStack(Stack *s){
	if ((s->ll).size == 0)
		return 1;
	return 0;
}


////////////////////////////////////////////////////////////////////////////////

void enqueue(Queue *q, int item){
	insertNode(&(q->ll), q->ll.size, item);
}

int dequeue(Queue *q){
	int item;
	item = ((q->ll).head)->item;
	removeNode(&(q->ll), 0);
	return item;
}

int isEmptyQueue(Queue *q){
	if ((q->ll).size == 0)
		return 1;
	return 0;
}



////////////////////////////////////////////////////////////////////////////////

void printList(ListNode *head){

	ListNode *temp = head;

	if (temp == NULL)
		return;

	while (temp != NULL){
		printf("%d ", temp->item);
		temp = temp->next;
	}
	printf("\n");
}

ListNode * findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

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

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->tail = ll->head;
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}

	// Inserting as new last node
	if (index == ll->size){
		pre = ll->tail;
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		ll->tail = pre->next;
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));

		if (index == ll->size)
			ll->tail = pre->next;

		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}

int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		if (ll->size == 0)
			ll->tail = 0;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		// Removing the last node, update the tail pointer
		if (index == ll->size - 1){
			ll->tail = pre;
			free(pre->next);
			pre->next = NULL;
		}
		else{
			cur = pre->next->next;
			free(pre->next);
			pre->next = cur;
		}
		ll->size--;
		return 0;
	}

	return -1;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;
typedef ListNode StackNode;

typedef struct _graph{
    int V;
    int E;
    ListNode **list;
}Graph;

typedef ListNode QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

typedef struct _stack
{
	int size;
	StackNode *head;
} Stack;

int CC (Graph g);

void printGraphList(Graph );

// You should not change the prototypes of these functions
void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
//////////////////////////////////
void reset(Graph g,int arr[]);
int check(Graph g,int arr[]);
void bfs(Graph g,int visited[],int v);

int main()
{
    Graph g;
    int i,j;
    ListNode *temp;

    printf("Enter the number of vertices:\n");
    scanf("%d",&g.V);

    g.list = (ListNode **) malloc(g.V*sizeof(ListNode *));

    for(i=0;i<g.V;i++)
        g.list[i] = NULL;

    printf("Enter two vertices which are adjacent to each other:\n");
    while(scanf("%d %d",&i,&j)==2)
    {
        i=i-1;

        if(g.list[i]==NULL){
            g.list[i] = (ListNode *)malloc(sizeof(ListNode));
            g.list[i]->vertex = j;
            g.list[i]->next = NULL;
        }
        else{
            temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = g.list[i];
            temp->vertex = j;
            g.list[i] = temp;
        }
        g.E++;
        printf("Enter two vertices which are adjacent to each other:\n");
    }
    scanf("%*c");

    int res = CC(g);
    if(res ==1)
        printf("The graph is strongly connected.\n");
    else
        printf("The graph is not strongly connected.\n");

    printGraphList(g);
    return 0;
}
void bfs(Graph g,int visited[],int v)
{
    ListNode *temp;
    Stack s;
    s.head = NULL;
    s.size = 0;
    int start,i,cur,neighbour,is_visited = 0;
    visited[v] = 1;
    push(&s,v);
    while(!isEmptyStack(s))
    {
        cur = peek(s);
        printf("cur is %d\n",cur +1);
        temp = g.list[cur];
        is_visited = 0; //reset
        while(temp != NULL)
        {

            is_visited = 0;
            neighbour = temp->vertex - 1;//offset
            //printf("neightbour is %d\n",neighbour);
            if(visited[neighbour] != 1)
            {
                visited[neighbour] = 1;
                push(&s,neighbour);
                is_visited = 1;
                break;
            }
            temp = temp->next;
        }
        //cur node no neighbours or visited all
        if(is_visited == 0)
        {
            //printf("%d ",cur + 1);
            pop(&s);
        }

    }
}

int CC (Graph g)
{
    int *visited,i,result;
    visited = malloc(sizeof(int)*g.V);
    reset(g,visited); //initialize the array
    for(i = 0;i<g.V;i++)
    {   //need check all possible nodes as starting and can visit all other nodes 1 fail all fail
        printf("starting from node %d\n",i+1);
        bfs(g,visited,i);
        printf("\n");
        result = check(g,visited);
        if(result == 0)
        {
            return -1;
        }
        reset(g,visited); //reset for new starting position
    }

    return 1; //all the way means strongly connected
}
void reset(Graph g,int arr[])
{
    int i;
    for(i=0;i<g.V;i++)
    {
        arr[i] = -1;
    }
    return;
}
int check(Graph g,int arr[])
{
    int i ;
    for(i=0;i<g.V;i++)
    {
        if(arr[i] == -1)
        {
            return 0; //fail 1 time no need check already since not strongly connected
        }
    }
    return 1; //all the way mean strongly connected
}
void printGraphList(Graph g){
    int i;
    ListNode* temp;

    for(i=0;i<g.V;i++)
    {
        printf("%d:\t",i+1);
        temp = g.list[i];
        while(temp!=NULL){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void enqueue(Queue *qPtr, int vertex) {
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    if(newNode==NULL) exit(0);

    newNode->vertex = vertex;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr))
        qPtr->head=newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr) {
    if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
        return 0;
    }
    else{
       QueueNode *temp = qPtr->head;
       qPtr->head = qPtr->head->next;
       if(qPtr->head == NULL) //Queue is emptied
           qPtr->tail = NULL;

       free(temp);
       qPtr->size--;
       return 1;
    }
}

int getFront(Queue q){
    return q.head->vertex;
}

int isEmptyQueue(Queue q) {
    if(q.size==0) return 1;
    else return 0;
}

void removeAllItemsFromQueue(Queue *qPtr)
{
	while(dequeue(qPtr));
}

void push(Stack *sPtr, int vertex)
{
	StackNode *newNode;
    newNode= malloc(sizeof(StackNode));
    newNode->vertex = vertex;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if(sPtr==NULL || sPtr->head==NULL){
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

int isEmptyStack(Stack s)
{
     if(s.size==0) return 1;
     else return 0;
}

int peek(Stack s){
    return s.head->vertex;
}

void removeAllItemsFromStack(Stack *sPtr)
{
	while(pop(sPtr));
}

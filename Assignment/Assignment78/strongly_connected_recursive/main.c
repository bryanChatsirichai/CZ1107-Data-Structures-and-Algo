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
void reset_visited(int *visited,int v);
int check(int *visited, int v);
void dfs(Graph g,int *visited,int start);
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
void reset_visited(int *visited,int v)
{
    //reset the test condition
    int i = 0;
    for(i;i<v;i++)
        {
           visited[i] = -1;
        }
    return;
}
int check(int *visited, int v)
{
    //check if all nodes have been visited
    int i = 0;
    for(i;i<v;i++)
        {
           if(visited[i] == -1)
           {
               return -1; // not strongly connected
           }
        }
    return 1; //strongly connected
}
void dfs(Graph g,int *visited,int start)
{   /*start from a vertex and explore it as far as possible before backing up */
    int node,neighbour,top;
    ListNode *temp = NULL;
    node = start;

    visited[node] = 1;
    temp = g.list[node];
    while(temp != NULL)
    {
        neighbour = temp->vertex - 1;
        if(visited[neighbour] == -1)
        {
            dfs(g,visited,neighbour);

        }
        temp = temp->next;
    }
}

int CC (Graph g)
{
    /* To show strongly connected all starting node able to reach any node
       one fail means not strongly connected */
       int *visited,i = 0;
       int is_connected;
       visited = malloc(g.V * sizeof(int)); //check condition
       for(i; i<g.V ;i++) //need check all node as possible starting location and can visit all other nodes
       {
           //need check all nodes
           reset_visited(visited,g.V); //reset test conditon
           dfs(g,visited,i); //perform dfs
           is_connected = check(visited,g.V); //get result if graph is strongly connected
           if(is_connected == -1)
           {
               //fail once  at any initial starting points implies not strongly connected already
               return -1;
           }

       }
    // exit loop implies all node regardless as starting position can visit all other nodes
    return 1;
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

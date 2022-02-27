#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;

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

int BFS (Graph G, int v, int w);

void printGraphList(Graph );

// You should not change the prototypes of these functions
void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);

int main()
{
    Graph g;
    int i,j;
    ListNode *temp;

    printf("Enter the number of vertices:\n"); //nodes
    scanf("%d",&g.V);

    g.list = (ListNode **) malloc(g.V*sizeof(ListNode *)); //size of the Ajancency list

    for(i=0;i<g.V;i++) //set all entry in the array of pointers to null
        g.list[i] = NULL;

    printf("Enter two vertices which are adjacent to each other:\n");

    /*Function 'scanf' returns number of succesfully matched items.
    The 'while' loop is repeated as long as there were two matched
    numbers in user-provided input.*/
    while(scanf("%d %d",&i,&j)==2)
    {
        //Vertices ranged from 1 to |V|.
        i=i-1;
        if(g.list[i]==NULL){
            g.list[i] = (ListNode *)malloc(sizeof(ListNode));
            g.list[i]->vertex = j;
            g.list[i]->next = NULL;
        }
        else{
            //new nodes are insert at the begining
            temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = g.list[i];
            temp->vertex = j;
            g.list[i] = temp;
        }
        g.E++;
        printf("Enter two vertices which are adjacent to each other:\n");
    }


    scanf("%*c");// clear buffer
    printf("Enter two vertices for finding their shortest distance:\n");
    scanf("%d %d", &i, &j);

    int d = BFS(g,i,j);

    if(d==-1)
        printf("%d and %d are unconnected.\n",i,j);
    else
        printf("The shortest distance is %d\n",d);
    printGraphList(g);
    return 0;
}

int BFS (Graph g, int v, int w){
    //printf("g.v %d\n g.e %d\n",g.V,g.E);
    //v is the initial
    int *visited = malloc(sizeof(int) *g.V);
    int *prev =  malloc(sizeof(int) *g.V);
    int i = 0,path,node,neighbour;
    ListNode *head = NULL,*last = NULL,*temp = NULL;
    ListNode *p,*t,*r;
    int count = 0;
    int at;
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;
    for(i;i<g.V;i++) //set all haven visited
    {
        visited[i] = -1;
        prev[i] = -1;
    }
    //initial set to visited
    enqueue(&q,v-1);
    visited[v-1] = 1; //when visited set to 1 and enqueue
    while(!isEmptyQueue(q))
    {
        node = getFront(q); //node to be expore
        dequeue(&q);
        temp = g.list[node]; //which element in the array of pointers to LL
        while(temp != NULL)
        {
            neighbour = temp->vertex - 1;
            if(visited[neighbour] == -1) //if the node a;ready visited we do not need enqueue them again
            {
                visited[neighbour] = 1;
                enqueue(&q,neighbour);
                prev[neighbour] = node; // the index element is the vertex parent/adjacent to

            }
            //printf("neightbour is %d\n",neighbour);
            temp = temp->next;
        }
    }
        // reconstruct the path backward end to start;
        //printf("construct path backward\n");
        at = w - 1;
        while(at != -1)
        {
            if(head == NULL)
            {
                head = malloc(sizeof(ListNode));
                head->next = NULL;
                head->vertex = at;
                last = head;
            }
            else
            {
                temp = malloc(sizeof(ListNode));
                temp->vertex = at;
                temp->next = NULL;
                last->next = temp;
                last = temp;
            }
            at = prev[at];
            count++; //how many nodees created
        }
       path = count - 1;

       //reverse the path since we make from end to start
        p = head;
        t = NULL;
        r = NULL;
        printf("head %d\n last %d\n",head->vertex,last->vertex);
        while(p != NULL)
        {
            r = t;
            t = p;
            p = p->next;
            t->next = r;
        }
        temp = last;
        last = head;
        head = temp;
         printf("head %d\n last %d\n",head->vertex,last->vertex);
    //if start and end is connected return the path
    if(head->vertex == v - 1 && last->vertex == w - 1)
    {
        //if the path from start to end match the LL head and last
        //means have a path
        return path;
    }
    else
        return -1;
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

void enqueue(Queue *qPtr, int item) {
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    if(newNode==NULL) exit(0);

    newNode->vertex = item;
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


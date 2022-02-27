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

    printf("Enter the number of vertices:\n");
    scanf("%d",&g.V);

    g.list = (ListNode **) malloc(g.V*sizeof(ListNode *)); ///Adj list, array of pointers to LL

    for(i=0;i<g.V;i++) //no LL yet so array points to NUll
        g.list[i] = NULL;

    printf("Enter two vertices which are adjacent to each other:\n");
    while(scanf("%d %d",&i,&j)==2)
    {
        i=i-1;

        if(g.list[i]==NULL){ //first time insert to LL
            g.list[i] = (ListNode *)malloc(sizeof(ListNode));
            g.list[i]->vertex = j;
            g.list[i]->next = NULL;
        }
        else{ //new node are inserted to front of LL
            temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = g.list[i];
            temp->vertex = j;
            g.list[i] = temp;
        }
        g.E++;
        printf("Enter two vertices which are adjacent to each other:\n");
    }
    scanf("%*c");
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
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    //array to keep track which nodes has been visited
    int *visited = malloc(sizeof(int)*g.V);

    //array to keep track of the node parent, index is the nodes while the elements inside is the parent
    int *parent = malloc(sizeof(int)*g.V);

    int i,cur,neighbour,start,end,x,y;
    int count = 0;
    ListNode *temp;
    for(i=0;i<g.V;i++)
    {
        parent[i] = -1;
        visited[i] = -1; //initialize the array
    }
    start = v - 1; //offset index
    end = w - 1; //offset index
    enqueue(&q,start);
    visited[start] = 1;
    while(!isEmptyQueue(q))
    {
        cur = getFront(q);
        printf("cur is %d\n",cur);
        dequeue(&q);
        temp = g.list[cur];
        while(temp != NULL)
        {
            neighbour = temp->vertex - 1;
            if(visited[neighbour] == -1) //haven visited yet
            {
                visited[neighbour] = 1;
                parent[neighbour] = cur;
                enqueue(&q,neighbour);
            }
            temp = temp->next;
        }
    }

    if(visited[end] ==  -1)
    {
        //NO path to target node found
        return 0;
    }
    /*construct a path from x to y but we do it backwards y to x using the parent array
    note that the start node has -1 as its element */
    y = end; //end
    printf("start is %d end is %d\n",start,end);
    printf("y is %d\n",y);
    printf("going backward from y to x\n");
    while(y != start)
    {
        x = parent[y];
        printf("%d->%d\n",y,x);
        y = parent[y];
        count++;
    }

    return count;

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


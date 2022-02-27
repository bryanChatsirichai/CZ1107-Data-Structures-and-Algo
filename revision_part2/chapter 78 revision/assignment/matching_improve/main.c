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

void insertAdjVertex(ListNode** AdjList,int vertex);
void removeAdjVertex(ListNode** AdjList,int vertex);
int matching(Graph g);

void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);
void printQ(QueueNode *cur);
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
//////////////////////////////////
void printGraphList(Graph g);
int ** getMatrix(Graph g);
void print_Matrix(int **arr,Graph g);
void reset_visited(int *parent_tracker,Graph g);
int min(int u,int v);
int bfs(Graph g,int **r_graph,int source,int target,int parent_tracker[]);
int fordfulerson(Graph g,int source,int target);

//////////////////////////////////

int main()
{
    int Prj, Std, Mtr,fake_std; //Project, Student and Mentor;
    int maxMatch;
    int i;
    int fake_index;
    int p_num,m_num,s_num,f_num,count,source,sink;
    scanf("%d %d %d", &Std, &Prj, &Mtr);

    int np,nm; //number of projects and number of mentors


    Graph g;
    fake_std = Std; //std will point to fake std then points to mentor
    g.V = Std + fake_std + Prj + Mtr + 2; //including s and t and fakes
    printf("Total number of nodes are %d\n",g.V);
    //elements of the array are pointer to a pointer
    g.list = (ListNode **)malloc(sizeof(ListNode*)*g.V); //array of pointer where each element in array points to a LL head
    for(i=0;i<g.V;i++)
    {
        //create and set the array
        g.list[i] = NULL;
    }

    source = 0; //let this node be source
    sink = g.V - 1; //let last node be the sink

    for(i = 1;i<=Prj;i++) //connects source to project
     {

        insertAdjVertex(&g.list[source],i);
    }

    s_num = Prj + 1; // start of student index
    f_num = fake_std; //amount of fake
    for(i = 0;i < Std;i++)//repeat for how many student
    {

        //printf("s_num is %d\n",s_num);
        printf("How many project and mentor student %d take\n",i+1);
        scanf("%d %d",&np,&nm);
         //array list index start at this for student
        for(count = 0;count<np;count++) //connect project to student
        {
            //project adjacent to student
            printf("Enter project number\n",p_num);
            scanf("%d",&p_num);
            insertAdjVertex(&g.list[p_num],s_num);
        }

        ///connect student to fake student
        fake_index = s_num + f_num;
        insertAdjVertex(&g.list[s_num],fake_index);

        for(count = 0;count<nm;count++)
        {
            //fake student to mentor
            printf("Enter mentor number\n",m_num);
            scanf("%d",&m_num);
            m_num = m_num + Prj + Std + fake_std ; //offset the index
            insertAdjVertex(&g.list[fake_index],m_num);
        }
         s_num++; //offset the index
    }

    m_num = Prj + Std + fake_std + 1;

    for(i = 0;i<Mtr;i++)///fake student connect to mentor
    {
        //mentor adjacent to sink
        insertAdjVertex(&g.list[m_num],sink);
        m_num++;
    }
    printGraphList(g);
    //apply Ford Fulkerson algorithm
    // use DFS or BFS to find a path
    maxMatch = matching(g);
    printf("%d\n", maxMatch);
    return 0;
}

int ** getMatrix(Graph g)
{
    int i,j,node;
    ListNode *temp;
    int **arr = malloc(sizeof(int*)*g.V);
    for (i = 0;i<g.V;i++)
    {

        arr[i] = malloc(sizeof(int)*g.V);
        for(j=0;j<g.V;j++)
        {
            arr[i][j] = 0;
        }
        temp = g.list[i];
        while(temp != NULL)
        {
            node = temp->vertex;
            arr[i][node] = 1;
            temp = temp->next;

        }

    }

    return arr;
}

void print_Matrix(int **arr,Graph g)
{
    int i,j;
    for(i=0;i<g.V;i++)
    {
        printf("[%d]->\t ",i);
        for(j=0;j<g.V;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
void reset_visited(int parent_tracker [],Graph g)
{
    //reset the test condition
    int i = 0;
    for(i;i<g.V;i++)
        {
           parent_tracker[i] = -1;
        }
    return;
}

int bfs(Graph g,int **r_graph,int source,int target,int parent_tracker[])
{
    // return 1 if have path else return o
    printf("bsf\n");
    //printf("source is %d target is %d\n",source,target);
    int i,j,current_node,neighbour_node;
    int *visited = malloc(sizeof(int) *g.V);
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;
    for(i = 0;i<g.V;i++) //set all haven visited
    {
        //printf("i is %d\n",i);
        visited[i] = -1;
    }
    enqueue(&q,source); //start from source
    visited[source] = 1;
    parent_tracker[source] = -1; //source has no parent
    while(!isEmptyQueue(q))
    {
        //stop when all possible nodes has been reach and cannot explore anymore
        current_node = getFront(q);
        dequeue(&q);
        for(i=0;i<g.V;i++)
        {
            if(r_graph[current_node][i] != 0) //check all possible neighbour of current node
            {
                neighbour_node = i; //found and node adjacent to the current node
                if(visited[neighbour_node] != 1)
                {
                    //if the node a;ready visited we do not need enqueue them again
                    printf("node %d is adjacent to node %d\n",current_node,neighbour_node);
                    visited[neighbour_node] = 1;
                    enqueue(&q,neighbour_node);
                    parent_tracker[neighbour_node] = current_node; //current node is parent of this neighbour

                }
            }
        }
    }

    if(visited[target] == 1)
    {
        //if have a path from source to target
        return 1;
    }

    else
        return 0;

}
int min(int u,int v)
{
    if(u<v)
    {
        return u;
    }
    else
    {
        return v;
    }
}
int fordfulerson(Graph g,int source,int target)
{
    int i,j; //for iteration
    int u = 0,v = 0; //keep track of nodes
    int bottle_neck,maxflow = 0;
    int** r_graph = getMatrix(g);
    int parent_tracker[g.V];
    reset_visited(parent_tracker,g);

    print_Matrix(r_graph,g);
    while(bfs(g,r_graph,source,target,parent_tracker))
    {
        //have a path

        bottle_neck = 100;
        v  = target;
        while(v != source)// reconstruct the path backward end to start;
        {
            //so call going backward from v->u
            //find the bottle neck value
            //go backward from target till reach source node to construct a path
            u = parent_tracker[v];
            bottle_neck = min(bottle_neck,r_graph[u][v]);
            v = parent_tracker[v];
        }

        v = target;

        while( v != source)//thinking of going from u -> v
        {
            //so call going backward from v->u
            //go backward from target till reach source node to construct a path
            //updating the residue capacity
            /*
            Updating the flow means updating the flow values of the edge along augmented path
            also need to decrease the flow along each residual edge (doted edge going backward of augmented path)
            Think 'remaining capacity of an edge (residual or not) as e.capacity - e.flow
            the difference between capacity and flow is the true remaining capacity
            so remaining capacity of an edge is always non negative even if the flow can be negative
            */
            printf("bottleneck is %d\n",bottle_neck);
            u = parent_tracker[v];
            printf("path backward v->u %d->%d\n",v,u);
            r_graph[u][v]-= bottle_neck;
            r_graph[v][u]+= bottle_neck;
            v = parent_tracker[v];
        }

        maxflow += bottle_neck;
        printf("maxflow is %d\n",maxflow);
        reset_visited(parent_tracker,g); //reset for next iteration
        printf("\n");
        print_Matrix(r_graph,g);
    }
    //print_Matrix(r_graph,g);

    return maxflow;
}


int matching(Graph g)
{
    int max_matching;
    //printf("matching g.v is %d\n",g.V);
    return fordfulerson(g,0,g.V-1);

}
void printGraphList(Graph g){
    ListNode* temp;
    int i;
    for(i=0;i<g.V;i++)
    {
        printf("%d:\t",i);
        temp = g.list[i];
        while(temp!=NULL){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void removeAdjVertex(ListNode** AdjList,int vertex)
{
    ListNode *temp, *preTemp;
    if(*AdjList != NULL)
    {
        if((*AdjList)->vertex ==vertex){//first node
            temp = *AdjList;
            *AdjList = (*AdjList)->next;
            free(temp);
            return;
        }
        preTemp = *AdjList;
        temp = (*AdjList)->next;
        while(temp!=NULL && temp->vertex != vertex)
        {
            preTemp= temp;
            temp = temp->next;
        }
        preTemp->next = temp->next;
        free(temp);
    }

}
void insertAdjVertex(ListNode** AdjList,int vertex)
{
    ListNode *temp;
    if(*AdjList==NULL)
    {
        *AdjList = (ListNode *)malloc(sizeof(ListNode));
        (*AdjList)->vertex = vertex;
        (*AdjList)->next = NULL;
    }
    else{
        temp = (ListNode *)malloc(sizeof(ListNode));
        temp->vertex = vertex;
        temp->next = *AdjList;
        *AdjList = temp;
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

void printQ(QueueNode *cur){
    if(cur==NULL) printf("Empty");

    while (cur != NULL){
        printf("%d ", cur->vertex);
        cur = cur->next;
    }
    printf("\n");
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

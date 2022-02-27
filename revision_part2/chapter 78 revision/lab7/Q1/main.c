#include <stdio.h>
#include <stdlib.h>

enum GraphType {ADJ_MATRIX, ADJ_LIST}; // Types of Graph Representation

typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;

union GraphForm{ ///allow store everything in that union in the exact memory size largest variable inside
    int **matrix;
    ListNode **list;
};

typedef struct _graph{
    int V;
    int E;
    enum GraphType type;
    union GraphForm adj;
}Graph;

void printGraphMatrix(Graph );
void adjM2adjL(Graph *);
void adjL2adjM(Graph *);
void printGraphList(Graph );
void calDegreeV(Graph,int *);
void printDegreeV(int *,int );

int main()
{
    Graph g;
    int i,j;

    int* degreeV;

    printf("Enter the number of vertices:\n");
    scanf("%d",&g.V);

    g.E = 0;
    g.adj.matrix = (int **)malloc(g.V*sizeof(int *)); ///array of pointers that each element points to an array
    for(i=0;i<g.V;i++)
        g.adj.matrix[i] = (int *)malloc(g.V*sizeof(int));

    for(i=0;i<g.V;i++)
        for(j=0;j<g.V;j++)
            g.adj.matrix[i][j] = 0;
    g.type = ADJ_MATRIX;

    degreeV = (int *) malloc(g.V*sizeof(int));///array of each vertex degrees
    for(i=0;i<g.V;i++)
        degreeV[i]=0;

    int V1, V2;
    printf("Enter two vertices which are adjacent to each other:\n");
    while(scanf("%d %d",&V1,&V2)==2) ///vertex minus 1 to offset index

    {
        if(V1>0 && V1<=g.V && V2>0 && V2<=g.V)
        {
            g.adj.matrix[V1-1][V2-1] = 1;
            g.adj.matrix[V2-1][V1-1] = 1;
            g.E++;
        }
        else
            break;
        printf("Enter two vertices which are adjacent to each other:\n");
    }

    calDegreeV(g,degreeV);

    printGraphMatrix(g);
    printDegreeV(degreeV,g.V);

    adjM2adjL(&g);

    calDegreeV(g,degreeV);

    printGraphList(g);
    printDegreeV(degreeV,g.V);

    adjL2adjM(&g);
    printGraphMatrix(g);

    return 0;
}

void printGraphMatrix(Graph g)
{
    int i,j;
    if(g.type == ADJ_LIST) {printf("Error"); return;}

    for(i=0;i<g.V;i++){
        for(j=0;j<g.V;j++)
            printf("%d\t",g.adj.matrix[i][j]);
        printf("\n");
    }

}

void printDegreeV(int *degreeV,int V)
{
    int i;
    for(i=0;i<V;i++)
        printf("%d: %d degree\n",i+1,degreeV[i]);
}

void printGraphList(Graph g){
    int i;
    ListNode* temp;

    if(g.type == ADJ_MATRIX) {printf("Error"); return;}

    for(i=0;i<g.V;i++)
    {
        printf("%d:\t",i+1);
        temp = g.adj.list[i];
        while(temp!=NULL){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void adjM2adjL(Graph *g)
{
    ListNode **arr;
    ListNode *temp;
    int i,j;
    if(g->V <= 0)
    {
        printf("Empty graph\n");
        return;
    }
    if(g->type == ADJ_LIST)
    {
        printf("wrong type\n");
    }
    arr = (ListNode **)malloc(sizeof(ListNode)*g->V);
    for(i=0; i<g->V; i++)
    {
        arr[i] = NULL;
        for(j=0;j<g->V;j++)
        {
            if(g->adj.matrix[i][j] == 1)
               {
                   temp = malloc(sizeof(ListNode));
                   temp->vertex = j + 1;
                   temp->next = arr[i];
                   arr[i] = temp;
               }
        }
    }

    g->type = ADJ_LIST;
    ///free adj matrix
    for(i=0;i<g->V;i++)
    {
        free(g->adj.matrix[i]);
    }
    free(g->adj.matrix);
    g->adj.list = arr; ///must be last as they share the same memory location

}

void adjL2adjM(Graph *g){
    if(g->V <= 0)
    {
        printf("Empty graph\n");
        return;
    }
    if(g->type == ADJ_MATRIX)
    {
        printf("wrong type\n");
    }
    int i,j;
    int **matrix;
    matrix = (int**)malloc(sizeof(int*)*g->V); ///array of pointers to an array of integers

    for(i=0;i<g->V;i++)
    {
        matrix[i] = (int *)malloc(sizeof(int)*g->V); //array of integers
        for(j=0;j<g->V;j++)
        {
            matrix[i][j] = 0;
        }
    }
    ListNode *temp,*deletenode;
    for(i=0;i<g->V;i++)
    {
        temp = g->adj.list[i];
        while(temp != NULL)
        {
            matrix[i][temp->vertex - 1] = 1;
            temp = temp->next;
        }
    }
    g->type = ADJ_MATRIX;
    ///free adj list
    for(i =0;i<g->V;i++)
    {
        temp = g->adj.list[i];
        while(temp != NULL)
        {
            deletenode = temp;
            temp = temp->next;
            free(deletenode);
        }
    }
    free(g->adj.list);
    g->adj.matrix = matrix;

}

void calDegreeV(Graph g, int *degreeV)
{
    int i,j,count;
    ListNode *temp;
    if(g.type == ADJ_MATRIX)
    {
        for(i=0;i<g.V;i++)
        {
            count = 0;
            for(j=0;j<g.V;j++)
            {
                if(g.adj.matrix[i][j] == 1)
                {
                   count++;
                }
            }
            degreeV[i] = count;
        }
        return;
    }
    else
    {
        for(i=0;i<g.V;i++)
        {
            count = 0;
            temp = g.adj.list[i];
            while(temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            degreeV[i] = count;
        }
        return;
    }

}

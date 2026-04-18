

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
 
typedef struct AdjNode{
    int dest;
    struct AdjNode *next;
} AdjNode;

typedef struct{
    int      numVertices;
    AdjNode *adjList[MAX_VERTICES];
} Graph;

typedef struct{
    int  items[MAX_VERTICES];
    int  front, rear;
} Queue;

Graph *createGraph(int vertices){
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
        g->adjList[i] = NULL;
    return g;
}

void addEdge(Graph *g, int u, int v){

    AdjNode*nodeV=(AdjNode *)malloc(sizeof(AdjNode));
    nodeV->dest= v;
    nodeV->next=g->adjList[u];
    g->adjList[u]=nodeV;

    AdjNode*nodeU=(AdjNode *)malloc(sizeof(AdjNode));
    nodeU->dest= u;
    nodeU->next= g->adjList[v];
    g->adjList[v]=nodeU;
}

void printGraph(Graph *g){
    printf("\n=== Adjacency List ===\n");
    for (int i=0; i<g->numVertices; i++) {
        printf("  Vertex %d :", i);
        AdjNode*curr = g->adjList[i];
        while (curr) {
            printf(" : %d", curr->dest);
            curr = curr->next;
        }
        printf("\n");
    }
    printf("\n");
}

void initQueue(Queue*q){ 
    q->front = q->rear = -1; }
bool isQueueEmpty(Queue *q{ 
    return q->front == -1; }

void enqueue(Queue*q, int val){
    if (q->rear == MAX_VERTICES - 1) { printf("Queue overflow\n"); return; }
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = val;
}

int dequeue(Queue*q){
    int val = q->items[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else                     q->front++;
    return val;
}

bool bfs(Graph*g,int src,int dest,int parent[]){
    bool visited[MAX_VERTICES] = { false };
    Queue q;
    initQueue(&q);

    for (int i = 0; i < g->numVertices; i++)
        parent[i] = -1;

    visited[src] = true;
    enqueue(&q, src);

    while (!isQueueEmpty(&q)) {
        int curr = dequeue(&q);

        if (curr == dest)
            return true;

        AdjNode*nbr=g->adjList[curr];
        while (nbr) {
            if (!visited[nbr->dest]) {
                visited[nbr->dest]  = true;
                parent[nbr->dest]   = curr;
                enqueue(&q, nbr->dest);
            }
            nbr = nbr->next;
        }
    }
    return false;   
}


void printPath(int parent[], int src, int dest)
{
    int path[MAX_VERTICES];
    int len  = 0;
    int curr = dest;

    while (curr != -1) {
        path[len++]=curr;
        curr=parent[curr];
    }


    printf("Path : ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i>0) printf(" : ");
    }
    printf("\n");
}


void freeGraph(Graph *g)
{
    for (int i = 0; i < g->numVertices; i++) {
        AdjNode *curr = g->adjList[i];
        while (curr) {
            AdjNode *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(g);
}


int main(void){
    int numVertices = 6;
    Graph *g = createGraph(numVertices);

    addEdge(g,0,1);
    addEdge(g,0,2);
    addEdge(g,1,3);
    addEdge(g,3,5);
    addEdge(g,4,5);

    printGraph(g);


    int queries[][2] = {
        {0,4},   
        {2,5},   
        {4,2},   
        {1,1}   
    };
    int numQueries = sizeof(queries) / sizeof(queries[0]);

    int parent[MAX_VERTICES];

    for (int i = 0; i < numQueries; i++) {
        int src  = queries[i][0];
        int dest = queries[i][1];

        printf("\nSource = %d   Destination = %d\n", src, dest);

        if (bfs(g, src, dest, parent)) {
            printf("Path EXISTS.\n");
            printPath(parent, src, dest);
        } else {
            printf("No path exists between %d and %d.\n", src, dest);
        }
        printf("\n");
    }

    freeGraph(g);
    return 0;
}

/* Ex no:20
 * Write a program to represent any given graph and to do the following operations:
 * Compute adjacency list and adjacency matrix
 * Perform a depth first search
 * Perform a breadth first search
 * 70 shravan Nander Pandala
 * 01/11/24
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Structure for adjacency list node
struct Node {
    int vertex;
    struct Node* next;
}*temp;

// Structure for graph
struct Graph {
    int numVertices;
    int adjMatrix[MAX][MAX];
    struct Node* adjList[MAX];
    int visited[MAX];
}graph;

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Graph
void initGraph(struct Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
}

// Add edge to graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;  
    
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Print adjacency matrix
void printAdjMatrix(struct Graph* graph) {
    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < graph->numVertices; i++) {
        for(int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Print adjacency list
void printAdjList(struct Graph* graph) {
    printf("\nAdjacency List:\n");
    for(int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjList[i];
        printf("Vertex %d", i);
        while(temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Reset visited array
void resetVisited(struct Graph* graph) {
    for(int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
}

// DFS 
void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjList[vertex];
    struct Node* temp = adjList;
    
    graph->visited[vertex] = 1;
    printf("%d ", vertex);
    
    while(temp != NULL) {
        int connectedVertex = temp->vertex;
        
        if(graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Queue for BFS
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

//Checks if queue is empty
int isEmpty(struct Queue* queue) {
    return queue->rear == -1;
}

// Add element to queue
void enqueue(struct Queue* queue, int value) {
    if(queue->rear == MAX-1)
        return;
    else {
        if(queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Remove element from queue
int dequeue(struct Queue* queue) {
    int item;
    if(isEmpty(queue)) {
        return -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if(queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return item;
    }
}

// BFS 
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue();
    
    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);
    
    while(!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);
        
        struct Node* temp = graph->adjList[currentVertex];
        while(temp) {
            int adjVertex = temp->vertex;
            if(graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
    free(queue);
}

void main() {
    int vertices, edges, i, src, dest, startVertex;
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    initGraph(&graph, vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    for(i = 0; i < edges; i++) {
        printf("Enter edge %d : ", i+1);
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }
    
    printAdjMatrix(&graph);
    printAdjList(&graph);
    
    printf("\nEnter starting vertex for traversal: ");
    scanf("%d", &startVertex);
    
    if(startVertex >= 0 && startVertex < vertices) {
        printf("\nDFS from vertex %d: ", startVertex);
        resetVisited(&graph);
        DFS(&graph, startVertex);
        
        printf("\nBFS from vertex %d: ", startVertex);
        resetVisited(&graph);
        BFS(&graph, startVertex);
    } else {
        printf("\nInvalid starting vertex!");
    }
}
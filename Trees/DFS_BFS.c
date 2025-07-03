#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node **adjList;
    int **adjMatrix;
} Graph;

Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Node **)malloc(numVertices * sizeof(Node *));
    graph->adjMatrix = (int **)malloc(numVertices * sizeof(int *));

    for (int i = 0; i < numVertices; ++i)
    {
        graph->adjList[i] = NULL;
        graph->adjMatrix[i] = (int *)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; ++j)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph *graph, int u, int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1; // For undirected graphs
}

void printGraph(Graph *graph, int representation)
{
    if (representation == 1)   // Adjacency List
    {
        for (int i = 0; i < graph->numVertices; ++i)
        {
            printf("Vertex %d: ", i);
            Node *temp = graph->adjList[i];
            while (temp != NULL)
            {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
    else if (representation == 2)     // Adjacency Matrix
    {
        for (int i = 0; i < graph->numVertices; ++i)
        {
            for (int j = 0; j < graph->numVertices; ++j)
            {
                printf("%d ", graph->adjMatrix[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Invalid representation.\n");
    }
}

void bfs(Graph *graph, int start)
{
    int visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; ++i)
    {
        visited[i] = 0;
    }

    int queue[graph->numVertices];
    int front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front != rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        Node *temp = graph->adjList[current];
        while (temp != NULL)
        {
            if (!visited[temp->data])
            {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

void dfs(Graph *graph, int start, int visited[])
{
    visited[start] = 1;
    printf("%d ", start);

    Node *temp = graph->adjList[start];
    while (temp != NULL)
    {
        if (!visited[temp->data])
        {
            dfs(graph, temp->data, visited);
        }
        temp = temp->next;
    }
}

int main()
{
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Adjacency List:\n");
    printGraph(graph, 1);

    printf("\nAdjacency Matrix:\n");
    printGraph(graph, 2);

    printf("\nBFS Traversal:\n");
    bfs(graph, 0);

    printf("\nDFS Traversal:\n");
    int visited[5] = {0};
    dfs(graph, 0, visited);

    return 0;
}

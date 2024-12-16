#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of vertices

// Function prototypes
void createGraph(int graph[MAX][MAX], int vertices, int edges);
void dfs(int graph[MAX][MAX], int vertices, int startVertex, int visited[]);
void bfs(int graph[MAX][MAX], int vertices, int startVertex);

int main() {
    int graph[MAX][MAX] = {0}; // Adjacency matrix
    int vertices, edges, choice, startVertex;
    int visited[MAX] = {0}; // Visited array for DFS
    
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);
    
    createGraph(graph, vertices, edges);
    
    printf("Choose Traversal Method:\n");
    printf("1. Depth-First Search (DFS)\n");
    printf("2. Breadth-First Search (BFS)\n");
    scanf("%d", &choice);
    
    printf("Enter the starting vertex (0 to %d): ", vertices - 1);
    scanf("%d", &startVertex);
    
    switch (choice) {
        case 1:
            printf("DFS Traversal Order:\n");
            dfs(graph, vertices, startVertex, visited);
            break;
        case 2:
            printf("BFS Traversal Order:\n");
            bfs(graph, vertices, startVertex);
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}

// Function to create the adjacency matrix
void createGraph(int graph[MAX][MAX], int vertices, int edges) {
    int u, v;
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For an undirected graph
    }
}

// DFS function
void dfs(int graph[MAX][MAX], int vertices, int startVertex, int visited[]) {
    printf("%d ", startVertex);
    visited[startVertex] = 1;
    for (int i = 0; i < vertices; i++) {
        if (graph[startVertex][i] && !visited[i]) {
            dfs(graph, vertices, i, visited);
        }
    }
}

// BFS function
void bfs(int graph[MAX][MAX], int vertices, int startVertex) {
    int queue[MAX], front = 0, rear = 0, visited[MAX] = {0};
    
    printf("%d ", startVertex);
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    
    while (front < rear) {
        int current = queue[front++];
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

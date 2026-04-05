# include <stdio.h>

# define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int vertices;

void BFS(int startingNode){
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < vertices; i++){
        visited[i] = 0;
    }

    visited[startingNode] = 1;
    queue[rear++] = startingNode;

    printf("BFS Traversal: \n");
    while(front < rear){
        int node = queue[front++];
        printf("%d \t", node);

        for(int i = 0; i < vertices; i++){
            if(graph[node][i] == 1 && !visited[i]){
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int edges, u, v, startingNode;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    if(edges > vertices * (vertices - 1)/2) return 0;

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            graph[i][j] = 0;
        }
    }

    // User input edges
    printf("Enter edges (u v):\n");
    for(int i = 0; i < edges; i++){
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter your starting node of your graph: ");
    scanf("%d", &startingNode);

    BFS(startingNode);

    return 0;
}
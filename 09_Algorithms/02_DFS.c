# include <stdio.h>

# define MAX 100

int graph[MAX][MAX];
int visited [MAX];
int vertices;

void DFS(int node){
    visited[node] = 1;

    printf("%d \t", node);

    for(int i = 0; i < vertices; i++){
        if(graph[node][i] && !visited[i]){
            visited[i] = 1;
            DFS(i);
        }
    }
}

int main () {
    int edges, u, v, start;

    printf("Enter number of vertices for your graph: ");
    scanf("%d", &vertices);
    printf("Enter number of edges for your graph: ");
    scanf("%d", &edges);

    if(edges > vertices * (vertices - 1)/2) return 0;



    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j ++){
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < edges; i ++){
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter your staring node: ");
    scanf("%d", &start);

    DFS(start);

    return 0;
}
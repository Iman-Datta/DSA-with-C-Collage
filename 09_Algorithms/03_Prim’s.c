#include <stdio.h>
#define MAX 10
#define INF 9999

int graph[MAX][MAX];
int parent[MAX];

/* ---------- UNION FIND for Kruskal ---------- */
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    parent[rootA] = rootB;
}

/* ---------- Prim's Algorithm ---------- */
void primMST(int vertices) {
    int selected[MAX] = {0};
    int edge_count = 0;
    int min, x, y;
    int totalCost = 0;

    selected[0] = 1;   // Start from vertex 0

    printf("\nPrim's MST:\n");

    while (edge_count < vertices - 1) {
        min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < vertices; i++) {
            if (selected[i]) {
                for (int j = 0; j < vertices; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);
        totalCost += graph[x][y];
        selected[y] = 1;
        edge_count++;
    }

    printf("Total cost = %d\n", totalCost);
}

/* ---------- Kruskal's Algorithm ---------- */
void kruskalMST(int vertices) {
    int edge_count = 0;
    int totalCost = 0;

    for (int i = 0; i < vertices; i++)
        parent[i] = i;

    printf("\nKruskal's MST:\n");

    while (edge_count < vertices - 1) {
        int min = INF;
        int a = -1, b = -1;

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (graph[i][j] && graph[i][j] < min) {
                    if (find(i) != find(j)) {
                        min = graph[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        unionSet(a, b);
        printf("%d - %d : %d\n", a, b, min);
        totalCost += min;
        graph[a][b] = graph[b][a] = INF;
        edge_count++;
    }

    printf("Total cost = %d\n", totalCost);
}

/* ---------- Main ---------- */
int main() {
    int vertices, edges, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    /* Initialize graph */
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    primMST(vertices);
    kruskalMST(vertices);

    return 0;
}
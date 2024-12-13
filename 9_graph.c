#include <stdio.h>
#include <string.h>
#define MAX 20

int a[MAX][MAX], visited[MAX], n;
char vertexNames[MAX];

// Function to find the index of a vertex by its name
int getVertexIndex(char name) {
    for (int i = 0; i < n; i++) {
        if (vertexNames[i] == name) return i;
    }
    return -1;
}

// Function to read the adjacency matrix
void readGraph() {
    int i, j;
    char vertex;

    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the vertex names (e.g., a b c d):\n");
    for (i = 0; i < n; i++) {
        scanf(" %c", &vertexNames[i]);
    }

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        printf("Enter row for vertex %c:\n", vertexNames[i]);
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nThe adjacency matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// BFS Function
void bfs(char startVertex) {
    int queue[MAX], front = 0, rear = -1, i;
    int start = getVertexIndex(startVertex);

    if (start == -1) {
        printf("Invalid starting vertex.\n");
        return;
    }

    printf("\nBFS Traversal: ");
    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        int current = queue[front++];
        printf("%c ", vertexNames[current]);

        for (i = 0; i < n; i++) {
            if (a[current][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS Function
void dfs(char startVertex) {
    int stack[MAX], top = -1, i;
    int start = getVertexIndex(startVertex);

    if (start == -1) {
        printf("Invalid starting vertex.\n");
        return;
    }

    printf("\nDFS Traversal: ");
    stack[++top] = start;

    while (top >= 0) {
        int current = stack[top--];

        if (!visited[current]) {
            printf("%c ", vertexNames[current]);
            visited[current] = 1;

            for (i = n - 1; i >= 0; i--) {
                if (a[current][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}

// Topological Sort Function
void topologicalSort() {
    int inDegree[MAX] = {0}, stack[MAX], top = -1, i, j, count = 0;

    // Calculate in-degrees
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[j][i] == 1) {
                inDegree[i]++;
            }
        }
    }

    // Push nodes with 0 in-degree onto stack
    for (i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            stack[++top] = i;
        }
    }

    printf("\nTopological Order: ");
    while (top >= 0) {
        int current = stack[top--];
        printf("%c ", vertexNames[current]);
        count++;

        for (i = 0; i < n; i++) {
            if (a[current][i] == 1) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }

    if (count != n) {
        printf("\nThe graph has a cycle; topological sort is not possible.");
    }
    printf("\n");
}

int main() {
    int i, choice;
    char startVertex;

    do {
        // Menu-driven program
        printf("\n1. Read Graph\n2. BFS\n3. DFS\n4. Topological Sort\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Reset visited array for each traversal
        for (i = 0; i < n; i++) {
            visited[i] = 0;
        }

        switch (choice) {
            case 1:
                readGraph();
                break;
            case 2:
                printf("Enter the starting vertex for BFS: ");
                scanf(" %c", &startVertex);
                bfs(startVertex);
                break;
            case 3:
                printf("Enter the starting vertex for DFS: ");
                scanf(" %c", &startVertex);
                dfs(startVertex);
                break;
            case 4:
                topologicalSort();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

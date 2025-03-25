#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10
#define INF 99999

int numNodes;
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

void dijkstra(int startNode) {
    int distance[MAX_NODES];
    int previous[MAX_NODES];

    for (int i = 0; i < numNodes; i++) {
        distance[i] = INF;
        visited[i] = false;
    }

    distance[startNode] = 0;
    previous[startNode] = -1;

    for (int count = 0; count < numNodes - 1; count++) {
        int minDistance = INF;
        int minNode;

        for (int i = 0; i < numNodes; i++) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                minNode = i;
            }
        }

        visited[minNode] = true;

        for (int i = 0; i < numNodes; i++) {
            if (!visited[i] && graph[minNode][i] && distance[minNode] + graph[minNode][i] < distance[i]) {
                distance[i] = distance[minNode] + graph[minNode][i];
                previous[i] = minNode;
            }
        }
    }

    printf("\nRouting Table for Node %d:\n", startNode);
    printf("Destination\tNext Hop\tCost\n");

    for (int i = 0; i < numNodes; i++) {
        if (i != startNode) {
            printf("%c\t\t%c\t\t%d\n", i + 65, previous[i] + 65, distance[i]);
        }
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Initialize the graph
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    int numLinks;
    printf("Enter the number of links: ");
    scanf("%d", &numLinks);

    // Add links to the graph
    for (int i = 0; i < numLinks; i++) {
        int src, dest, cost;
        printf("Enter source, destination, and cost of link %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &cost);
        graph[src][dest] = cost;
        graph[dest][src] = cost;
    }

    // Perform Link State Routing for each node
    for (int i = 0; i < numNodes; i++) {
        dijkstra(i);
    }

    return 0;
}

/*
Enter the number of nodes: 4
Enter the number of links: 5
Enter source, destination, and cost of link 1: 0 1 10
Enter source, destination, and cost of link 2: 0 2 20
Enter source, destination, and cost of link 3: 1 2 5
Enter source, destination, and cost of link 4: 1 3 15
Enter source, destination, and cost of link 5: 2 3 10
*/

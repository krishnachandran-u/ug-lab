#include <stdio.h>

struct node {
    int dist[20];
    int from[20];
} route[10];

int main() {
    int dm[20][20], no;

    printf("Enter number of nodes: ");
    scanf("%d", &no);
    printf("Enter the distance matrix:\n");

    for (int i = 0; i < no; i++) {
        for (int j = 0; j < no; j++) {
            scanf("%d", &dm[i][j]);
            /* Set distance from i to i as 0 */
            dm[i][i] = 0;
            route[i].dist[j] = dm[i][j];
            route[i].from[j] = j;
        }
    }

    int flag;

    do {
        flag = 0;
        for (int i = 0; i < no; i++) {
            for (int j = 0; j < no; j++) {
                for (int k = 0; k < no; k++) {
                    if ((route[i].dist[j]) > (route[i].dist[k] + route[k].dist[j])) {
                        route[i].dist[j] = route[i].dist[k] + route[k].dist[j];
                        route[i].from[j] = route[i].from[k];
                        flag = 1;
                    }
                }
            }
        }
    } while (flag);

    for (int i = 0; i < no; i++) {
        printf("Router info for router: %c\n", i + 65);
        printf("Dest\tNext Hop\tDist\n");
        for (int j = 0; j < no; j++) {
            printf("%c\t%c\t\t%d\n", j + 65, route[i].from[j] + 65, route[i].dist[j]);
        }
    }

    return 0;
}

/*
Enter number of nodes: 4
Enter the distance matrix:
0 10 999 30
10 0 50 10
999 50 0 20
30 10 20 0
*/

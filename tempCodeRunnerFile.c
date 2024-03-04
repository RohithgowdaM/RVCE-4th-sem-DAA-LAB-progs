#include <stdio.h>

void dijs(int n, int sv, int cost[10][10], int dist[])
{
        int i, v, count, w, j, visited[23], min;
        for (i = 1; i <= n; i++)
        {
                visited[i] = 0;
                dist[i] = cost[sv][i];
        }
        visited[sv] = 1;
        dist[sv] = 1;
        count = 2;
        while (count <= n)
        {
                min = 999;
                for (w = 1; w <= n; w++)
                {
                        if (dist[w] < min && !visited[w])
                        {
                                min = dist[w];
                                v = w;
                        }
                }
                visited[v] = 1;
                count++;
                for (w = 1; w <= n; w++)
                        if (dist[v] + cost[v][w] < dist[w])
                                dist[w] = dist[v] + cost[v][w];
        }
}

int main()
{
        int n, sv, i, j, dist[10], cost[10][10];
        printf("\nDijkstra\n");
        printf("Enter the number of vertices");
        scanf("%d", &n);
        printf("Enter the cost of matrix");
        for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                {
                        scanf("%d", &cost[i][j]);
                        if (cost[i][j] == 0)
                                cost[i][j] = 999;
                }
        printf("Enter the source");
        scanf("%d", &sv);
        dijs(n, sv, cost, dist);
        printf("Shortest path:\n");
        for (j = 1; j <= n; j++)
        {
                if (j != sv)
                        printf("%d->%d==%d\n", sv, j, dist[j]);
        }
}
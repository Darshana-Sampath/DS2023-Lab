#include <iostream>
#include <limits.h>
using namespace std;

#define V 6

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int src)
{
    for (int i = 0; i < V; i++)
        if ( i != src)
        {
            cout << "From vertex " << src << " to vertex "<< i  << endl;
            cout << "\t\t\t\t\t\t Time to travel : - \t" << dist[i] << endl;
        }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, src);
}

int main()
{
    int graph[V][V] = {
        { 0,  10,  0,  0, 15,  5  },
        { 10,  0, 10, 30,  0,  0 },
        { 0,  10,  0, 12,  5,  0 },
        { 0,  30, 12,  0,  0, 20 },
        { 15,  0,  5,  0,  0,  0 },
        { 5,   0,  0, 20,  0,  0 },
    };

    dijkstra(graph, 5);

    return 0;
}


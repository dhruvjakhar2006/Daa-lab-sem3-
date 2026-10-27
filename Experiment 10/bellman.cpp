#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> dist(n, 1000000000);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != 1000000000 &&
                dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative-weight cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != 1000000000 &&
            dist[u] + w < dist[v]) {
            cout << "Negative-weight cycle detected!\n";
            return 0;
        }
    }

    cout << "\nShortest distances from source " << src << ":\n";

    for (int i = 0; i < n; i++) {
        if (dist[i] == 1000000000) {
            cout << "Vertex " << i << ": Unreachable\n";
        } else {
            cout << "Vertex " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}

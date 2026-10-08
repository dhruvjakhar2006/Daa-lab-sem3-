#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});   // Remove this for directed graph
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);

    dist[source] = 0;

    for (int i = 0; i < V - 1; i++) {

        // Find vertex with minimum distance
        int u = -1;

        for (int j = 0; j < V; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (u == -1 || dist[u] == INT_MAX)
            break;

        visited[u] = true;

        // Relax all adjacent edges
        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    cout << "\nShortest distances from source " << source << ":\n";

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << source << " -> " << i << " = INF\n";
        else
            cout << source << " -> " << i << " = " << dist[i] << "\n";
    }

    return 0;
}

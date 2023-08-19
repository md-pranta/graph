#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int V) {
        vertices = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int bfs(int source, int destination) {
        vector<bool> visited(vertices, false);
        vector<int> distance(vertices, -1);

        queue<int> q;
        q.push(source);
        visited[source] = true;
        distance[source] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adjList[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                    distance[v] = distance[u] + 1;
                }
            }
        }

        return distance[destination];
    }
};

int main() {
    int n, m; // Number of vertices and edges
    cin >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int q; // Number of queries
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int source, destination;
        cin >> source >> destination;
        int minDistance = graph.bfs(source, destination);
        cout << "Minimum distance from " << source << " to " << destination << ": " << minDistance << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1); // Adjacency list representation
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // Undirected graph
    }
    
    // BFS to find shortest path from 1 to n
    vector<int> dist(n + 1, -1); // Distance from source
    vector<int> parent(n + 1, -1); // To reconstruct the path
    queue<int> q;
    
    dist[1] = 0;
    q.push(1);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : graph[u]) {
            if (dist[v] == -1) { // Not visited
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    
    if (dist[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dist[n] + 1 << endl; // Number of nodes in path
        vector<int> path;
        for (int v = n; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        for (int x : path) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}
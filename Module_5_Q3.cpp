#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    vector<int> adj[100];
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start;
    cin >> start;
    bool visited[100];
    for (int i = 0; i < n; i++) visited[i] = false;
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
    return 0;
}

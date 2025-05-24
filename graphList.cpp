#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5, m = 6;
    vector<int> adj[n+1];  // Adjacency list representation

    cout << "Enter " << m << " edges (u v):" << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "\nGraph elements (Adjacency List):" << endl;
    for(int i = 1; i <= n; i++) {  // Loop through nodes
        cout << "Node " << i << ": ";
        for(int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5, m = 6;
    int adj[n+1][n+1];  // Graph adjacency matrix (fixing the size)

    memset(adj, 0, sizeof(adj)); // Initialize matrix to 0

    cout << "Enter " << m << " edges (u v):" << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }  

    cout << "\nGraph elements:" << endl;
    for(int i = 1; i <= n; i++) {  // Fixing bounds
        for(int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

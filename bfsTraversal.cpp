#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vis[0] = 1;
        queue<int> que;
        que.push(0);
        vector<int> bfs;
        
        while (!que.empty()) {
            int node = que.front();
            que.pop();
            bfs.push_back(node);
            
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    que.push(it);
                }
            }
        }
        return bfs;
    }
};

int main() {
    // Creating a sample adjacency list representation of a graph
    vector<vector<int>> adj = {
        {1, 2},     // Node 0 connected to 1 and 2
        {0, 3, 4},  // Node 1 connected to 0, 3, and 4
        {0, 4},     // Node 2 connected to 0 and 4
        {1, 5},     // Node 3 connected to 1 and 5
        {1, 2, 5},  // Node 4 connected to 1, 2, and 5
        {3, 4}      // Node 5 connected to 3 and 4
    };
    Solution sol;
    vector<int> result = sol.bfs(adj);

    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

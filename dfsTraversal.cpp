#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findDfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ls) {
        ls.push_back(node);
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                findDfs(it, adj, vis, ls);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0); 
        int start = 0; 
        vector<int> dfsResult;
        findDfs(start, adj, vis, dfsResult);
        return dfsResult;
    }
};

int main() {
    vector<vector<int>> adj = {
        {1, 2},  // Node 0 connected to 1, 2
        {0, 3, 4},  // Node 1 connected to 0, 3, 4
        {0, 4},  // Node 2 connected to 0, 4
        {1, 5},  // Node 3 connected to 1, 5
        {1, 2, 5},  // Node 4 connected to 1, 2, 5
        {3, 4}  // Node 5 connected to 3, 4
    };

    Solution sol;
    vector<int> result = sol.dfs(adj);

    cout << "DFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

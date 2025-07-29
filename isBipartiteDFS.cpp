#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool isBipartiteDFS(vector<vector<int>>& graph, int color[], int node, int col){
        if(color[node] != -1) {
            return color[node] == col;  // Already colored: check for conflict
        }
        color[node] = col;
        for(auto it : graph[node]){
            if(!isBipartiteDFS(graph, color, it, 1 - col)) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        for(int i = 0; i < n; i++) color[i] = -1;  // -1 means uncolored

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(!isBipartiteDFS(graph, color, i, 0)) return false;
            }
        }
        return true;
    }
};

// ----------- MAIN FUNCTION TO TEST --------------
int main() {
    Solution sol;

    // Example 1: Bipartite graph
    vector<vector<int>> graph1 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    // Example 2: Not Bipartite (odd cycle)
    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    cout << "Graph 1 is Bipartite: " << (sol.isBipartite(graph1) ? "Yes" : "No") << endl;
    cout << "Graph 2 is Bipartite: " << (sol.isBipartite(graph2) ? "Yes" : "No") << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    bool dfs(vector<vector<int>>& adj, vector<int>& visit, vector<int>& ans, int idx) {
        if (visit[idx] == 2) {
            return true; // Already visited and processed
        }
        visit[idx] = 1; // Mark as visiting
        for (int nei : adj[idx]) {
            if (visit[nei] == 1) {
                return false; // Cycle detected
            }
            if (!dfs(adj, visit, ans, nei)) {
                return false;
            }
        }
        visit[idx] = 2; // Mark as visited
        ans.push_back(idx); // Add to result
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]); // edge[1] -> edge[0]
        }
        vector<int> visit(numCourses, 0), ans;
        for (int i = 0; i < numCourses; i++) {
            if (visit[i] == 0 && !dfs(adj, visit, ans, i)) {
                return {}; // Cycle detected, no valid ordering
            }
        }
        reverse(ans.begin(), ans.end()); // Reverse to get correct order
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};

    vector<int> order = sol.findOrder(numCourses, prerequisites);

    if (order.empty()) {
        cout << "No valid course ordering exists due to a cycle." << endl;
    } else {
        cout << "Valid course order: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}

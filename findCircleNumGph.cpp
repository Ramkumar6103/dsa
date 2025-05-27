#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(int start, vector<int> &vis, vector<vector<int>>& adj){
        vis[start] = 1;
        for(auto it : adj[start]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        int count = 0;

        //To change the adjacency matrix into adjacency list
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int result = sol.findCircleNum(isConnected);
    cout << "Number of provinces: " << result << endl;

    return 0;
}

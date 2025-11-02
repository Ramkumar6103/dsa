#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    void dfs(int r, int c, string dir, vector<vector<int>>& vis, map<pair<int, int>, int>& mp){
        int n = vis.size();
        int m = vis[0].size();
        if(r < 0 || c < 0 || r >= n || c >= m) return;
        if(mp.find({r, c}) != mp.end()) return;
        if(vis[r][c] == 1) return;

        vis[r][c] = 1;

        if(dir == "r"){
            dfs(r, c+1, "r", vis, mp);
        }
        if(dir == "l"){
            dfs(r, c-1, "l", vis, mp);
        }
        if(dir == "u"){
            dfs(r-1, c, "u", vis, mp);
        }
        if(dir == "d"){
            dfs(r+1, c, "d", vis, mp);
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        map<pair<int, int>, int> mp;

        for(auto& it : guards){
            mp[{it[0], it[1]}]++;
            vis[it[0]][it[1]] = 1;
        }

        for(auto& it : walls){
            mp[{it[0], it[1]}]++;
            vis[it[0]][it[1]] = 1;
        }

        for(auto& it : guards){
            int r = it[0];
            int c = it[1];
            dfs(r, c+1, "r", vis, mp);
            dfs(r, c-1, "l", vis, mp);
            dfs(r+1, c, "d", vis, mp);
            dfs(r-1, c, "u", vis, mp);
        }

        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == 0) cnt++;
            }
        }

        return cnt;
    }
};

int main() {
    Solution sol;

    int m = 4, n = 6;
    vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};

    int result = sol.countUnguarded(m, n, guards, walls);
    cout << "Number of unguarded cells: " << result << endl;

    return 0;
}

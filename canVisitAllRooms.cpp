#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> Vis(n, false);
        Vis[0] = true;
        queue<int> que;
        for (int i = 0; i < rooms[0].size(); i++) {
            que.push(rooms[0][i]);
        }
        while (!que.empty()) {
            int key = que.front();
            que.pop();
            if (!Vis[key]) {
                Vis[key] = true;
                for (int i = 0; i < rooms[key].size(); i++) {
                    que.push(rooms[key][i]);
                }
            }
        }
        for (bool visited : Vis) {
            if (!visited)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Sample input: each index represents a room, and the vector at that index contains keys to other rooms
    vector<vector<int>> rooms = {
        {1},        // Room 0 has a key to room 1
        {2},        // Room 1 has a key to room 2
        {3},        // Room 2 has a key to room 3
        {}          // Room 3 has no keys
    };

    bool result = sol.canVisitAllRooms(rooms);
    cout << (result ? "All rooms can be visited." : "Not all rooms can be visited.") << endl;

    return 0;
}

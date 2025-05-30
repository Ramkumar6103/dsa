#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// class Solution {                         // DFS
// public:
//     void dfs(int row, int col, vector<vector<int>>& image, int initColor, int newColor, int m, int n) {
//         if (row < 0 || row >= m || col < 0 || col >= n) return;
//         if (image[row][col] != initColor) return;

//         image[row][col] = newColor;

//         // Move in 4 directions
//         dfs(row - 1, col, image, initColor, newColor, m, n); // up
//         dfs(row + 1, col, image, initColor, newColor, m, n); // down
//         dfs(row, col - 1, image, initColor, newColor, m, n); // left
//         dfs(row, col + 1, image, initColor, newColor, m, n); // right
//     }

//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int m = image.size();
//         int n = image[0].size();
//         int initColor = image[sr][sc];

//         if (initColor != color) {
//             dfs(sr, sc, image, initColor, color, m, n);
//         }

//         return image;
//     }
// };

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int init = image[sr][sc];
        if (init == color) return image;

        queue<pair<int,int>> que;
        que.push({sr, sc});
        image[sr][sc] = color;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!que.empty()) {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                    if (image[nrow][ncol] == init) {
                        image[nrow][ncol] = color;
                        que.push({nrow, ncol});
                    }
                }
            }
        }

        return image;
    }
};

// Utility function to print a 2D vector
void printImage(const vector<vector<int>>& image) {
    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

int main() {
    // Sample image
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1, sc = 1, newColor = 2;

    Solution sol;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    cout << "Flood-filled image:" << endl;
    printImage(result);

    return 0;
}

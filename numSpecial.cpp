#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    continue;
                }

                bool good = true;

                // Check column
                for(int r = 0; r < n; r++){
                    if(r != i && mat[r][j] == 1){
                        good = false;
                        break;
                    }
                }

                // Check row
                for(int c = 0; c < m; c++){
                    if(c != j && mat[i][c] == 1){
                        good = false;
                        break;
                    }
                }

                if(good){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    cout << "Enter matrix elements (0 or 1):\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    Solution obj;
    int result = obj.numSpecial(mat);

    cout << "Number of special positions: " << result << endl;

    return 0;
}
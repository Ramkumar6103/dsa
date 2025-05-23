#include <iostream>
#include <vector>
#include <stack>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

/*
    int rows = 3, cols = 4;
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));


    int matrix[3][4] = {0};

*/

/*
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][n - 1 - i] = matrix[i][j];
            }
        }

        matrix = ans; // Copy result back to input
    }
*/

    // void rotate(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     vector<vector<int>> ans(n, vector<int>(n));
    //     stack<int> st;

    //     for (int j = 0; j < n; j++) {
    //         for (int i = 0; i < n; i++) {
    //             st.push(matrix[i][j]);
    //         }
    //         for (int k = 0; k < n; k++) {
    //             ans[j][k] = st.top();
    //             st.pop();
    //         }
    //     }

    //     matrix = ans;
    // }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    Solution sol;
    sol.rotate(matrix);

    cout << "\nRotated Matrix (90 degrees clockwise):\n";
    printMatrix(matrix);

    return 0;
}

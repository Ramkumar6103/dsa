#include <iostream>
#include <vector>
#include <stack>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
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
    sol.transpose(matrix);

    cout << "\nTranspose of the given matrix:\n";
    printMatrix(matrix);

    return 0;
}

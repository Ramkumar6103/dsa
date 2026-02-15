#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralMatrix(vector<vector<int>> &matrix){
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int rowStart = 0;
        int rowEnd = m - 1;
        int colStart = 0;
        int colEnd = n - 1;
        while(rowStart <= rowEnd && colStart <= colEnd){
            for(int i=colStart;i<=colEnd;i++){
                ans.push_back(matrix[rowStart][i]);
                cout<<matrix[rowStart][i]<<" ";
            }
            rowStart++;
            for(int i=rowStart;i<=rowEnd;i++){
                ans.push_back(matrix[i][colEnd]);
                cout<<matrix[i][colEnd]<<" ";
            }
            colEnd--;
            if(rowStart <= rowEnd){
                for(int i=colEnd;i>=colStart;i--){
                ans.push_back(matrix[rowEnd][i]);
                cout<<matrix[rowEnd][i]<<" ";
            }
            }

            rowEnd--;
            if(colStart <= colEnd){
                for(int i=rowEnd;i>=rowStart;i--){
                ans.push_back(matrix[i][colStart]);
                cout<<matrix[i][colStart]<<" ";
                }
            }

             colStart++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<int> ans = sol.spiralMatrix(matrix);
    return 0;
}


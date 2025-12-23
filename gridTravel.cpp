#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void gridTravel(int n, int m){
        vector<vector<int>> grid(n+1, vector<int> (m+1));
        grid[1][1] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                grid[i][j] += grid[i-1][j] + grid[i][j-1]; 
            }
        }
        for(auto g : grid){
            for(int n : g){
                cout<<n<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Solution obj;
    obj.gridTravel(4,4);
    return 0;
}
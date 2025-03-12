#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxProfit(vector<int> &arr) {
    int n = arr.size();
    int profit = 0;
    int cost = 0;
    int mini = arr[0];
    for (int i = 0; i < n; i++) {
        cost = arr[i] - mini;
        profit = max(cost, profit);
        mini = min(mini, arr[i]);
    }
    return profit;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {7,1,5,3,6,4};
    cout << "Max profit is: " << obj.maxProfit(arr)<< endl;
    return 0;
}


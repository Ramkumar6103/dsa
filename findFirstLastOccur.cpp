#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    int n = nums.size() - 1;
    int first = -1, last = -1;
    for(int i = 0; i <= n; i++) {
        if(nums[i] == target) {
            if(first == -1) first = i;
            last = i;
        }
    }
    res.push_back(first);
    res.push_back(last);
    return res;
}

int main() {
    int key = 13;
    vector<int> nums = {3, 4, 13, 13, 13, 20, 40};
    
    vector<int> result = searchRange(nums, key);
    cout << "First occurrence: " << result[0] << ", Last occurrence: " << result[1] << endl;

    return 0;
}

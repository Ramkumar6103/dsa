#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        int dom = 0, count = 0;
        for(int n : nums){
            mpp[n]++;
        }
        for(auto [i,j] : mpp){
            if(j > n/2){
                dom = i;
                count = j;
            }
        }
        //find the leftside and rightside count
        int leftcount = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i] == dom){
                leftcount++;
            }
            int leftside = i+1;
            int rightside = n-leftside;
            int rightcount = count - leftcount;
        if(leftcount > leftside / 2 && rightcount > rightside/2 ){
            return i;
        }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,1,3,1,1,1,7,1,2,1};
    int result = solution.minimumIndex(nums);

    if (result != -1) {
        cout << "The minimum index is: " << result << endl;
    } else {
        cout << "No valid index found." << endl;
    }

    return 0;
}

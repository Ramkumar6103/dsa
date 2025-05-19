#include <iostream>
#include <vector>
using namespace std;

    // A triangle is called equilateral if it has all sides of equal length.
    // A triangle is called isosceles if it has exactly two sides of equal length.
    // A triangle is called scalene if all its sides are of different lengths.

class Solution {
public:
    bool isTriangle(vector<int>& nums) {
        return (nums[0] + nums[1] > nums[2] &&
                nums[1] + nums[2] > nums[0] &&
                nums[0] + nums[2] > nums[1]);
    }

    string triangleType(vector<int>& nums) {
        if (!isTriangle(nums)) return "none";
        if (nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";
        else if (nums[0] == nums[1] || nums[0] == nums[2] || nums[1] == nums[2]) return "isosceles";
        return "scalene";
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 5}; // Example numbers

    cout << "Given sides: ";
    for (int i = 0; i < 3; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    string result = sol.triangleType(nums);
    cout << "The triangle is: " << result << endl;

    return 0;
}

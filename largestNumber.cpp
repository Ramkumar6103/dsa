#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> changeTOString(vector<int>& nums) {
        vector<string> cS;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (n == 0) {
                cS.push_back("0");
                continue;
            }
            stack<int> que;
            while (n != 0) {
                int d = n % 10;
                n = n / 10;
                que.push(d);
            }
            string s = "";
            while (!que.empty()) {
                s += to_string(que.top());
                que.pop();
            }
            cS.push_back(s);
        }
        return cS;
    }

public:
    string largestNumber(vector<int>& nums) {
        // Convert integer vector -> string vector
        vector<string> cS = changeTOString(nums);

        // Custom comparator
        sort(cS.begin(), cS.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // If the biggest element is "0", answer is "0"
        if (cS[0] == "0") return "0";

        // Create final answer
        string ans = "";
        for (int i = 0; i < cS.size(); i++) {
            ans += cS[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {3, 30, 34, 5, 9};

    // Get result
    string result = sol.largestNumber(nums);

    // Print output
    cout << "Largest Number: " << result << endl;

    return 0;
}

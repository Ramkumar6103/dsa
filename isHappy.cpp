#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> convertArray(int n){
        vector<int> ans;
        while(n > 0){
            int d = n % 10;
            n = n / 10;
            ans.push_back(d);
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
public:
    bool isHappy(int n) {
        while(n != 1 && n != 4 ){
            vector<int> ans;
            ans = convertArray(n);
            int temp = 0;
            for(int ns : ans){
                temp = temp + ns * ns;
            }
            n = temp;
        }
        return n == 1;
    }
};

int main() {
    Solution sol;
    int number = 2;

    // cout << "Enter a number to check if it's a happy number: ";
    // cin >> number;

    if(sol.isHappy(number)) {
        cout << number << " is a happy number!" << endl;
    } else {
        cout << number << " is not a happy number." << endl;
    }

    return 0;
}

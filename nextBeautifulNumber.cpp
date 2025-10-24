#include<bits/stdc++.h>
using namespace std;

// class Solution {
// private:
//     bool isBeautiful(unordered_map<int, int> temp) {
//         for (auto [x, y] : temp) {
//             if (x != y) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     unordered_map<int, int> findNumberCnt(int n) {
//         unordered_map<int, int> num;
//         int d = 0;
//         while (n != 0) {
//             d = n % 10;
//             n = n / 10;
//             num[d]++;
//         }
//         return num;
//     }

// public:
//     int nextBeautifulNumber(int n) {
//         n++;
//         while (true) {
//             auto nums = findNumberCnt(n);
//             bool ans = isBeautiful(nums);
//             if (ans) return n;
//             else n++;
//         }
//         return 0;
//     }
// };

class Solution {
private:
    bool isBeautiful(int n){
        vector<int> cnt(10,0);
        int temp = n;
        while(temp != 0){
            int d = temp % 10;
            temp = temp / 10;
            cnt[d]++;
        }
        for(int i=0;i<10;i++){
            if(cnt[i] != 0 && cnt[i] != i) return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        while(true){
            n++;
            if(isBeautiful(n)){
                return n;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    // int input = 890319;
    int input = 780001;
    // cout << "Enter a number: ";
    // cin >> input;
    int result = sol.nextBeautifulNumber(input);
    cout << "Next beautiful number is: " << result << endl;
    return 0;
}

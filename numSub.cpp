#include <iostream>
#include <string>
using namespace std;

// class Solution {
// private:
//     int findOneCount(int i,int j, string s){
//         int cnt = 0;
//         // cout<<i<<" "<<j<<" ";
//         for(int x=i;x<=j;x++){
//             // cout<<"[ "<<s[x]<<" ] ";
//             if(s[x] == '0'){
//                 return 0;
//             }
//             cnt++;
//         }
//         return cnt;
//     }
// public:
//     int numSub(string s) {
//         int ans = 0;
//         int mod = 1000000007;
//         for(int i=0;i<s.size();i++){
//             for(int j=i;j<s.size();j++){
//                 int cnt = findOneCount(i,j,s);
//                 if(cnt !=0) ans++;
//             }
//         }
//         ans = ans % mod;
//         return ans;
//     }
// };
class Solution {            // Optimized approach
public:
    int numSub(string s) {
        long long ans = 0;
        int mod = 1e9 + 7;
        long long cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                cnt++;
            } else {
                cnt = 0;
            }
            ans = (ans + cnt) % mod;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string input = "0110111";
    // cout << "Enter binary string: ";
    // cin >> input;

    int result = sol.numSub(input);
    cout << "Number of substrings with only '1's: " << result << endl;

    return 0;
}

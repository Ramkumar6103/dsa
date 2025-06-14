#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string ma = "";
        string mi = "";
        int n = s.size();
        char ele;
        for(int i=0;i<n;i++){
            if(s[i] != '9'){
                ele = s[i];
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i] == ele) ma += '9';
            else ma += s[i];
        }
        for(int i=0;i<n;i++){
            if(s[i] == s[0]) mi += '0';
            else mi += s[i];
        }

        int maxi = stoi(ma);
        int mini = stoi(mi);
        return maxi - mini;
    }
};

int main() {
    Solution sol;
    int num = 11891;

    // cout << "Enter a number: ";
    // cin >> num;

    int result = sol.minMaxDifference(num);
    cout << "Min-Max Difference: " << result << endl;

    return 0;
}

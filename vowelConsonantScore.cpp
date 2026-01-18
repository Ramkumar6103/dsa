#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vowelConsonantScore(string s) {
        short int v = 0, c = 0;
        for (char ch : s) {
            int val = ch;
            if (val >= 97) { // lowercase letters
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                    ch == 'u') {
                    v++;
                } else {
                    c++;
                }
            }
        }
        return c == 0 ? 0 : v / c;
    }
};

int main() {
    Solution obj;
    string s = "hello";
    
    // cin >> s;   // Input the string
    cout << obj.vowelConsonantScore(s) << endl;

    return 0;
}

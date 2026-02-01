#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseByType(string s) {
        string apt = "";
        string spl = "";

        // Separate lowercase letters and others
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z')
                apt.push_back(ch);
            else
                spl.push_back(ch);
        }

        int i = apt.size() - 1;
        int j = spl.size() - 1;

        // Rebuild the string
        for (int k = 0; k < s.size(); k++) {
            if (s[k] >= 'a' && s[k] <= 'z') {
                s[k] = apt[i--];
            } else {
                s[k] = spl[j--];
            }
        }

        return s;
    }
};

int main() {
    Solution obj;

    string s = ")ebc#da@f(";

    string result = obj.reverseByType(s);
    cout << "Output: " << result << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int i = 0, count = 0, width = 0;
        while (i < s.size()) {
            width += widths[s[i] - 'a'];
            if (width > 100) {
                width = widths[s[i] - 'a'];
                count++;
            }
            i++;
        }
        return {count + 1, width};
    }
};

int main() {
    Solution sol;
    vector<int> widths = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
                          10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
                          10, 10, 10, 10, 10, 10};
    string s = "abcdefghijklmnopqrstuvwxyz";

    vector<int> result = sol.numberOfLines(widths, s);

    cout << "Number of lines: " << result[0] << endl;
    cout << "Last line width: " << result[1] << endl;

    return 0;
}

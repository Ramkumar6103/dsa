#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        bool check = true;
        int res = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '*' && check)
                res++;
            else if(s[i] == '|')
                check = !check;
        }
        return res;
    }
};

int main() {
    Solution sol;
    string input = "l|*e*et|c**o|*de|";

    int result = sol.countAsterisks(input);
    cout << "Number of asterisks outside '|' pairs: " << result << endl;

    return 0;
}

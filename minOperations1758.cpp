#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int start0 = 0, start1 = 0;

        for(int i = 0; i < n; i++){
            // Pattern: 010101...
            if(s[i] != (i % 2 == 0 ? '0' : '1')){
                start0++;
            }

            // Pattern: 101010...
            if(s[i] != (i % 2 == 0 ? '1' : '0')){
                start1++;
            }
        }

        return min(start0, start1);
    }
};

int main() {
    Solution obj;
    
    string s;
    cout << "Enter binary string: ";
    cin >> s;

    int result = obj.minOperations(s);

    cout << "Minimum operations needed: " << result << endl;

    return 0;
}
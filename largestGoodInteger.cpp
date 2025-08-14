#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string maxTriplet = "";
        string triplet = "";
        int n = num.size();
        for (int i = 0; i <= n - 3; i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                triplet = num.substr(i, 3);
                if (triplet > maxTriplet) maxTriplet = triplet;
            }
        }
        return maxTriplet;
    }
};

int main() {
    Solution sol;

    // Sample test cases
    string input1 = "6777133339";
    string input2 = "2300019";
    string input3 = "42352338";

    cout << "Input: " << input1 << "\nOutput: " << sol.largestGoodInteger(input1) << "\n\n";
    cout << "Input: " << input2 << "\nOutput: " << sol.largestGoodInteger(input2) << "\n\n";
    cout << "Input: " << input3 << "\nOutput: " << sol.largestGoodInteger(input3) << "\n";

    return 0;
}

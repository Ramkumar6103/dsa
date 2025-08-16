#include <iostream>
#include <string>

class Solution {
public:
    int maximum69Number(int num) {
        std::string s = std::to_string(num);
        for (char &c : s) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        return std::stoi(s);
    }
};

int main() {
    Solution sol;
    
    int input = 9669;
    // std::cout << "Enter a number consisting of digits 6 and 9: ";
    // std::cin >> input;

    int result = sol.maximum69Number(input);
    std::cout << "Maximum number after changing at most one 6 to 9: " << result << std::endl;

    return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string result;
        
        // Handle signs
        if ((numerator < 0) ^ (denominator < 0)) {
            result += '-';
        }
        
        // Convert to long long to avoid overflow
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        
        // Integer part
        result += to_string(num / den);
        long long remainder = num % den;
        
        if (remainder == 0) {
            return result;
        }
        
        // Fractional part
        result += '.';
        unordered_map<long long, int> remainderPositions;
        
        while (remainder != 0) {
            // If we've seen this remainder before, we have a repeating decimal
            if (remainderPositions.find(remainder) != remainderPositions.end()) {
                int pos = remainderPositions[remainder];
                result.insert(pos, "(");
                result += ')';
                break;
            }
            
            // Store the current position of this remainder
            remainderPositions[remainder] = result.size();
            
            // Perform division
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    int numerator = 1, denominator = 8;
    
    // cout << "Enter numerator: ";
    // cin >> numerator;
    // cout << "Enter denominator: ";
    // cin >> denominator;
    
    if (denominator == 0) {
        cout << "Error: Denominator cannot be zero!" << endl;
        return 1;
    }
    
    string result = solution.fractionToDecimal(numerator, denominator);
    cout << numerator << "/" << denominator << " = " << result << endl;
    
    return 0;
}
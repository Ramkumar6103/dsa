#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> toSeparateWords(string text) {
        vector<string> words;
        string temp = "";
        for (char ch : text) {
            if (ch == ' ') {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp = "";
                }
            } else {
                temp += ch;
            }
        }
        if (!temp.empty()) words.push_back(temp);
        return words;
    }

public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> words = toSeparateWords(text); 
        int cnt = words.size();
        
        for (string &s : words) {
            for (char ch : brokenLetters) {
                if (s.find(ch) != string::npos) { 
                    cnt--;
                    break;  
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    // Sample input
    string text = "hello world laptop";
    string brokenLetters = "ad";

    // Function call
    int result = sol.canBeTypedWords(text, brokenLetters);

    // Output result
    cout << "Number of words that can be typed: " << result << endl;

    return 0;
}

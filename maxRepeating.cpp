#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string repeat = word;
        int count = 0;
        while (sequence.find(repeat) != string::npos) {
            count++;
            repeat += word;
        }
        return count;
    }
};

int main() {
    Solution sol;
    string sequence = "ababc";
    string word = "ab";

    // cout << "Enter the sequence: ";
    // cin >> sequence;
    
    // cout << "Enter the word: ";
    // cin >> word;

    int result = sol.maxRepeating(sequence, word);
    cout << "The maximum repeating count is: " << result << endl;

    return 0;
}

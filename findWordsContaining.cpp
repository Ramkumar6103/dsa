#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            for (char ch : words[i]) {
                if (x == ch) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"apple", "banana", "cherry", "date", "elderberry"};
    char x = 'a';
    
    vector<int> result = sol.findWordsContaining(words, x);
    
    cout << "Indices of words containing '" << x << "': ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}

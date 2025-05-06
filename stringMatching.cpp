#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<string> words = {"mass", "as", "hero", "superhero"};

    Solution sol;
    vector<string> result = sol.stringMatching(words);

    cout << "Matching words found as substrings: ";
    for(const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}

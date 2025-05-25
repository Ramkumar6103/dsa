#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mpp;
        for(string s : words){
            mpp[s]++;
        }
        int count = 0;
        int isPalindrome = 0;
        for(auto [w , freq] : mpp){
            string s = w;
            reverse(s.begin(), s.end());

            // Check the value is already Palindrome
            if(w == s){
                count += (freq / 2) * 4;
                if(freq % 2) isPalindrome = 1;
            }
            else if(w < s && mpp.count(s)){
                count += min(freq, mpp[s]) * 4;
            }
        }
        return count + isPalindrome * 2;
    }
};

int main() {
    vector<string> words = {"ab", "ba", "cd", "dc", "ee", "ee", "ee"};
    
    Solution sol;
    int result = sol.longestPalindrome(words);

    cout << "Longest possible palindrome length: " << result << endl;

    return 0;
}

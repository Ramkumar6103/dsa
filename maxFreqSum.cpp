#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool isVowel(char &ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch == 'u';
    }
public:
    int maxFreqSum(string s) {
        int maxVol = 0;
        int maxCon = 0;
        unordered_map<char,int> vowel;
        unordered_map<char,int> conson;
        for(char ch : s){
            if(isVowel(ch)){
                vowel[ch]++;
                maxVol = max(maxVol, vowel[ch]);
            }
            else{
                conson[ch]++;
                maxCon = max(maxCon, conson[ch]);
            }
        }
        return maxVol + maxCon;
    }
};

int main() {
    Solution sol;
    string input = "aeiouxyz";
    // cout << "Enter a lowercase string: ";
    // cin >> input;

    int result = sol.maxFreqSum(input);
    cout << "Maximum frequency sum of most common vowel and consonant: " << result << endl;

    return 0;
}

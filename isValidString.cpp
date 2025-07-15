#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3)
            return false;

        int vowel = 0, cons = 0, num = 0;

        for (char ch : word) {
            if ('0' <= ch && ch <= '9') {
                num++;
            } else if (isalpha(ch)) {
                char lower = tolower(ch);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    vowel++;
                } else {
                    cons++;
                }
            } else {
                return false; // contains invalid character
            }
        }

        return (vowel >= 1 && cons >= 1 && vowel + cons + num == word.size());
    }
};

int main() {
    Solution sol;
    string testWord;

    cout << "Enter a word to check validity: ";
    cin >> testWord;

    if (sol.isValid(testWord)) {
        cout << "The given word is Valid word " << endl;
    } else {
        cout << "The given word is Invalid word " << endl;
    }

    return 0;
}

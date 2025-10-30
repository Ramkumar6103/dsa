#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const long long MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    // Fast modular exponentiation
    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    // Precompute factorials and inverse factorials up to n
    void precomputeFactorials(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modPow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    // Count distinct permutations for one word
    long long findAnagramPermutation(const string &s) {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        long long res = fact[s.size()];
        for (auto &p : freq)
            res = res * invFact[p.second] % MOD;
        return res;
    }

    // Split sentence into individual words
    vector<string> separate(const string &s) {
        vector<string> result;
        stringstream ss(s);
        string word;
        while (ss >> word)
            result.push_back(word);
        return result;
    }

public:
    int countAnagrams(string s) {
        vector<string> words = separate(s);

        // Find longest word to precompute factorials efficiently
        int maxLen = 0;
        for (auto &w : words)
            maxLen = max(maxLen, (int)w.size());

        precomputeFactorials(maxLen);

        long long ans = 1;
        for (auto &w : words)
            ans = ans * findAnagramPermutation(w) % MOD;

        return (int)ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // Example 1
    string s1 = "too hot";
    cout << "Input: " << s1 << "\n";
    cout << "Output: " << sol.countAnagrams(s1) << "\n";  // Expected: 18

    // Example 2
    string s2 = "abc def";
    cout << "\nInput: " << s2 << "\n";
    cout << "Output: " << sol.countAnagrams(s2) << "\n";  // Expected: 36 (6*6)

    // Example 3
    string s3 = "a aa aaa";
    cout << "\nInput: " << s3 << "\n";
    cout << "Output: " << sol.countAnagrams(s3) << "\n";  // Expected: 1 (1*1*1)

    return 0;
}

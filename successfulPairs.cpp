#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    //     long long s = spells.size();
    //     long long p = potions.size();
    //     long long tempC = 0;
    //     vector<int> ans;
    //     for (long long i = 0; i < s; i++) {
    //         for (long long j = 0; j < p; j++) {
    //             long long tempM = static_cast<long long>(spells[i]) * potions[j];
    //             if (tempM >= success) {
    //                 tempC++;
    //             }
    //         }
    //         ans.push_back(tempC);
    //         tempC = 0;
    //     }
    //     return ans;
    // }

        static vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        const int n=spells.size();
        vector<int> result(n, 0);
        
        const int m=potions.size();
        const int maxPotion=potions[m-1];

        
        for (int i=0; i<n; i++) {
            int spell=spells[i];
            long long k = (success+spell-1)/spell;
            if (k<=maxPotion) {
                result[i]=m-(lower_bound(potions.begin(), potions.end(), k)-potions.begin());
            }
        }       
        return result;
    }
};

int main() {
    // Sample input
    vector<int> spells = {10, 20, 30};
    vector<int> potions = {1, 2, 3, 4};
    long long success = 60;

    Solution sol;
    vector<int> result = sol.successfulPairs(spells, potions, success);

    // Output the result
    cout << "Successful pairs for each spell:" << endl;
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}

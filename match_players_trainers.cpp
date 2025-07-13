#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) 
    {
        const int n=p.size(), m=t.size();
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());
        int match=0;
        for (int i=0, j=0; i<n && j<m; i++){
            const int pi=p[i];
            while(j<m && t[j]<pi) j++;
            if (j<m) {
                j++;
                match++;
            }
        } 
        return match;
    }
};

int main() {
    // Test case 1
    vector<int> players1 = {4, 7, 9};
    vector<int> trainers1 = {8, 2, 5, 8};
    
    cout << "Test Case 1:" << endl;
    cout << "Players: ";
    for (int p : players1) cout << p << " ";
    cout << endl;
    cout << "Trainers: ";
    for (int t : trainers1) cout << t << " ";
    cout << endl;
    cout << "Maximum matches: " << Solution::matchPlayersAndTrainers(players1, trainers1) << endl;
    cout << endl;
    
    // Test case 2
    vector<int> players2 = {1, 1, 1};
    vector<int> trainers2 = {10};
    
    cout << "Test Case 2:" << endl;
    cout << "Players: ";
    for (int p : players2) cout << p << " ";
    cout << endl;
    cout << "Trainers: ";
    for (int t : trainers2) cout << t << " ";
    cout << endl;
    cout << "Maximum matches: " << Solution::matchPlayersAndTrainers(players2, trainers2) << endl;
    cout << endl;
    
    // Test case 3
    vector<int> players3 = {2, 3, 4};
    vector<int> trainers3 = {1, 2, 3, 4};
    
    cout << "Test Case 3:" << endl;
    cout << "Players: ";
    for (int p : players3) cout << p << " ";
    cout << endl;
    cout << "Trainers: ";
    for (int t : trainers3) cout << t << " ";
    cout << endl;
    cout << "Maximum matches: " << Solution::matchPlayersAndTrainers(players3, trainers3) << endl;
    
    return 0;
} 
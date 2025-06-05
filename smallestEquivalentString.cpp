#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    char findMinChar(unordered_map<char, vector<char>>& adj, char currChar, vector<char> vis){
        vis[currChar - 'a'] = 1;
        char minChar = currChar;
        for(auto ch: adj[currChar]){
            if(!vis[ch - 'a']){
                minChar = min(minChar, findMinChar(adj, ch, vis));
            }
        }
        return minChar;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int m = baseStr.size();
        unordered_map<char, vector<char>> adj;
        for(int i=0;i<n;i++){
            int u = s1[i];
            int v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result = "";
        for(int i=0;i<m;i++){
            vector<char> vis(26,0);
            char minChar = baseStr[i];
            minChar = min(minChar, findMinChar(adj, minChar, vis));
            result += minChar;
        }
        return result;    
    }
};

int main() {
    Solution solution;
    string s1 = "parker";
    string s2 = "morris";
    string baseStr = "parser";
    
    string result = solution.smallestEquivalentString(s1, s2, baseStr);
    cout << "Smallest Equivalent String: " << result << endl;
    
    return 0;
}

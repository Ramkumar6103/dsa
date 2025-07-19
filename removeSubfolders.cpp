#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> str;
        unordered_map<string,int> check;
        for(int i = 0; i < folder.size(); i++) {
            if(folder[i].size() == 2) {
                str.push_back(folder[i]);
                for(auto ch : folder[i]) {
                    if(ch != '/') check[string(1, ch)]++;
                }
            } else {
                int flag = 0;
                int s = folder[i].size();
                string strtemp = "";
                for(int j = 0; j < s;) {
                    if(folder[i][j] == '/') strtemp = "";
                    while(j < s && folder[i][j] != '/') {
                        strtemp += folder[i][j];
                        j++;
                    }
                    if(check[strtemp] > 0) {
                        flag = 1;
                        break;
                    }
                    j++; // Move past the '/'
                }
                if(flag == 0){
                    str.push_back(folder[i]);
                    check[strtemp]++;
                } 
            }
        }
        return str;
    }

    //     vector<string> removeSubfolders(vector<string>& folder) {
    //     unordered_set<string> dirSet(folder.begin(), folder.end());
    //     vector<string> res;
    //     for (const string& dir : folder) {
    //         res.push_back(dir);
    //         for (int i = 0; i < dir.size(); ++i) {
    //             if (dir[i] == '/' && dirSet.count(dir.substr(0, i))) {
    //                 res.pop_back();
    //                 break;
    //             }
    //         }
    //     }
        
    //     return res;
    // }

    // vector<string> removeSubfolders(vector<string>& folder) {
    //     sort(folder.begin(), folder.end());
    //     vector<string> result;

    //     for (const string& path : folder) {
    //         if (result.empty() || path.compare(0, result.back().size(), result.back()) != 0 || path[result.back().size()] != '/') {
    //             result.push_back(path);
    //         }
    //     }

    //     return result;
    // }
};

int main() {
    Solution solution;
    vector<string> folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    // vector<string> folder = {"/a/b/c","/abc/d"};
    vector<string> result = solution.removeSubfolders(folder);

    cout << "Filtered folders:\n";
    for(const string& f : result) {
        cout << f << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
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
};

int main() {
    Solution solution;
    vector<string> folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};

    vector<string> result = solution.removeSubfolders(folder);

    cout << "Filtered folders:\n";
    for(const string& f : result) {
        cout << f << endl;
    }

    return 0;
}

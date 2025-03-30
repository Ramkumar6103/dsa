#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last_occurrence;
        for (int i = 0; i < s.size(); i++) {
            last_occurrence[s[i]] = i;
        }

        vector<int> result;
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            end = max(end, last_occurrence[s[i]]);
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "ababcbacadefegdehijhklij";
    vector<int> partitions = solution.partitionLabels(s);

    cout << "Partition lengths: ";
    for (int length : partitions) {
        cout << length << " ";
    }
    cout << endl;

    return 0;
}

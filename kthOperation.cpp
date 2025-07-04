#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // char kthCharacter(long long k, vector<int>& operations) {
    //     string init = "a";
    //     string temp;
    //     int n = operations.size();
    //     for(int i=0;i<n;i++){
    //         if(operations[i] == 0){
    //             init += init;
    //             if(init.size() > k) return init[k-1];
    //         }
    //         else if(operations[i] == 1){
    //             temp = init;
    //             if(init.size() < k){
    //                 for(char ch : init){
    //                     temp += ch + 1;
    //                 }
    //                 init = temp;
    //             }else{
    //                 return init[k-1];
    //             }
    //         }
    //     }
    //     return init[k-1];
    // }
        char kthCharacter(long long k, vector<int>& operations) {
        int shift = 0;
        vector<long long> lengths;
        long long len = 1;

        for (int op : operations) {
            len *= 2;
            lengths.push_back(len);
            if (len >= k) break;
        }

        for (int i = lengths.size() - 1; i >= 0; --i) {
            long long half = lengths[i] / 2;
            int op = operations[i];
            if (k > half) {
                k -= half;
                if (op == 1) shift++;
            }
        }

        return (char)((('a' - 'a' + shift) % 26) + 'a');
    }
};
int main(){
    Solution obj;
    int k = 10;
    vector<int> opt = {0,1,0,1};
    cout<<obj.kthCharacter(k,opt);
    return 0;
}
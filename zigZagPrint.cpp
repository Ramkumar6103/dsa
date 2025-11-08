#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void printZigZag(int n){
        int count = 1;
        int rev = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(i % 2 != 0){
                    cout<<count<<" ";
                    count++;
                }
                else{
                    cout<<rev<<" ";
                    rev--;
                }
            }
            if(i % 2 == 0){
               count = rev + i + 1;
            }
            else{
                rev = count + i;
            }
            cout<<endl;
        }
    }
};
int main(){
    int n = 5;
    Solution obj;
    obj.printZigZag(n);
    return 0;
}
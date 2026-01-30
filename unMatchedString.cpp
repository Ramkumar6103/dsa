#include<iostream>
using namespace std;
class Solution{
    public:
    void unMatchedString(string str1, string str2){
        int i = 0;
        int n = str1.size();
        string s1 = "";
        string s2 = "";
        while(i<n){
            if(str1[i] != str2[i]){           
                string s1 = "", s2 = "";
                while(i < n && str1[i] != str2[i]){
                    s1 += str1[i];
                    s2 += str2[i];
                    i++;
                }
                cout<<s1<<" "<<s2<<" ";
            }
            else{
                i++;
            }
        }
    }
};
int main(){
    Solution obj;
    string str1 = "schoollifeisusefull";
    string str2 = "schoollongofuselike";
    obj.unMatchedString(str1,str2);
    return 0;
}
#include<iostream>
#include<cctype>
using namespace std;
class Solution{
    private:
    public:
    bool isPalindrome(string s){
        int n = s.size();
        int i=0, j = n-1;
        while(i < j){
            s[i] = tolower(s[i]);
            s[j] = tolower(s[j]);

            while(!(s[i]>='a' && s[i] <='z')){
                cout<<s[i]<<" ";
                i++;
            }
            while(!(s[j]>='a' && s[j] <='z')){
                cout<<s[j]<<" ";
                j--;
            }
            if(s[i] != s[j]){
                return false;
            }   
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};
int main(){
    Solution obj;
    string s = "Ab@!Cb#a)";
    if(obj.isPalindrome(s)) cout<<"The given string is palindrome";
    else cout<<"The given string is not a palindrome";
    return 0;
}
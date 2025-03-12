#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
class Solution{
    public:
    bool validAnagram(string s, string t){
        // if(s.size() != t.size()) return false;
        // unordered_map<char,int> mp1;
        // for(int i=0;i<s.size();i++){
        //     mp1[s[i]]++;
        //     mp1[t[i]]--;
        // }
        // for(auto temp: mp1){
        //     if(temp.second != 0) return false;
        // }
        if(s.size() != t.size()) return false;
        unordered_map<char,int> mp1;
        for(char c: s) mp1[c]++;
        for(char c: t) mp1[c]--;
        for(auto temp: mp1){
            if(temp.second) return false;
        }
        return true;
        }
};
int main(){

    // Get starting timepoint
    auto start = high_resolution_clock::now();
    Solution obj;
    string s,t;
    //Strings should be have the same length...
    cout<<"Enter the first string: ";
    cin>>s;
    cout<<"Enter the second string: ";
    cin>>t;
    if(obj.validAnagram(s,t)) cout<<"The strings are anagram";
    else cout<<"The strings are not anagram";
    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to 
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
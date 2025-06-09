#include<bits/stdc++.h>
using namespace std;
int compareString(string s1, string s2){
    int mins = min(s1.size(),s2.size());
    for(int i=0;i<mins;i++){
        char c1 = s1[i];
        char c2 = s2[i];
        if(c1 != c2){
            return c1 - c2;
        }
    }
    return s1.size() - s2.size();
}
void lexicalOrderSort(vector<string>& s){
    int n = s.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(compareString(s[i],s[j]) > 0){
                string temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
int main(){
    vector<string> s = {"banana","apple","orange","mango","grapes","apples"};
    cout<<"Input string :"<<endl;
    for(string w : s){
        cout<<w<<" ";
    }
    lexicalOrderSort(s);
    cout<<"\nLexicographic sorting :"<<endl;
    for(string w : s){
        cout<<w<<" ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
string convert2Binary(int n){
    string res = "";
    while(n >= 1){
        if(n % 2 == 1) res+="1";
        else res+="0";
        n = n/2;
    }
    reverse(res.begin(),res.end());
    return res;
}
int convert2Decimal(string str){
    int num = 0;
    int p = 1;
    int n = str.size();
    for(int i = n-1;i>=0;i--){
        if(str[i] == '1'){
            num = num + p;
        }
        p = p*2;
    }
    return num;
}
int main(){
    int n = 13;
    string str = "1101";
    cout<<convert2Binary(n);
    cout<<endl;
    cout<<convert2Decimal(str);
    return 0;
}
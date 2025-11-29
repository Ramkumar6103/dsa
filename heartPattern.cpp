#include <iostream>
using namespace std;

void heartPattern(int n) {
    for(int i=0;i<n;i++){
    //space
    for(int j=n-i;j>0;j--){
        cout<<" ";
    }
    //star

        for(int j=1;j<=2*i+1;j++){
            cout<<"*";
        }
        cout << endl;
    }
    
}
int main() {
    cout<< "Heart Pattern:" << endl;
    int n = 5;
    // cout << "Enter the size of the heart pattern: ";
    // cin >> n;
    heartPattern(n);
    return 0;
}
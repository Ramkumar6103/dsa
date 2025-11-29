#include <iostream>
using namespace std;

void diamondPattern(int n) {
    //upper part
    for(int i=0;i<n;i++){
        for(int j=n-i;j>0;j--){
            cout<<" ";
        }
        for(int j=1;j<=2*i+1;j++){
            cout<<"*";
        }
        cout << endl;
    }
    //lower part
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<" ";
        }
        for(int j=0;j<(2*n)-(2*i+1);j++){
            cout<<"*";
        }
        cout << endl;
    }

}
int main() {
    cout<< "Diamond Pattern:" << endl;
    int n = 5;
    // cout << "Enter the size of the heart pattern: ";
    // cin >> n;
    diamondPattern(n);
    return 0;
}
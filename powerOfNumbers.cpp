#include<bits/stdc++.h>
using namespace std;
bool powerOfTwo(int n){
    //return n>0 && INT_MIN % n == 0;

    if(n <= 0) return false;
    while(n % 2 == 0){
        n /= 2;
    }
    return n == 1;
}
bool powerOfThree(int n) {
    if (n <= 0) return false;
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}
bool powerOfFour(int n) {
    if (n <= 0) return false;
    while (n % 4 == 0) {
        n /= 4;
    }
    return n == 1;
}
int main()
{
    int x = 16;
    int y = 27;
    int z = 64;
    cout<<powerOfTwo(x);
    cout<<endl;
    cout<<powerOfThree(y);
    cout<<endl;
    cout<<powerOfFour(z);
    return 0;
}
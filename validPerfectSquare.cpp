#include<bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int num) {
    int low = 0;
    int high = num;
    while(low <= high){
        long mid = (low + high)/2;
        long long sqt = mid * mid;
        if(sqt == num){
            return true;
        }  
        else if(sqt > num){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return false;
}
int main(){
    int num = 16;
    cout<<isPerfectSquare(num);
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // vector<int> replaceElements(vector<int>& arr) {
    //     int n = arr.size();
    //     if (n <= 1) {
    //         arr[n - 1] = -1;
    //         return arr;
    //     }

    //     for (int i = 0; i < n - 1; i++) {
    //         int maxi = 0;
    //         for (int j = i + 1; j < n; j++) {
    //             maxi = max(maxi, arr[j]);
    //         }
    //         arr[i] = maxi;
    //     }
    //     arr[n - 1] = -1;
    //     return arr;
    // }

    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        if(n==1){
            arr[0]=-1;
            return arr;
        }
        int maxi=max(arr[n-2],arr[n-1]);
        arr[n-2]=arr[n-1];
        arr[n-1]=-1;
        if(n==2)return arr;
        for(int i=n-3;i>=0;i--){
            int a = arr[i];
            arr[i]=maxi;
            maxi=max(maxi,a);
        }
        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {17,18,5,4,6,1};
    // int n , num;

    // cout << "Enter the number of elements in the array: ";
    // cin >> n;

    // cout << "Enter the elements: ";
    // for (int i = 0; i < n; i++) {
    //     cin >> num;
    //     arr.push_back(num);
    // }

    vector<int> result = sol.replaceElements(arr);

    cout << "Modified array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int day = 0;
        int startWeek = 1;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += day + startWeek;
            cout << "Day " << i + 1 << ": " << day + startWeek << ", Total: " << ans << endl;
            day++;
            if(day == 7) {
                startWeek++;
                day = 0;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of days: ";
    cin >> n;
    int result = sol.totalMoney(n);
    cout << "\nTotal money saved after " << n << " days: " << result << endl;
    return 0;
}

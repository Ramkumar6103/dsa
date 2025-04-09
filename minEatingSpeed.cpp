#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canEatInTime(piles, mid, h)) 
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return left;
    }

    bool canEatInTime(vector<int>& piles, int k, int h) {
        long hours = 0;
        for (int pile : piles) {
            int div = pile / k;
            hours += div;
            if (pile % k != 0) 
                hours++;
        }
        return hours <= h;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    // Calling the function
    int result = solution.minEatingSpeed(piles, h);

    // Output the result
    cout << "Minimum eating speed: " << result << endl;

    return 0;
}

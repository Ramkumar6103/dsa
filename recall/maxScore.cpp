#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftsum = 0;
        int rightsum = 0;

        // Take first k cards from the left
        for(int i = 0; i < k; i++){
            leftsum += cardPoints[i];
        }

        int ans = leftsum;

        // Try taking cards from right side
        for(int i = 1; i <= k; i++){
            leftsum -= cardPoints[k - i];
            rightsum += cardPoints[n - i];

            int temp = leftsum + rightsum;
            ans = max(ans, temp);
        }

        return ans;
    }
};

int main() {
    int n, k;

    cout << "Enter number of cards: ";
    cin >> n;

    vector<int> cardPoints(n);

    cout << "Enter card points: ";
    for(int i = 0; i < n; i++) {
        cin >> cardPoints[i];
    }

    cout << "Enter k (number of cards to pick): ";
    cin >> k;

    Solution obj;
    int result = obj.maxScore(cardPoints, k);

    cout << "Maximum Score: " << result << endl;

    return 0;
}
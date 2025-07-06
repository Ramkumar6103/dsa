#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
private:
    vector<int> n1, n2;
    unordered_map<int, int> mpp;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int n : n2) {
            mpp[n]++;
        }
    }

    void add(int index, int val) {
        mpp[n2[index]]--;
        n2[index] += val;
        mpp[n2[index]]++;
    }

    int count(int tot) {
        int count = 0;
        for (int n : n1) {
            count += mpp[tot - n];
        }
        return count;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {3, 4, 5};

    FindSumPairs* obj = new FindSumPairs(nums1, nums2);

    cout << "Initial count for total 7: " << obj->count(7) << endl; // should count pairs (2,5), (3,4)
    
    obj->add(1, 1); // nums2 becomes {3, 5, 5}
    
    cout << "Count after adding 1 to index 1 in nums2, total 7: " << obj->count(7) << endl; // now pairs: (2,5), (3,4 - no longer exists)

    delete obj;
    return 0;
}

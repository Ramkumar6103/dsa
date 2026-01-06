#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == nullptr) return -1;

        vector<long long> s;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int qlen = que.size();
            long long sum = 0;

            for (int i = 0; i < qlen; i++) {
                TreeNode* temp = que.front();
                que.pop();

                sum += temp->val;

                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }

            s.push_back(sum);
        }

        if (k > s.size()) return -1;

        sort(s.begin(), s.end(), greater<long long>());
        return s[k - 1];
    }
};

int main() {
    /*
        Example Tree:
                5
               / \
              8   9
             / \   \
            2   1   7

        Level sums:
        Level 0 → 5
        Level 1 → 17
        Level 2 → 10
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(8);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(7);

    Solution sol;

    int k = 2;
    long long result = sol.kthLargestLevelSum(root, k);

    cout << "Kth Largest Level Sum: " << result << endl;

    return 0;
}

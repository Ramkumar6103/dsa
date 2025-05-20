#include <iostream>
#include <vector>
using namespace std;

/** Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool twoSum(vector<int>& ans, int k) {
        int i = 0;
        int j = ans.size() - 1;
        while (i < j) {
            int sum = ans[i] + ans[j];
            if (sum == k) return true;
            else if (sum < k) i++;
            else j--;
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);
        return twoSum(ans, k);
    }
};

// Helper function to insert nodes into a BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

int main() {
    TreeNode* root = nullptr;

    // Create BST by inserting values
    vector<int> values = {5, 3, 6, 2, 4, 7};
    for (int val : values) {
        root = insertBST(root, val);
    }

    int k = 9;  // Example target

    Solution sol;
    if (sol.findTarget(root, k)) {
        cout << "Found two elements in BST that sum to " << k << endl;
    } else {
        cout << "No two elements found in BST that sum to " << k << endl;
    }

    return 0;
}

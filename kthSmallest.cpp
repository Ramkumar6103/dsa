#include <iostream>
#include <vector>

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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* node, vector<int>& arr) {
        if (node == nullptr) return;
        inorder(node->left, arr);
        arr.push_back(node->val);
        inorder(node->right, arr);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);
        return ans[k - 1];
    }
};

// Helper function to insert nodes into a binary search tree
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

int main() {
    TreeNode* root = nullptr;
    root = insertBST(root, 5);
    root = insertBST(root, 3);
    root = insertBST(root, 6);
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 1);

    Solution sol;
    int k = 3;
    cout << "The " << k << "rd smallest element in the BST is: " << sol.kthSmallest(root, k) << endl;

    return 0;
}

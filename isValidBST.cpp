#include <iostream>
#include <climits>
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
    bool isValidBSTree(TreeNode* root, long minV, long maxV){
        if(root == NULL) return true;
        if(root->val <= minV || root->val >= maxV) return false;
        return isValidBSTree(root->left, minV, root->val) && isValidBSTree(root->right, root->val, maxV);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTree(root, LONG_MIN, LONG_MAX);
    }
};

int main() {
    // Constructing a binary tree
    //      5
    //     / \
    //    3   7
    //   / \   \
    //  2   4   8

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3, new TreeNode(2), new TreeNode(4));
    root->right = new TreeNode(7, nullptr, new TreeNode(8));

    Solution solution;
    if (solution.isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    // Cleanup memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

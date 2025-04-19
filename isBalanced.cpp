#include <iostream>
#include <cmath> // For abs() function
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
    int dfHeight(TreeNode* root) {
        if (root == NULL) return 0;
        int lh = dfHeight(root->left);
        if (lh == -1) return -1;
        int rh = dfHeight(root->right);
        if (rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfHeight(root) != -1;
    }
};

int main() {
    // Creating a sample binary tree:
    //          1
    //         / \
    //        2   2
    //       / \
    //      3   3
    //     / \
    //    4   4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);

    Solution solution;
    if (solution.isBalanced(root)) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is not balanced." << endl;
    }

    // Clean up allocated memory
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}

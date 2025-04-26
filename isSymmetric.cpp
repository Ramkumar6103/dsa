#include <iostream>
using namespace std;

// Definition for a binary tree node.
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
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetricHelp(root->left, root->right);
    }
    bool isSymmetricHelp(TreeNode* rootLeft, TreeNode* rootRight) {
        if (rootLeft == NULL || rootRight == NULL) {
            return rootLeft == rootRight;
        }
        if (rootLeft->val != rootRight->val) return false;
        return isSymmetricHelp(rootLeft->left, rootRight->right) && isSymmetricHelp(rootLeft->right, rootRight->left);
    }
};

// Main function to test the isSymmetric method
int main() {
    // Create a binary tree: [1, 2, 2, 3, 4, 4, 3]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;
    bool result = solution.isSymmetric(root);

    cout << "The binary tree is " << (result ? "symmetric" : "not symmetric") << "." << endl;

    // Clean up the memory allocated for the tree
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

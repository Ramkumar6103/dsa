#include <iostream>
#include <algorithm>
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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

    int height(TreeNode* node, int& maxi) {
        if (!node) return 0;
        int lh = height(node->left, maxi);
        int rh = height(node->right, maxi);
        maxi = max(maxi, lh + rh);
        return 1 + max(lh, rh);
    }
};

// Helper function to create a simple binary tree and test the function
TreeNode* createSampleTree() {
    // Creating a simple binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    Solution solution;
    int diameter = solution.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << diameter << endl;

    // Clean up memory allocated for the tree
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

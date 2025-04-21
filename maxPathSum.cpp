#include <iostream>
#include <climits>
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
    int maxSum(TreeNode* node, int& maxi) {
        if (node == NULL) return 0;
        int maxL = max(0, maxSum(node->left, maxi));
        int maxR = max(0, maxSum(node->right, maxi));
        maxi = max(maxi, node->val + maxL + maxR);
        return node->val + max(maxL, maxR);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxSum(root, maxi);
        return maxi;
    }
};

// Helper function to create a sample binary tree
TreeNode* createSampleTree() {
    // Creating the following binary tree:
    //        10
    //       /  \
    //      2    10
    //     / \     \
    //    20   1    -25
    //               /  \
    //              3    4
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    Solution solution;
    int maxPathSum = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << maxPathSum << endl;

    // Clean up memory allocated for the tree
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBinaryTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* createBinaryTree(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = createBinaryTree(nums, left, mid - 1);
        node->right = createBinaryTree(nums, mid + 1, right);
        return node;
    }
};

// Helper function to print the tree (in-order traversal)
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9};  // Example sorted array

    TreeNode* root = solution.sortedArrayToBST(nums);

    cout << "In-order Traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

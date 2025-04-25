#include <iostream>
#include <vector>
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
    vector<int> findRecursive(TreeNode* root, int level, vector<int>& ans) {
        if (root == NULL) return ans;
        if (level == ans.size()) ans.push_back(root->val);
        findRecursive(root->right, level + 1, ans);
        findRecursive(root->left, level + 1, ans);
        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        ans = findRecursive(root, 0, ans);
        return ans;
    }
};

// Helper function to create a tree and test the solution
int main() {
    // Create a binary tree: [1, 2, 3, null, 5, null, 4]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution solution;
    vector<int> rightView = solution.rightSideView(root);

    cout << "Right side view of the binary tree: ";
    for (int val : rightView) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the memory allocated for the tree
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

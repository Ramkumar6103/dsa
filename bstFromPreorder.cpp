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
    TreeNode* buildBST(TreeNode* root, int val){
        if (root == nullptr) return new TreeNode(val);  // Fix: was missing return

        if (root->val > val) {
            if (root->left == nullptr) root->left = new TreeNode(val);
            else buildBST(root->left, val);
        } else {
            if (root->right == nullptr) root->right = new TreeNode(val);
            else buildBST(root->right, val);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            buildBST(root, preorder[i]);
        }
        return root;
    }
};

// Helper function to print inorder traversal of the BST
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution solution;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode* bstRoot = solution.bstFromPreorder(preorder);

    cout << "Inorder Traversal of the BST: ";
    printInorder(bstRoot);
    cout << endl;

    return 0;
}

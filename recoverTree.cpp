#include <iostream>
#include <climits>
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
private:
    TreeNode* first;
    TreeNode* last;
    TreeNode* middle;
    TreeNode* prev;

    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        
        if (prev && prev->val > root->val) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last) swap(first->val, last->val);
        else if (first && middle) swap(first->val, middle->val);
    }
};

// Helper function to do in-order traversal and print tree values
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Manual tree creation with two swapped nodes for testing
TreeNode* createSwappedTree() {
    /*
         3
        / \
       1   4
          /
         2

     Tree should be:
         2
        / \
       1   4
          /
         3
     */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    return root;
}

int main() {
    TreeNode* root = createSwappedTree();

    cout << "Inorder traversal before recovery: ";
    printInorder(root);
    cout << endl;

    Solution sol;
    sol.recoverTree(root);

    cout << "Inorder traversal after recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}

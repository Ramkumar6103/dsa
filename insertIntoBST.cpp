#include <iostream>
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
    TreeNode* insertElement(TreeNode* root, int val){
        TreeNode* node = root;
        if(node == NULL) return new TreeNode(val);
        while(node != NULL){
            if(node->val < val){
                if(node->right == NULL){
                    TreeNode* newNode = new TreeNode(val);
                    node->right = newNode;
                    break;
                }
                node = node->right;
            }
            else if(node->val > val) {
                if(node->left == NULL){
                    TreeNode* newNode = new TreeNode(val);
                    node->left = newNode;
                    break;
                }
                node = node->left;
            }
        }
        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insertElement(root, val);
    }
};

// Utility function to print the BST inorder
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    Solution sol;
    
    // Creating initial BST: 4 -> 2, 7
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    cout << "Original BST (Inorder): ";
    inorderTraversal(root);
    cout << endl;

    // Insert new value
    int valToInsert = 5;
    root = sol.insertIntoBST(root, valToInsert);

    cout << "BST after inserting " << valToInsert << " (Inorder): ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

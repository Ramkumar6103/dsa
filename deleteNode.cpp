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
    TreeNode* findRightLast(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return findRightLast(root->right);
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;
        TreeNode* rightChild = findRightLast(root->left);
        rightChild->right = root->right;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            return helper(root);
        }
        TreeNode* temp = root;
        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else if(root->val < key){
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return temp;
    }
};

// Helper function to insert a node into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// In-order traversal (Left, Root, Right)
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = nullptr;

    // Inserting nodes into the BST
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);

    cout << "Original BST (in-order): ";
    inorder(root);
    cout << endl;

    Solution solution;
    int key = 3;
    root = solution.deleteNode(root, key);

    cout << "BST after deleting " << key << " (in-order): ";
    inorder(root);
    cout << endl;

    return 0;
}

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
    TreeNode* findElement(TreeNode* node, int val){
        if(node == NULL) return NULL;
        if(node->val == val){
            return node;
        }
        else if(node->val < val){
            return findElement(node->right,val);
        }
        else {
            return findElement(node->left,val);
        }
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return findElement(root, val);
    }
};

// Helper function to insert a node in BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int main() {
    // Create BST:      4
    //                /   \
    //               2     7
    //              / \
    //             1   3

    TreeNode* root = nullptr;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);

    Solution solution;
    int searchValue = 2;
    TreeNode* result = solution.searchBST(root, searchValue);

    if (result) {
        cout << "Node found with value: " << result->val << endl;
    } else {
        cout << "Node not found." << endl;
    }

    return 0;
}

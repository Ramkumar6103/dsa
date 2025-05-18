#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* findLCA(TreeNode* node, TreeNode* r, TreeNode* s){
        if(node == NULL) return NULL;
        if(node->val >= r->val && node->val <= s->val) return node;
        else if(node->val > r->val && node->val > s->val) return findLCA(node->left, r, s);
        else if(node->val < r->val && node->val < s->val) return findLCA(node->right, r, s);
        return node;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) swap(p, q); // Ensure p has smaller value
        return findLCA(root, p, q);
    }
};

// Helper function to insert a node into a BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// Helper function to find a node by value
TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;
    if (val < root->val) return findNode(root->left, val);
    return findNode(root->right, val);
}

int main() {
    // Create BST
    TreeNode* root = NULL;
    root = insertBST(root, 6);
    insertBST(root, 2);
    insertBST(root, 8);
    insertBST(root, 0);
    insertBST(root, 4);
    insertBST(root, 7);
    insertBST(root, 9);
    insertBST(root, 3);
    insertBST(root, 5);

    // Find nodes for which LCA is to be found
    TreeNode* p = findNode(root, 2);
    TreeNode* q = findNode(root, 8);

    // Call solution
    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    // Output result
    if (lca)
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "Lowest Common Ancestor not found." << endl;

    return 0;
}

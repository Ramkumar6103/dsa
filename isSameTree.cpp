#include <iostream>
using namespace std;

// Definition of the TreeNode structure
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) return (p == q);
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

int main() {
    Solution solution;

    // Create two sample trees
    TreeNode* tree1 = createSampleTree();
    TreeNode* tree2 = createSampleTree();

    // Check if they are the same
    if (solution.isSameTree(tree1, tree2)) {
        cout << "The trees are the same." << endl;
    } else {
        cout << "The trees are different." << endl;
    }

    // Free allocated memory
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0;
}

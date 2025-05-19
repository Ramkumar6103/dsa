#include <iostream>
#include <stack>
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

// BST Iterator class
class BSTIterator {
    stack<TreeNode*> stk;

public:
    BSTIterator(TreeNode* root) {
        pushALL(root);
    }
    
    int next() {
        TreeNode* temp = stk.top();
        stk.pop();
        pushALL(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }

private:
    void pushALL(TreeNode* root) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
    }
};

// Function to insert a node in the BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Main function to test BSTIterator
int main() {
    TreeNode* root = nullptr;
    // Creating the BST with values [7, 3, 15, 9, 20]
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 15);
    root = insert(root, 9);
    root = insert(root, 20);

    BSTIterator* obj = new BSTIterator(root);

    cout << "BST Iterator output in sorted order:\n";
    while (obj->hasNext()) {
        cout << obj->next() << " ";
    }
    cout << endl;

    delete obj;
    return 0;
}

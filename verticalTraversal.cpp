#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with verticalTraversal method
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->val);
            if (node->left) {
                todo.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

// Helper function to build a binary tree from an array representation
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        
        if (nodes[i] != -1) { // Left child
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        
        if (i < nodes.size() && nodes[i] != -1) { // Right child
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    
    return root;
}

// Main function to test the verticalTraversal method
int main() {
    // Example input: [3, 9, 20, -1, -1, 15, 7] (-1 represents null)
    vector<int> nodes = {3, 9, 20, -1, -1, 15, 7};
    TreeNode* root = buildTree(nodes);
    
    Solution solution;
    vector<vector<int>> result = solution.verticalTraversal(root);
    
    cout << "Vertical Traversal: \n";
    for (const auto& column : result) {
        cout << "[";
        for (const auto& value : column) {
            cout << value << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}

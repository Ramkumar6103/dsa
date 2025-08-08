#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    void travel(Node* root, vector<int>& res){
        if(root == nullptr) return;
        res.push_back(root->val);
        for(auto child : root->children){
            travel(child, res);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        travel(root, res);
        return res;
    }
};

// Helper function to print the result
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Constructing the tree:
    //         1
    //      /  |  \
    //     3   2   4
    //    / \
    //   5   6

    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node3 = new Node(3, {node5, node6});
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    Node* root = new Node(1, {node3, node2, node4});

    Solution sol;
    vector<int> result = sol.preorder(root);

    cout << "Preorder Traversal: ";
    printVector(result);

    // Clean up memory
    delete node5;
    delete node6;
    delete node3;
    delete node2;
    delete node4;
    delete root;

    return 0;
}

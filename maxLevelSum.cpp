#include <iostream>
#include <queue>
#include <climits>
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
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);

        int maxsum = INT_MIN;
        int maxlevel = 1;
        int level = 1;

        while (!q.empty()) {
            int levelsum = 0;
            int qlen = q.size();

            for (int i = 0; i < qlen; i++) {
                TreeNode* temp = q.front();
                q.pop();

                levelsum += temp->val;

                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }

            if (levelsum > maxsum) {
                maxsum = levelsum;
                maxlevel = level;
            }
            level++;
        }
        return maxlevel;
    }
};


// class Solution {
// public:
//     int maxLevelSum(TreeNode* root) {
//         vector<long long> levelSum;
//         queue<TreeNode*> q;
//         long long sum = 0;
//         q.push(root);

//         while(!q.empty()) {
//             int size =  q.size();
//             for (int i = 0; i < size; i++) {
//                 TreeNode* node = q.front();
//                 q.pop();
//                 sum += node->val;

//                 if (node->left) q.push(node->left);
//                 if (node->right) q.push(node->right);
//             }
//             levelSum.push_back(sum);
//             sum = 0;
//         }

//         return max_element(levelSum.begin(), levelSum.end()) - levelSum.begin() + 1;
//     }
// };

int main() {
    /*
        Example Tree:
                1
               / \
              7   0
             / \
            7  -8

        Level sums:
        Level 1 -> 1
        Level 2 -> 7 + 0 = 7
        Level 3 -> 7 + (-8) = -1

        Answer = Level 2
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    Solution sol;
    int result = sol.maxLevelSum(root);

    cout << "Level with maximum sum: " << result << endl;

    return 0;
}


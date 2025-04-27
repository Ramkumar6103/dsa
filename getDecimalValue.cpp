#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        stack<int> s;
        ListNode* temp = head;
        while (temp != NULL) {
            s.push(temp->val);
            temp = temp->next;
        }
        int ans = 0;
        int i = 0;
        while (!s.empty()) {
            ans += pow(2, i) * s.top();
            i++;
            s.pop();
        }
        return ans;
    }
};

int main() {
    // Constructing a linked list: 1 -> 0 -> 1
    ListNode* node3 = new ListNode(1);
    ListNode* node2 = new ListNode(0, node3);
    ListNode* head = new ListNode(1, node2);

    // Creating an instance of Solution
    Solution solution;

    // Getting the decimal value from binary representation
    int result = solution.getDecimalValue(head);

    // Displaying the result
    cout << "Decimal value of the binary linked list: " << result << endl;

    // Freeing allocated memory
    delete node3;
    delete node2;
    delete head;

    return 0;
}

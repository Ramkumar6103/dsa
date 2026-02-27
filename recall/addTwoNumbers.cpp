#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;

        while (l1 || l2 || carry) {

            int num1 = (l1 != nullptr) ? l1->val : 0;
            int num2 = (l2 != nullptr) ? l2->val : 0;

            int sum = num1 + num2 + carry;
            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next;
    }
};

/* Helper function to create linked list from vector */
ListNode* createList(vector<int> arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

/* Helper function to print linked list */
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Example: 342 + 465 = 807
    // Stored as reverse order: [2,4,3] + [5,6,4]

    vector<int> v1 = {2, 4, 3};
    vector<int> v2 = {5, 6, 4};

    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);

    Solution obj;
    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "Result Linked List: ";
    printList(result);

    return 0;
}

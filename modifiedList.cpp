#include <bits/stdc++.h>
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head) return nullptr;  // handle empty list

        unordered_set<int> toDelete(nums.begin(), nums.end());

        // Skip nodes at the start that should be deleted
        while (head && toDelete.count(head->val)) {
            head = head->next;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            if (toDelete.count(curr->val)) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        return head;
    }
};

// Helper function to create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* temp = head;
    for (int i = 1; i < vals.size(); ++i) {
        temp->next = new ListNode(vals[i]);
        temp = temp->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper to free memory (optional for demo)
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Example: linked list = [1, 2, 3, 4, 5, 6]
    vector<int> listVals = {1, 2, 3, 4, 5, 6};
    ListNode* head = createList(listVals);

    // nums = [2, 4, 6] -> these should be deleted
    vector<int> numsToDelete = {2, 4, 6};

    cout << "Original list: ";
    printList(head);

    Solution s;
    head = s.modifiedList(numsToDelete, head);

    cout << "Modified list: ";
    printList(head);

    // Free memory
    deleteList(head);
    return 0;
}

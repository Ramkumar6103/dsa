#include <iostream>
#include <vector>
using namespace std;

/** Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* insertIntoFront(ListNode* ans, int n) {
        ListNode* temp = new ListNode(n);
        temp->next = ans;
        return temp;
    }

    ListNode* createList(long long num) {
        if (num == 0) return new ListNode(0);
        ListNode* ans = nullptr;
        while (num != 0) {
            int d = num % 10;
            num = num / 10;
            ans = insertIntoFront(ans, d);
        }
        return ans;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = l1;
        long long v1 = 0;
        while (temp != nullptr) {
            v1 = (v1 * 10) + temp->val;
            temp = temp->next;
        }

        temp = l2;
        long long v2 = 0;
        while (temp != nullptr) {
            v2 = (v2 * 10) + temp->val;
            temp = temp->next;
        }

        long long add = v1 + v2;
        return createList(add);
    }
};

// Helper to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& digits) {
    if (digits.empty()) return nullptr;
    ListNode* head = new ListNode(digits[0]);
    ListNode* current = head;
    for (size_t i = 1; i < digits.size(); ++i) {
        current->next = new ListNode(digits[i]);
        current = current->next;
    }
    return head;
}

// Helper to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Sample Input: l1 = [7, 2, 4, 3], l2 = [5, 6, 4]
    vector<int> v1 = {7, 2, 4, 3};  // represents 7243
    vector<int> v2 = {5, 6, 4};     // represents 564

    ListNode* l1 = createLinkedList(v1);
    ListNode* l2 = createLinkedList(v2);

    cout << "Input List 1: ";
    printLinkedList(l1);
    cout << "Input List 2: ";
    printLinkedList(l2);

    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Output (Sum): ";
    printLinkedList(result);

    return 0;
}

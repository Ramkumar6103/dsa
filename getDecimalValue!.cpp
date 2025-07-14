#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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
        int res = 0;
        vector<int> ans;
        ListNode * temp = head;
        while(temp != NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(ans[i] != 0){
                res += pow(2,i);
            }
        }
        return res;
    }
};

// Helper function to create a linked list from a vector of integers
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> testCases = {
        {1,0,1},      // 5
        {0},          // 0
        {1,1,1,1},    // 15
        {1,0,0,1,0}   // 18
    };

    Solution sol;
    for (size_t i = 0; i < testCases.size(); ++i) {
        ListNode* head = createList(testCases[i]);
        cout << "Test case " << i+1 << ": ";
        printList(head);
        cout << "Decimal value: " << sol.getDecimalValue(head) << endl << endl;
        // Free memory
        while (head) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    return 0;
}
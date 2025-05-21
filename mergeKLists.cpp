#include <iostream>
#include <vector>
#include <algorithm>
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

/*                             ------------------- Optimal approach using Priority queue (Min heap)
class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap: smallest value on top
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Push the head of each non-null list into the priority queue
        for (auto list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }
};

*/

class Solution {
private:
    void addIntoVector(ListNode* root, vector<int>& nums){
        ListNode* temp = root;
        while(temp != nullptr){
            nums.push_back(temp->val);
            temp = temp->next;
        }
    }

    ListNode* createList(vector<int>& list){
        if(list.empty()) return nullptr;
        ListNode* head = new ListNode(list[0]);
        ListNode* temp = head;
        for(int i = 1; i < list.size(); i++){
            temp->next = new ListNode(list[i]);
            temp = temp->next;
        }
        return head;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        for(int i = 0; i < lists.size(); i++){
            addIntoVector(lists[i], ans);
        }
        sort(ans.begin(), ans.end());
        return createList(ans);
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create linked list from vector
ListNode* createLinkedList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* temp = head;
    for (int i = 1; i < vals.size(); ++i) {
        temp->next = new ListNode(vals[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    // Create example input: 3 sorted linked lists
    vector<int> list1_vals = {1, 4, 5};
    vector<int> list2_vals = {1, 3, 4};
    vector<int> list3_vals = {2, 6};

    ListNode* list1 = createLinkedList(list1_vals);
    ListNode* list2 = createLinkedList(list2_vals);
    ListNode* list3 = createLinkedList(list3_vals);

    vector<ListNode*> lists = {list1, list2, list3};

    Solution sol;
    ListNode* merged = sol.mergeKLists(lists);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}

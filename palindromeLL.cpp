#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* convertArray2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
    // bool isPalindrome(Node* head){                           // using stack
    //     stack<int> st;
    //     Node* temp = head;
    //     while(temp != NULL){
    //         st.push(temp->data);
    //         temp = temp->next;
    //     }
    //     temp = head;
    //     while(temp != NULL){
    //         if(temp->data != st.top()){
    //             return false;
    //         }
    //         st.pop();
    //         temp = temp->next;
    //     }
    //     return true;
    // }
    Node* reverseLL(Node* head){
        if(head == NULL || head->next == NULL) return head;
        Node* newhead = reverseLL(head->next);
        Node* front = head->next;
            front->next = head;
            head->next = NULL;
        return newhead;
    }
    bool isPalindrome(Node* head) {                     // optimal approach
        Node* slow = head;
        Node* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* newhead = reverseLL(slow->next);
        Node* first = head;
        Node* second = newhead;
        while(second != NULL){
            if(first->data != second->data){
                reverseLL(newhead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(newhead);
        return true;
    }
int main(){
    vector<int> arr = {2,5,6,5,2};   
    Node* head = convertArray2LL(arr);
    printLL(head);
    cout<<endl;
    cout<<isPalindrome(head);
    return 0;
}
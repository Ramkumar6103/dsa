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
Node* removeNthFromEnd(Node* head, int n) {
    // if(head == NULL || head->next == NULL) return NULL;      //------bruteforce--------
    // int count = 0;
    // Node* temp = head;
    // while(temp != NULL){
    //     count++;
    //     temp = temp->next;
    // }
    // if(count == n){
    //     Node* newhead = head->next;
    //     delete head;
    //     return newhead;
    // }
    // int res = count - n;
    // temp = head;
    // while(temp != NULL){
    //     res--;
    //     if(res == 0){
    //         Node* delnode = temp->next;
    //         temp->next = temp->next->next;
    //         delete delnode;
    //         break;
    //     }
    //     temp = temp->next;
    // }
    // return head;

    if(head == NULL || head->next == NULL) return NULL;         //-------Optimal approach-------
        Node* fast = head;
        Node* slow = head;
            for(int i=0;i<n;i++){
                fast = fast->next;
            }
        while(fast != NULL && fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == NULL) return head->next;
        Node* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
}
int main(){
    vector<int> arr = {2,5,6,5,2};   
    Node* head = convertArray2LL(arr);
    printLL(head);
    cout<<endl;
    head = removeNthFromEnd(head, 2);
    printLL(head);
    return 0;
}
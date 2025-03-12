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
Node* reverseLL(Node* head){ 
    // if(head == NULL) return NULL;                                //------brute force-------
    // Node* temp = head;
    // stack<int> st;
    // while(temp != NULL){
    //     st.push(temp->data);
    //     temp = temp->next;
    // }
    // temp = head;
    // while(temp != NULL){
    //     temp->data = st.top();
    //     st.pop();
    //     temp = temp->next;
    // }
    // return head;
    // if(head == NULL) return NULL;                                //------optimal--------
    // Node* temp = head;
    // Node* front = NULL;
    // Node* prev = NULL;
    // while(temp != NULL){
    //     front = temp->next;
    //     temp->next = prev;
    //     prev = temp;
    //     temp = front;
    // }
    // return prev;
    if(head == NULL || head->next == NULL) return head;            //-------recursive-------
    Node* newhead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}
int main(){
    vector<int> arr = {2,5,6,7,9};   
    Node* head = convertArray2LL(arr);
    printLL(head);
    cout<<endl;
    head = reverseLL(head);
    printLL(head);
    return 0;
}
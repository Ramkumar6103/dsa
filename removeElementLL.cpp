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
Node* removeElement(Node* head, int val){ 
    if(head == NULL || head->next == NULL) return head;
    Node* temp = new Node(0);
    temp->next = head;
    Node* curr = temp;
    while(curr->next != NULL){
        if(curr->next->data == val){
            curr->next = curr->next->next;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}
int main(){
    vector<int> arr = {1,1,2,2,3,4,5,5};
    int k = 2;   
    Node* head = convertArray2LL(arr);
    printLL(head);
    cout<<endl;
    head = removeElement(head, 2);
    printLL(head);
    return 0;
}
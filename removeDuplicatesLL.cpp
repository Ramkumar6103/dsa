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
Node* removeDuplicates(Node* head){ 
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    while(temp != NULL && temp->next != NULL){
        if(temp->data == temp->next->data){
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
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
    head = removeDuplicates(head);
    printLL(head);
    return 0;
}
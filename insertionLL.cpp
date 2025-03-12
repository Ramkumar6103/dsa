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
Node* insertHead(Node* head,int val){
    if(head == NULL){
        Node* newNode = new Node(val);
        head = newNode;
    }
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    return head;
}
Node* insertTail(Node* head,int val){
    if(head == NULL){
        Node* newNode = new Node(val);
        head = newNode;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    newNode->next = NULL;
    return head;
}
Node* insertK(Node* head, int val,int k){
    if(head == NULL){
        Node* newNode = new Node(val);
        head = newNode;
    }
    if(k == 1){
        Node* temp = head;
        Node* newNode = new Node(val);
        newNode->next = temp;
        head = newNode;
        return head;
    }
    int count = 0;
    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == k){
            Node* newNode = new Node(val);
            newNode->next = temp;
            prev->next = newNode;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {2,5,6,7,9};   
    Node* head = convertArray2LL(arr);
    printLL(head);
    cout<<endl;
    head = insertHead(head, 10);
    printLL(head);
    cout<<endl;
    head = insertTail(head, 25);
    printLL(head);
    cout<<endl;
    head = insertK(head, 30, 1);
    printLL(head);
    return 0;
}
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
    Node* temp = head;
    Node* prev = NULL;
    Node* front = NULL;
    while(temp != NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
Node* findKthNode(Node* temp, int k){
    k-= 1;
    while(temp != NULL && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
}
Node* reverseKGroup(Node* head, int k){
    //if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    Node* kthNode = NULL;
    Node* prevNode = NULL;
    Node* nextNode = NULL;
    while(temp != NULL){
        kthNode = findKthNode(temp, k);
        if(kthNode == NULL){
            if(prevNode) prevNode->next = temp;
            break;
        }
        nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLL(temp);
        if(temp == head){
            head = kthNode;
        }
        else{
            prevNode->next = kthNode;
        }
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,0};   
    Node* head = convertArray2LL(arr);
    printLL(head);
    cout<<endl;
    // head = reverseLL(head);
    // printLL(head);
    // cout<<end;
    head = reverseKGroup(head, 3);
    printLL(head);
    return 0;
}
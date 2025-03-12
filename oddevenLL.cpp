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
Node* oddEvenList(Node* head) {
    // vector<int> v;                                         // bruteforce approach
    // Node* temp = head;
    // if(head == NULL || head->next == NULL) return head;
    // while(temp != NULL && temp->next != NULL){
    //     v.push_back(temp->data);
    //     temp = temp->next->next;
    // }
    // if(temp) v.push_back(temp->data);
    // temp = head->next;
    // while(temp != NULL && temp->next != NULL){
    //     v.push_back(temp->data);
    //     temp = temp->next->next;
    // }
    // if(temp) v.push_back(temp->data);
    // int i = 0;
    // temp = head;
    // while(temp != NULL){
    //     temp->data = v[i];
    //     temp = temp->next;
    //     i++;
    // }
    // return head;

    if(head == NULL || head->next == NULL) return head;          // optimal approach
    Node* odd = head;
    Node* evenhead = head->next;
    Node* even = head->next;

    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next= even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenhead;
    return head;
}

int main(){
    vector<int> arr = {2,5,6,5,2};   
    Node* head = convertArray2LL(arr);
    printLL(head);
    cout<<endl;
    head = oddEvenList(head);
    printLL(head);
    return 0;
}
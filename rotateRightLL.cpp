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
Node* rotateRightLL(Node* head,int k){ 
    if(head == NULL || head->next == NULL) return head;
        Node* tail = head;
        int len = 1;
        while(tail->next != NULL){
            len++;
            tail = tail->next;
        }

        if( k % len == 0 ) return head;
        k = k % len;
        int count = len - k;
        tail->next = head;
        Node* temp = head;
        while(count > 1 ){
            count--;
            temp = temp->next;
        }
        //Node* temp = findNthNode(head, len - k);
        head = temp->next;
        temp->next = NULL;
        return head;
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 2;   
    Node* head = convertArray2LL(arr);
    printLL(head);
    cout<<endl;
    head = rotateRightLL(head, k);
    printLL(head);
    return 0;
}
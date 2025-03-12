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
bool detectLoopLL(Node* head){                  //--------Brute force---------
    unordered_map<ListNode* , int> mpp;
        ListNode* temp = head;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){
                return true;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }
        return false;
}
int main(){
    vector<int> arr = {2,5,6,7,9,2};   
    Node* head = convertArray2LL(arr);
    printLL(head);
    cout<<endl;
    cout<<detectLoopLL(head);
    return 0;
}
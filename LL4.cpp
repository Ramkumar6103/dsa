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
Node* convertArray2LL(vector <int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int lengthOfLL(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}
int searchIfPresent(Node* head, int target){
    {
        Node* temp = head;
        while(temp){
            if(temp->data == target) return 1;
            temp = temp->next;
        }
        return 0;
    }
}

int main(){
    vector<int> arr = {2,5,6,7,9};   
    cout<<arr[0]<<endl;
    Node* head = convertArray2LL(arr);
    cout<<searchIfPresent(head,5);
    return 0;
}
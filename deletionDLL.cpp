#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1,Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* convertArray2DLL(vector<int> nums){
    Node* head = new Node(nums[0]);
    Node* prev = head;
    for(int i = 1; i < nums.size(); i++){
        Node* temp = new Node(nums[i],nullptr, prev);
        prev->next = temp;
        prev = prev->next;
    }
    return head;
}
void printDLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    head->back = NULL;
    delete temp;
    return head;
}
Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    
    while(tail->next->next != NULL){
        tail = tail->next;
    }
    Node* deleteNode = tail->next;
    tail->next = NULL;
    delete deleteNode;

    return head;
}
Node* deleteK(Node* head, int k){
    if(head == NULL) return head;
    int count = 0;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        head->back = NULL;
        delete(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != NULL){
        count++;
        if(count == k){
            prev->next = temp->next;
            temp->back = prev;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node* deleteEle(Node* head, int ele){
    if(head == NULL) return head;
    Node* temp = head;
    Node* prev = nullptr;
    if(head->data == ele){
        Node* temp = head;
        head = head->next;
        head->back = NULL;
        delete(temp);
        return head;
    }
    while(temp != NULL){
        if(temp->data == ele){
            prev->next = temp->next;
            temp->back = prev;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {2,5,6,7,9,8,1,0,3,4};   
    Node* head = convertArray2DLL(arr);
    printDLL(head);
    head = deleteHead(head);
    cout<<endl;
    printDLL(head);
    head = deleteTail(head);
    cout<<endl;
    printDLL(head);
    head = deleteK(head,6);
    cout<<endl;
    printDLL(head);
    head = deleteEle(head,0);
    cout<<endl;
    printDLL(head);
    return 0;
}
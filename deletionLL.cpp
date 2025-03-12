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
int searchIfPresent(Node* head, int target)
    {
        Node* temp = head;
        while(temp){
            if(temp->data == target) return 1;
            temp = temp->next;
        }
        return 0;
    }
    void printLL(Node* head){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    Node* removesHead(Node* head){
        if(head == NULL) return head;
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* removeTail(Node* head){
        if(head == NULL || head->next == NULL) return NULL;
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return head;
    }
    Node* removeK(Node* head, int k){
        if(head == NULL) return head;
        int count = 0;
        if(k == 1){
            Node* temp = head;
            head = head->next;
            delete(temp);
            return head;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while(temp != NULL){
            count++;
            if(count == k){
                prev->next = prev->next->next;
                delete prev->next;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
    Node* removeEle(Node* head, int ele){
        if(head == NULL) return head;
        if(head->data == ele){
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        Node* prev = NULL;
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == ele){
                prev->next = prev->next->next;
                delete temp;
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
    head = removesHead(head);
    printLL(head);
    cout<<endl;
    head = removeTail(head);
    printLL(head);
    cout<<endl;
    head = removeK(head, 1);
    printLL(head);
    cout<<endl;
    head = removeEle(head,7);
    printLL(head);
    return 0;
}
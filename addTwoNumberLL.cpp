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
void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node* addTwoNumbers(Node* head1, Node* head2){
    Node* dummy = new Node(0);
    Node* curr = dummy;
    int carry = 0;
    while(head1 && head2){
        int num = carry + head1->data + head2->data;
        carry = num / 10;
        Node* newNode = new Node(num % 10);
        curr->next = newNode;
        curr = curr->next;
        head1 = head1->next;
        head2 = head2->next;
    }
    while(head1){
        int num = carry + head1->data;
        carry = num / 10;
        Node* newNode = new Node(num % 10);
        curr->next = newNode;
        curr = curr->next;
        head1 = head1->next;
    }
    while(head2){
        int num = carry + head2->data;
        carry = num / 10;
        Node* newNode = new Node(num % 10);
        curr->next = newNode;
        curr = curr->next;
        head2 = head2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummy->next;
}

int main() {
    // // Linked List1 : 2 4 3
    Node* head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(3);

    // // Linked List1 : 5 6 4
    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);

    printLL(head1);
    cout<<endl;
    printLL(head2);
    cout<<endl;
    Node* head = addTwoNumbers(head1,head2);
    printLL(head);
    return 0;
}

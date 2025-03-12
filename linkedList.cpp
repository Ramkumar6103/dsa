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
};
int main(){
    vector<int> arr = {2,5,6,7,9};   
    cout<<arr[0]<<endl;
    Node x =  Node(arr[0], nullptr);
    Node *y = &x;
    Node *z = new Node(arr[1], nullptr);
    Node n = Node(arr[3], nullptr);
    cout<<y->data<<endl;
    cout<<z->data<<endl;
    cout<<n.data;
    return 0;
}
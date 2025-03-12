#include<bits/stdc++.h>
using namespace std;

// queue<int> qu;                                   // My solution
// public:
//     MyStack() {

//     }
    
//     void push(int x) {
//         int s = qu.size();
//         qu.push(x);
//         for(int i=1;i<=s;i++){
//             qu.push(qu.front());
//             qu.pop();
//         }
//     }
    
//     int pop() {
//         int val = qu.front();
//         qu.pop();
//         return val;
//     }
    
//     int top() {
//         return qu.front();
//     }
    
//     bool empty() {
//         return qu.empty();
//     }

class Stack {
    queue<int>q;
    public:
    void Push(int x){
        int s = q.size();
        q.push(x);
        for(int i=1;i<=s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    int Pop(){
        int val = q.front();
        q.pop();
        return val;
    }
    int Size(){
        return q.size();
    }
    bool Top(){
        return q.front();
    }
};

int main() {
  Stack s;
  s.Push(3);
  s.Push(2);
  s.Push(4);
  s.Push(5);
  cout << "Top of the stack: " << s.Top() << endl;
  cout << "Size of the stack before removing element: " << s.Size() << endl;
  cout << "The deleted element is: " << s.Pop() << endl;
  cout << "Top of the stack after removing element: " << s.Top() << endl;
  cout << "Size of the stack after removing element: " << s.Size();
  return 0;

}
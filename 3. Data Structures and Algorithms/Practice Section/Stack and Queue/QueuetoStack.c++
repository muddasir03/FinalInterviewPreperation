#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
    queue<int> q;
    
public:
    void push(int x) {
        int size = q.size();
        q.push(x);        
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    void pop() {
        if (!q.empty()) {
            q.pop();
        } else {
            cout << "Stack is empty\n";
        }
    }
    
    int top() {
        if (!q.empty()) {
            return q.front();
        } else {
            cout << "Stack is empty\n";
            return -1;
        }
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {
    StackUsingOneQueue stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout << "Top element: " << stack.top() << endl; // Output: 30
    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl; // Output: 20
    
    return 0;
}


// Time and Space Complexity
// Time Complexity:
// push(): O(n), where n is the number of elements in the queue.
// pop(): O(1).
// top(): O(1).
// empty(): O(1).
// Space Complexity: O(n), where n is the number of elements in the stack.
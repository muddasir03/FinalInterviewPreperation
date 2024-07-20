#include <iostream>
#include <stack>
using namespace std;

class QueueUsingOneStack {
    stack<int> s;
    
public:
    void enqueue(int x) {
        s.push(x);
    }
    
    int dequeue() {
        if (s.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        
        int x = s.top();
        s.pop();
        
        if (s.empty()) {
            return x;
        } else {
            int item = dequeue();
            s.push(x);
            return item;
        }
    }
    
    bool empty() {
        return s.empty();
    }
};

int main() {
    QueueUsingOneStack queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    cout << "Dequeued element: " << queue.dequeue() << endl; // Output: 10
    cout << "Dequeued element: " << queue.dequeue() << endl; // Output: 20
    
    return 0;
}


// Time and Space Complexity
// Time Complexity:
// enqueue(): O(1).
// dequeue(): O(n), where n is the number of elements in the stack.
// empty(): O(1).
// Space Complexity: O(n), where n is the number of elements in the queue.
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 1. Create a queue of integers
    queue<int> q;

    // 2. Push elements to the queue
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "After push(10), push(20), push(30):" << endl;
    cout << "Front: " << q.front() << ", Back: " << q.back() << endl; // Should print 10, 30

    // 3. Pop an element from the queue (removes the front)
    q.pop(); // Removes 10
    cout << "After pop(), Front: " << q.front() << ", Back: " << q.back() << endl; // Should print 20, 30

    // 4. Push more elements
    q.push(40);
    cout << "After push(40), Front: " << q.front() << ", Back: " << q.back() << endl; // Should print 20, 40

    // 5. Check the size
    cout << "Queue size: " << q.size() << endl; // Should print 3

    // 6. Check if queue is empty
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    // 7. Pop all remaining elements
    cout << "Popping all elements:" << endl;
    while (!q.empty()) {
        cout << "Front: " << q.front() << endl;
        q.pop();
    }

    // 8. After clearing
    cout << "Queue empty after popping all? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

int main() {
    // 1. Creating a stack
    stack<int> s;

    // 2. Pushing elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "After pushing 10, 20, 30:" << endl;
    cout << "Top element: " << s.top() << endl; // Should print 30

    // 3. Popping element from the stack
    s.pop(); // Removes 30
    cout << "After pop(), top element: " << s.top() << endl; // Should print 20

    // 4. Pushing more elements
    s.push(40);
    cout << "After pushing 40, top element: " << s.top() << endl; // Should print 40

    // 5. Checking the size
    cout << "Stack size: " << s.size() << endl;

    // 6. Checking if stack is empty
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    // 7. Popping all elements to empty the stack
    while (!s.empty()) {
        cout << "Popping: " << s.top() << endl;
        s.pop();
    }
    cout << "Now stack is empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}

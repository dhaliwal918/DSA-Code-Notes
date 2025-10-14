#include <iostream>
#include <deque>
using namespace std;

int main() {
    // 1. Creating a deque and displaying its contents
    deque<int> dq = {10, 20, 30, 40, 50};
    cout << "Initial deque: ";
    for (int n : dq) cout << n << " ";
    cout << endl;

    // 2. push_front & push_back
    dq.push_front(5);   // Insert at the front
    dq.push_back(60);   // Insert at the back
    cout << "After push_front(5) & push_back(60): ";
    for (int n : dq) cout << n << " ";
    cout << endl;

    // 3. pop_front & pop_back
    dq.pop_front();   // Remove front element (5)
    dq.pop_back();    // Remove back element (60)
    cout << "After pop_front() & pop_back(): ";
    for (int n : dq) cout << n << " ";
    cout << endl;

    // 4. Insert at specific position (iterator)
    auto it = dq.begin() + 2;
    dq.insert(it, 25); // Insert 25 at position 2 (zero-indexed)
    cout << "After insert(25) at index 2: ";
    for (int n : dq) cout << n << " ";
    cout << endl;

    // 5. Erase by position
    dq.erase(dq.begin() + 3); // Remove element at index 3
    cout << "After erase at index 3: ";
    for (int n : dq) cout << n << " ";
    cout << endl;

    // 6. Access front, back, at, operator[]
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << ", dq[2]: " << dq[2] << endl;

    // 7. Size, empty, clear
    cout << "Deque size: " << dq.size() << endl;
    cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << endl;
    dq.clear();
    cout << "After clear(), deque size: " << dq.size() << endl;

    // 8. Assign values
    dq.assign(4, 99);
    cout << "After assign(4, 99): ";
    for (int n : dq) cout << n << " ";
    cout << endl;

    // 9. Swapping deques
    deque<int> dq2 = {1, 2, 3};
    dq.swap(dq2);
    cout << "After swap, dq: ";
    for (int n : dq) cout << n << " ";
    cout << " and dq2: ";
    for (int n : dq2) cout << n << " ";
    cout << endl;

    return 0;
}

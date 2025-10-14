#include <iostream>
#include <list>
using namespace std;

int main() {
    // 1. Creating a list
    list<int> l1; // empty list
    list<int> l2 = {10, 20, 30, 40}; // initialize with values

    // 2. Adding elements using push_back and push_front
    l1.push_back(1);      // Adds 1 to end
    l1.push_front(0);     // Adds 0 to front

    // 3. Displaying a list using iterator
    cout << "l1: ";
    for (list<int>::iterator it = l1.begin(); it != l1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "l2: ";
    for (auto n : l2) cout << n << " ";
    cout << endl;

    // 4. Removing elements using pop_back and pop_front
    l2.pop_back();    // removes 40
    l2.pop_front();   // removes 10

    // 5. Inserting at a position (iterator points to position to insert before)
    auto it = l1.begin();
    ++it; // Move to second position
    l1.insert(it, 5); // Insert 5 at position 2

    // 6. Erase elements (by value and by position/range)
    l2.remove(20); // Removes all occurrences of 20
    if (!l1.empty()) l1.erase(l1.begin()); // Remove first element

    // 7. Size and empty
    cout << "Size of l1: " << l1.size() << endl;
    cout << "Is l2 empty? " << (l2.empty() ? "Yes" : "No") << endl;

    // 8. Sorting a list
    l2.push_back(15);
    l2.push_back(5);
    l2.sort(); // sorts l2 in ascending order

    // 9. Reverse a list
    l2.reverse();

    // 10. Remove duplicates (only consecutive)
    l2.unique();

    // 11. Assign new values
    l1.assign(3, 8); // l1 = {8,8,8}

    // 12. Swapping lists
    l1.swap(l2);

    // 13. Clear a list
    l2.clear();

    // 14. Front and back element access
    if (!l1.empty())
        cout << "First: " << l1.front() << ", Last: " << l1.back() << endl;

    // Final output
    cout << "Final l1: ";
    for (auto n : l1) cout << n << " ";
    cout << endl;
    cout << "Final l2 (should be empty): ";
    for (auto n : l2) cout << n << " ";
    cout << endl;

    return 0;
}

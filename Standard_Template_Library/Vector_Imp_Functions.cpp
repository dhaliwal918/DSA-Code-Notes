#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1. Creating a vector and displaying its contents
    vector<int> v = {10, 20, 30, 40, 50};
    cout << "Initial vector: ";
    for (int n : v) cout << n << " ";
    cout << endl;

    // 2. Using push_back() to add elements at the end
    v.push_back(60);
    cout << "After push_back(60): ";
    for (int n : v) cout << n << " ";
    cout << endl;

    // 3. Using pop_back() to remove the last element
    v.pop_back();
    cout << "After pop_back(): ";
    for (int n : v) cout << n << " ";
    cout << endl;

    // 4. Inserting an element at a specific position
    v.insert(v.begin() + 2, 25); // Insert 25 at index 2
    cout << "After insert(25) at index 2: ";
    for (int n : v) cout << n << " ";
    cout << endl;

    // 5. Inserting multiple elements
    v.insert(v.end(), 3, 70); // Insert 70 three times at end
    cout << "After insert(70) three times at end: ";
    for (int n : v) cout << n << " ";
    cout << endl;

    // 6. Erasing an element at a specific position
    v.erase(v.begin() + 1); // Remove element at index 1
    cout << "After erase element at index 1: ";
    for (int n : v) cout << n << " ";
    cout << endl;

    // 7. Erasing a range of elements
    v.erase(v.begin() + 2, v.begin() + 4); // Remove elements at indices 2 and 3
    cout << "After erase elements at indices 2 and 3: ";
    for (int n : v) cout << n << " ";
    cout << endl;

    // 8. Clearing the vector
    v.clear();
    cout << "After clear(), vector size: " << v.size() << endl;

    // 9. Using empty() function
    if (v.empty()) {
        cout << "Vector is empty now." << endl;
    }

    // 10. Assigning new values to vector
    v.assign(5, 100); // Assign five 100s
    cout << "After assign(5, 100): ";
    for (int n : v) cout << n << " ";
    cout << endl;

    // 11. Access element with at()
    cout << "Element at index 2: " << v.at(2) << endl;

    // 12. Using front() and back()
    cout << "First element: " << v.front() << ", Last element: " << v.back() << endl;

    // 13. Swapping two vectors
    vector<int> v2 = {1, 2, 3};
    v.swap(v2);
    cout << "After swap, v: ";
    for (int n : v) cout << n << " ";
    cout << " and v2: ";
    for (int n : v2) cout << n << " ";
    cout << endl;

    return 0;
}

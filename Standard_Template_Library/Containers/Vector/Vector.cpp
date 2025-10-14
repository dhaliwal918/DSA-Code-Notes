#include <iostream>
#include <vector>
using namespace std;
int main(){
    // 1. Initializing a vector
    vector<int> v1; // empty vector of ints
    vector<int> v2(5); // vector of 5 ints, all default (0)
    vector<int> v3(5, 10); // vector of 5 ints, all initialized with value 10
    vector<int> v4 = {1, 2, 3, 4, 5}; // list initialization

    // 2. Inserting elements
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    // 3. Accessing elements
    cout << "v1[0]: " << v1[0] << endl;        // Using []
    cout << "v1.at(1): " << v1.at(1) << endl;  // Using at()

    // 4. Iterating over vector elements
    cout << "Contents of v4 (range based for): ";
    for (int num : v4) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Contents of v1 (using iterator): ";
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 5. Checking size and capacity
    cout << "Size of v1: " << v1.size() << endl;
    cout << "Capacity of v1: " << v1.capacity() << endl;
    cout << "Is v1 empty? " << (v1.empty() ? "Yes" : "No") << endl;

    // 6. Removing elements
    v1.pop_back(); // Removes last element
    cout << "After pop_back, size of v1: " << v1.size() << endl;

    // 7. Inserting and erasing at specific positions
    v1.insert(v1.begin() + 1, 99); // Insert 99 at position 1
    cout << "After insert at position 1: ";
    for (int n : v1) cout << n << " ";
    cout << endl;

    v1.erase(v1.begin()); // Erase first element
    cout << "After erase first element: ";
    for (int n : v1) cout << n << " ";
    cout << endl;

    // 8. Clearing a vector
    v1.clear();
    cout << "After clear, size of v1: " << v1.size() << endl;

    // 9. Two dimensional vector
    vector<vector<int>> matrix(3, vector<int>(4, 0)); // 3x4 matrix filled with 0s
    cout << "2D Vector Matrix: " << endl;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // 10. Swapping two vectors
    vector<int> a = {1, 2, 3}, b = {4, 5};
    a.swap(b);
    cout << "After swap, a: ";
    for (int n : a) cout << n << " ";
    cout << " and b: ";
    for (int n : b) cout << n << " ";
    cout << endl;
}
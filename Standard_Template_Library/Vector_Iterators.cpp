#include <iostream>
#include <vector>
using namespace std;
int main(){
    // Example 1: Using iterator to traverse a vector
    vector<int> v = {10, 20, 30, 40, 50};
    cout << "Vector elements (using iterator): ";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Example 2: Using const_iterator (cannot modify elements)
    cout << "Vector elements (using const_iterator): ";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Example 3: Using reverse_iterator to traverse in reverse
    cout << "Vector elements (using reverse_iterator): ";
    for (int i = v.size() - 1; i >= 0; --i) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Example 4: Using auto keyword with iterators
    cout << "Vector elements (using auto with iterator): ";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Example 5: Modifying elements using iterator
    for (int i = 0; i < v.size(); ++i) {
        v[i] += 5; // Add 5 to every element
    }
    cout << "Vector after modification (add 5 to each element): ";
    for (int n : v) {
        cout << n << " ";
    }
    cout << endl;

}
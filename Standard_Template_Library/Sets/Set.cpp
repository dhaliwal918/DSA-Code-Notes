#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // 1️⃣ Create and initialize a set (unique elements, sorted)
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(1); // Duplicate - will be ignored!
    s.insert(2);

    // 2️⃣ Print set (always sorted in ascending order)
    cout << "\nSet contents:\n";
    for (const auto& element : s)
        cout << element << " ";
    cout << endl;

    // 3️⃣ Another way to initialize
    set<string> s2 = {"apple", "banana", "cherry", "apple"}; // Duplicate ignored
    cout << "\nString set contents:\n";
    for (const auto& str : s2)
        cout << str << " ";
    cout << endl;

    // 4️⃣ find() - check if element exists
    auto it = s.find(3);
    if (it != s.end())
        cout << "\nElement 3 found in set" << endl;
    else
        cout << "\nElement 3 not found" << endl;

    // 5️⃣ count() - returns 1 if element exists, else 0
    cout << "Does element 5 exist? " << (s.count(5) ? "Yes" : "No") << endl;
    cout << "Does element 1 exist? " << (s.count(1) ? "Yes" : "No") << endl;

    // 6️⃣ insert() with return value
    auto result = s.insert(6);
    if (result.second)
        cout << "\nElement 6 inserted successfully" << endl;
    else
        cout << "\nElement 6 already exists" << endl;

    // Try to insert duplicate
    result = s.insert(1);
    if (result.second)
        cout << "Element 1 inserted successfully" << endl;
    else
        cout << "Element 1 already exists (duplicate ignored)" << endl;

    // 7️⃣ emplace() - constructs element in-place
    s.emplace(7);
    s.emplace(8);

    cout << "\nAfter emplace operations:\n";
    for (const auto& element : s)
        cout << element << " ";
    cout << endl;

    // 8️⃣ erase() - by value, iterator, or range
    s.erase(4); // erase by value
    it = s.find(2);
    if (it != s.end()) s.erase(it); // erase by iterator

    cout << "\nAfter erasures:\n";
    for (const auto& element : s)
        cout << element << " ";
    cout << endl;

    // 9️⃣ lower_bound() and upper_bound()
    s.insert({5, 6, 7, 8, 9, 10});
    auto lb = s.lower_bound(6); // first element >= 6
    auto ub = s.upper_bound(8); // first element > 8
    
    cout << "\nElements >= 6 and <= 8:\n";
    for (auto it = lb; it != ub; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 🔟 equal_range() - returns pair of iterators
    auto range = s.equal_range(7);
    cout << "\nElements equal to 7:\n";
    for (auto it = range.first; it != range.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 1️⃣1️⃣ size() and empty()
    cout << "\nSet size: " << s.size() << endl;
    cout << "Is set empty? " << (s.empty() ? "Yes" : "No") << endl;

    // 1️⃣2️⃣ Reverse iteration
    cout << "\nReverse iteration:\n";
    for (auto rit = s.rbegin(); rit != s.rend(); ++rit)
        cout << *rit << " ";
    cout << endl;

    // 1️⃣3️⃣ Custom comparator example (descending order)
    set<int, greater<int>> s_desc;
    s_desc.insert({3, 1, 4, 1, 2});
    
    cout << "\nSet with custom comparator (descending):\n";
    for (const auto& element : s_desc)
        cout << element << " ";
    cout << endl;

    // 1️⃣4️⃣ clear() - removes all elements
    s.clear();
    cout << "\nAfter clear(), set size: " << s.size() << endl;

    // 1️⃣5️⃣ swap() - exchange contents
    set<int> s1 = {1, 2, 3};
    set<int> s3 = {10, 20, 30};
    
    cout << "\nBefore swap:\nS1 size: " << s1.size() << ", S3 size: " << s3.size() << endl;
    s1.swap(s3);
    cout << "After swap:\nS1 size: " << s1.size() << ", S3 size: " << s3.size() << endl;

    // 1️⃣6️⃣ Set operations
    set<int> set1 = {1, 2, 3, 4, 5};
    set<int> set2 = {4, 5, 6, 7, 8};
    
    cout << "\nSet operations:\n";
    cout << "Set1: ";
    for (const auto& e : set1) cout << e << " ";
    cout << "\nSet2: ";
    for (const auto& e : set2) cout << e << " ";
    cout << endl;

    // 1️⃣7️⃣ includes() - check if one set is subset of another
    set<int> subset = {2, 3};
    if (includes(set1.begin(), set1.end(), subset.begin(), subset.end()))
        cout << "\n{2, 3} is a subset of Set1" << endl;

    // 1️⃣8️⃣ set_union, set_intersection, set_difference
    set<int> union_set, intersection_set, difference_set;
    
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), 
              inserter(union_set, union_set.begin()));
    
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), 
                     inserter(intersection_set, intersection_set.begin()));
    
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), 
                   inserter(difference_set, difference_set.begin()));

    cout << "\nUnion: ";
    for (const auto& e : union_set) cout << e << " ";
    cout << "\nIntersection: ";
    for (const auto& e : intersection_set) cout << e << " ";
    cout << "\nDifference (set1 - set2): ";
    for (const auto& e : difference_set) cout << e << " ";
    cout << endl;

    // 1️⃣9️⃣ Performance characteristics
    cout << "\nPerformance characteristics:\n";
    cout << "- Insert: O(log n)\n";
    cout << "- Find: O(log n)\n";
    cout << "- Erase: O(log n)\n";
    cout << "- Memory: Each element stored once\n";
    cout << "- Order: Always maintained (sorted)\n";
    cout << "- Duplicates: NOT allowed\n";

    // 2️⃣0️⃣ begin() and end() iterators
    cout << "\nFirst element: " << *set1.begin() << endl;
    cout << "Last element: " << *(--set1.end()) << endl;

    cout << "\nAll set functions demonstrated successfully ✅" << endl;
    return 0;
}

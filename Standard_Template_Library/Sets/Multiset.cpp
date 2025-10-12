#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // 1️⃣ Create and initialize a multiset (allows duplicate elements, sorted)
    multiset<int> ms;
    ms.insert(3);
    ms.insert(1);
    ms.insert(4);
    ms.insert(1); // Duplicate allowed!
    ms.insert(2);
    ms.insert(1); // Another duplicate!

    // 2️⃣ Print multiset (always sorted in ascending order)
    cout << "\nMultiset contents:\n";
    for (const auto& element : ms)
        cout << element << " ";
    cout << endl;

    // 3️⃣ Another way to initialize
    multiset<string> ms2 = {"apple", "banana", "cherry", "apple", "banana"}; // Duplicates allowed
    cout << "\nString multiset contents:\n";
    for (const auto& str : ms2)
        cout << str << " ";
    cout << endl;

    // 4️⃣ count() - returns number of occurrences of element
    cout << "\nNumber of occurrences:\n";
    cout << "Element 1 appears " << ms.count(1) << " times" << endl;
    cout << "Element 3 appears " << ms.count(3) << " times" << endl;
    cout << "Element 5 appears " << ms.count(5) << " times" << endl;

    // 5️⃣ find() - returns iterator to first occurrence
    auto it = ms.find(1);
    if (it != ms.end())
        cout << "\nFirst occurrence of 1 found" << endl;

    // 6️⃣ equal_range() - returns pair of iterators for all occurrences
    auto range = ms.equal_range(1);
    cout << "\nAll occurrences of 1:\n";
    for (auto it = range.first; it != range.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 7️⃣ lower_bound() and upper_bound()
    auto lb = ms.lower_bound(2); // first element >= 2
    auto ub = ms.upper_bound(2); // first element > 2
    
    cout << "\nElements >= 2 and <= 2:\n";
    for (auto it = lb; it != ub; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 8️⃣ insert() with return value
    auto result = ms.insert(6);
    cout << "\nElement 6 inserted at position: " << *result << endl;

    // 9️⃣ emplace() - constructs element in-place
    ms.emplace(7);
    ms.emplace(8);

    cout << "\nAfter emplace operations:\n";
    for (const auto& element : ms)
        cout << element << " ";
    cout << endl;

    // 🔟 erase() - by value (removes ALL occurrences)
    cout << "\nBefore erasing all 1s, size: " << ms.size() << endl;
    ms.erase(1); // Removes ALL occurrences of 1
    cout << "After erasing all 1s, size: " << ms.size() << endl;

    // 1️⃣1️⃣ erase() - by iterator (removes only one occurrence)
    it = ms.find(2);
    if (it != ms.end()) {
        cout << "\nBefore erasing iterator, size: " << ms.size() << endl;
        ms.erase(it); // Removes only this specific occurrence
        cout << "After erasing iterator, size: " << ms.size() << endl;
    }

    // 1️⃣2️⃣ erase() - by range
    ms.insert({5, 5, 5, 6, 6, 7, 7, 7});
    auto range2 = ms.equal_range(5);
    ms.erase(range2.first, range2.second); // Remove all 5s

    cout << "\nAfter erasing range (all 5s):\n";
    for (const auto& element : ms)
        cout << element << " ";
    cout << endl;

    // 1️⃣3️⃣ size() and empty()
    cout << "\nMultiset size: " << ms.size() << endl;
    cout << "Is multiset empty? " << (ms.empty() ? "Yes" : "No") << endl;

    // 1️⃣4️⃣ Reverse iteration
    cout << "\nReverse iteration:\n";
    for (auto rit = ms.rbegin(); rit != ms.rend(); ++rit)
        cout << *rit << " ";
    cout << endl;

    // 1️⃣5️⃣ Custom comparator example (descending order)
    multiset<int, greater<int>> ms_desc;
    ms_desc.insert({3, 1, 4, 1, 2, 1});
    
    cout << "\nMultiset with custom comparator (descending):\n";
    for (const auto& element : ms_desc)
        cout << element << " ";
    cout << endl;

    // 1️⃣6️⃣ clear() - removes all elements
    ms.clear();
    cout << "\nAfter clear(), multiset size: " << ms.size() << endl;

    // 1️⃣7️⃣ swap() - exchange contents
    multiset<int> ms1 = {1, 2, 2, 3};
    multiset<int> ms3 = {10, 20, 20, 30};
    
    cout << "\nBefore swap:\nMS1 size: " << ms1.size() << ", MS3 size: " << ms3.size() << endl;
    ms1.swap(ms3);
    cout << "After swap:\nMS1 size: " << ms1.size() << ", MS3 size: " << ms3.size() << endl;

    // 1️⃣8️⃣ Multiset operations
    multiset<int> multiset1 = {1, 2, 2, 3, 4, 4, 5};
    multiset<int> multiset2 = {4, 4, 5, 6, 7, 7, 8};
    
    cout << "\nMultiset operations:\n";
    cout << "Multiset1: ";
    for (const auto& e : multiset1) cout << e << " ";
    cout << "\nMultiset2: ";
    for (const auto& e : multiset2) cout << e << " ";
    cout << endl;

    // 1️⃣9️⃣ includes() - check if one multiset is subset of another
    multiset<int> subset = {2, 2};
    if (includes(multiset1.begin(), multiset1.end(), subset.begin(), subset.end()))
        cout << "\n{2, 2} is a subset of Multiset1" << endl;

    // 2️⃣0️⃣ set_union, set_intersection, set_difference
    multiset<int> union_ms, intersection_ms, difference_ms;
    
    set_union(multiset1.begin(), multiset1.end(), multiset2.begin(), multiset2.end(), 
              inserter(union_ms, union_ms.begin()));
    
    set_intersection(multiset1.begin(), multiset1.end(), multiset2.begin(), multiset2.end(), 
                     inserter(intersection_ms, intersection_ms.begin()));
    
    set_difference(multiset1.begin(), multiset1.end(), multiset2.begin(), multiset2.end(), 
                   inserter(difference_ms, difference_ms.begin()));

    cout << "\nUnion: ";
    for (const auto& e : union_ms) cout << e << " ";
    cout << "\nIntersection: ";
    for (const auto& e : intersection_ms) cout << e << " ";
    cout << "\nDifference (multiset1 - multiset2): ";
    for (const auto& e : difference_ms) cout << e << " ";
    cout << endl;

    // 2️⃣1️⃣ Performance characteristics
    cout << "\nPerformance characteristics:\n";
    cout << "- Insert: O(log n)\n";
    cout << "- Find: O(log n)\n";
    cout << "- Erase: O(log n) for single element, O(log n + count) for all occurrences\n";
    cout << "- Memory: Each element stored separately (duplicates allowed)\n";
    cout << "- Order: Always maintained (sorted)\n";
    cout << "- Duplicates: ALLOWED (unlike set)\n";

    // 2️⃣2️⃣ begin() and end() iterators
    multiset<int> demo = {1, 1, 2, 3, 3, 3};
    cout << "\nFirst element: " << *demo.begin() << endl;
    cout << "Last element: " << *(--demo.end()) << endl;

    // 2️⃣3️⃣ key_comp() and value_comp()
    auto keyComp = demo.key_comp();
    cout << "\nkey_comp example:\n";
    int highest = *demo.rbegin();
    for (auto it = demo.begin(); keyComp(*it, highest); ++it)
        cout << *it << " ";
    cout << highest << endl;

    cout << "\nAll multiset functions demonstrated successfully ✅" << endl;
    return 0;
}

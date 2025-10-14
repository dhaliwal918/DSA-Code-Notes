#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // 1️⃣ Create and initialize a multimap (allows duplicate keys)
    multimap<int, string> mm;
    mm.insert({1, "Apple"});
    mm.insert({2, "Banana"});
    mm.insert({1, "Avocado"});  // Duplicate key allowed!
    mm.insert({3, "Cherry"});
    mm.insert({2, "Blueberry"}); // Another duplicate key!

    // 2️⃣ Print multimap (always sorted by key)
    cout << "\nMultimap contents:\n";
    for (const auto& pair : mm)
        cout << pair.first << " -> " << pair.second << endl;

    // 3️⃣ count() - returns number of elements with given key
    cout << "\nNumber of elements with key 1: " << mm.count(1) << endl;
    cout << "Number of elements with key 2: " << mm.count(2) << endl;
    cout << "Number of elements with key 5: " << mm.count(5) << endl;

    // 4️⃣ find() - returns iterator to first element with key
    auto it = mm.find(2);
    if (it != mm.end()) {
        cout << "\nFirst element with key 2: " << it->second << endl;
    }

    // 5️⃣ equal_range() - returns pair of iterators for all elements with key
    auto range = mm.equal_range(1);
    cout << "\nAll elements with key 1:\n";
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << " -> " << it->second << endl;
    }

    // 6️⃣ lower_bound() and upper_bound()
    auto lb = mm.lower_bound(2); // first element with key >= 2
    auto ub = mm.upper_bound(2); // first element with key > 2
    cout << "\nElements with key >= 2 and < 3:\n";
    for (auto it = lb; it != ub; ++it) {
        cout << it->first << " -> " << it->second << endl;
    }

    // 7️⃣ erase() - by key (removes ALL elements with that key)
    cout << "\nBefore erasing key 1, size: " << mm.size() << endl;
    mm.erase(1); // Removes ALL elements with key 1
    cout << "After erasing key 1, size: " << mm.size() << endl;

    // 8️⃣ erase() - by iterator (removes only one element)
    it = mm.find(2);
    if (it != mm.end()) {
        cout << "\nBefore erasing iterator, size: " << mm.size() << endl;
        mm.erase(it); // Removes only this specific element
        cout << "After erasing iterator, size: " << mm.size() << endl;
    }

    // 9️⃣ insert() with hint (for better performance)
    mm.insert({4, "Date"});
    auto hint = mm.find(4);
    mm.insert(hint, {5, "Elderberry"}); // Hint for insertion position

    // 🔟 emplace() - constructs element in-place
    mm.emplace(6, "Fig");
    mm.emplace(7, "Grape");

    cout << "\nFinal multimap contents:\n";
    for (const auto& [k, v] : mm)
        cout << k << " -> " << v << endl;

    // 1️⃣1️⃣ size() and empty()
    cout << "\nMultimap size: " << mm.size() << endl;
    cout << "Is multimap empty? " << (mm.empty() ? "Yes" : "No") << endl;

    // 1️⃣2️⃣ Reverse iteration
    cout << "\nReverse iteration:\n";
    for (auto rit = mm.rbegin(); rit != mm.rend(); ++rit)
        cout << rit->first << " -> " << rit->second << endl;

    // 1️⃣3️⃣ clear() - removes all elements
    mm.clear();
    cout << "\nAfter clear(), multimap size: " << mm.size() << endl;

    // 1️⃣4️⃣ Custom comparator example
    multimap<int, string, greater<int>> mm_desc; // Descending order
    mm_desc.insert({3, "Three"});
    mm_desc.insert({1, "One"});
    mm_desc.insert({2, "Two"});
    
    cout << "\nMultimap with custom comparator (descending):\n";
    for (const auto& pair : mm_desc)
        cout << pair.first << " -> " << pair.second << endl;

    // 1️⃣5️⃣ swap() - exchange contents
    multimap<int, string> mm1 = {{1, "A"}, {2, "B"}};
    multimap<int, string> mm2 = {{3, "C"}, {4, "D"}};
    
    cout << "\nBefore swap:\nMM1 size: " << mm1.size() << ", MM2 size: " << mm2.size() << endl;
    mm1.swap(mm2);
    cout << "After swap:\nMM1 size: " << mm1.size() << ", MM2 size: " << mm2.size() << endl;

    cout << "\nAll multimap functions demonstrated successfully ✅" << endl;
    return 0;
}

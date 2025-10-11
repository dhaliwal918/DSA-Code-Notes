#include <iostream>
#include <map>
using namespace std;

int main() {
    // 1️⃣ Create and initialize a map (key: int, value: string)
    map<int, string> m;
    m[1] = "One";
    m[2] = "Two";
    m[3] = "Three";

    // 2️⃣ Another way to insert elements
    m.insert({4, "Four"});
    m.insert(make_pair(5, "Five"));

    // 3️⃣ Emplace (constructs element in-place, faster than insert)
    m.emplace(6, "Six");
    m.emplace(7, "Seven");

    // 4️⃣ Print map (always sorted by key in ascending order)
    cout << "\nMap contents:\n";
    for (const auto& x : m)
        cout << x.first << " -> " << x.second << endl;

    // 5️⃣ find() - check if a key exists
    int key = 2;
    auto it = m.find(key);
    if (it != m.end())
        cout << "\nKey " << key << " found with value: " << it->second << endl;
    else
        cout << "\nKey " << key << " not found" << endl;

    // 6️⃣ count() - returns 1 if key exists, else 0
    cout << "Does key 5 exist? " << (m.count(5) ? "Yes" : "No") << endl;

    // 7️⃣ erase() - by key or iterator
    m.erase(4); // erase by key
    it = m.find(3);
    if (it != m.end()) m.erase(it); // erase by iterator

    // 8️⃣ size() and empty()
    cout << "\nMap size after erasures: " << m.size() << endl;
    cout << "Is map empty? " << (m.empty() ? "Yes" : "No") << endl;

    // 9️⃣ Access and modify elements
    m[10] = "Ten";        // insert new element
    m[2] = "TWO updated"; // update existing element

    cout << "\nAfter updates:\n";
    for (const auto& [k, v] : m)
        cout << k << " -> " << v << endl;

    // 🔟 at() - safe access (throws exception if key not found)
    cout << "\nAccess using at(): key 1 -> " << m.at(1) << endl;

    // 1️⃣1️⃣ lower_bound() and upper_bound()
    m[8] = "Eight";
    m[9] = "Nine";
    auto lb = m.lower_bound(8); // first element with key >= 8
    auto ub = m.upper_bound(8); // first element with key > 8
    if (lb != m.end())
        cout << "\nlower_bound(8): " << lb->first << " -> " << lb->second << endl;
    if (ub != m.end())
        cout << "upper_bound(8): " << ub->first << " -> " << ub->second << endl;

    // 1️⃣2️⃣ Reverse iteration
    cout << "\nReverse iteration:\n";
    for (auto rit = m.rbegin(); rit != m.rend(); ++rit)
        cout << rit->first << " -> " << rit->second << endl;

    // 1️⃣3️⃣ clear() - removes all elements
    m.clear();
    cout << "\nAfter clear(), map size: " << m.size() << endl;

    // 1️⃣4️⃣ swap() - exchange contents with another map
    map<int, string> m1 = {{1, "A"}, {2, "B"}};
    map<int, string> m2 = {{10, "X"}, {20, "Y"}};
    cout << "\nBefore swap:\nMap1:\n";
    for (auto& p : m1) cout << p.first << " -> " << p.second << endl;
    cout << "Map2:\n";
    for (auto& p : m2) cout << p.first << " -> " << p.second << endl;

    m1.swap(m2);

    cout << "\nAfter swap:\nMap1:\n";
    for (auto& p : m1) cout << p.first << " -> " << p.second << endl;
    cout << "Map2:\n";
    for (auto& p : m2) cout << p.first << " -> " << p.second << endl;

    // 1️⃣5️⃣ key_comp() and value_comp()
    // Used to compare keys or pairs
    auto keyComp = m1.key_comp();
    cout << "\nkey_comp example:\n";
    int highest = m1.rbegin()->first;
    for (auto it = m1.begin(); keyComp(it->first, highest); ++it)
        cout << it->first << " -> " << it->second << endl;

    cout << "\nAll map functions demonstrated successfully ✅" << endl;
}

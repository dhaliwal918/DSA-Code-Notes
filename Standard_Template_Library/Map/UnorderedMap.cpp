#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // 1️⃣ Create and initialize an unordered_map (hash table)
    unordered_map<int, string> um;
    um[1] = "One";
    um[2] = "Two";
    um[3] = "Three";

    // 2️⃣ Another way to insert elements
    um.insert({4, "Four"});
    um.insert(make_pair(5, "Five"));

    // 3️⃣ emplace() - constructs element in-place (faster than insert)
    um.emplace(6, "Six");
    um.emplace(7, "Seven");

    // 4️⃣ Print unordered_map (order is NOT guaranteed!)
    cout << "\nUnordered_map contents:\n";
    for (const auto& pair : um)
        cout << pair.first << " -> " << pair.second << endl;

    // 5️⃣ find() - check if a key exists (O(1) average)
    int key = 2;
    auto it = um.find(key);
    if (it != um.end())
        cout << "\nKey " << key << " found with value: " << it->second << endl;
    else
        cout << "\nKey " << key << " not found" << endl;

    // 6️⃣ count() - returns 1 if key exists, else 0
    cout << "Does key 5 exist? " << (um.count(5) ? "Yes" : "No") << endl;
    cout << "Does key 10 exist? " << (um.count(10) ? "Yes" : "No") << endl;

    // 7️⃣ erase() - by key or iterator
    um.erase(4); // erase by key
    it = um.find(3);
    if (it != um.end()) um.erase(it); // erase by iterator

    cout << "\nAfter erasures:\n";
    for (const auto& [k, v] : um)
        cout << k << " -> " << v << endl;

    // 8️⃣ Access and modify elements
    um[10] = "Ten";        // insert new element
    um[2] = "TWO updated"; // update existing element

    // 9️⃣ at() - safe access (throws exception if key not found)
    cout << "\nAccess using at(): key 1 -> " << um.at(1) << endl;
    // cout << um.at(99); // This would throw an exception!

    // 🔟 bucket_count() and bucket_size() - hash table info
    cout << "\nHash table info:\n";
    cout << "Number of buckets: " << um.bucket_count() << endl;
    cout << "Load factor: " << um.load_factor() << endl;
    cout << "Max load factor: " << um.max_load_factor() << endl;

    // 1️⃣1️⃣ bucket() - which bucket contains the key
    cout << "\nKey 2 is in bucket: " << um.bucket(2) << endl;
    cout << "Key 5 is in bucket: " << um.bucket(5) << endl;

    // 1️⃣2️⃣ reserve() - pre-allocate buckets for better performance
    unordered_map<int, string> um2;
    um2.reserve(100); // Reserve space for 100 elements
    cout << "\nReserved buckets: " << um2.bucket_count() << endl;

    // 1️⃣3️⃣ rehash() - change number of buckets
    um2.rehash(50);
    cout << "After rehash, buckets: " << um2.bucket_count() << endl;

    // 1️⃣4️⃣ Custom hash function example
    unordered_map<string, int> um_string;
    um_string["apple"] = 1;
    um_string["banana"] = 2;
    um_string["cherry"] = 3;

    cout << "\nString unordered_map:\n";
    for (const auto& pair : um_string)
        cout << pair.first << " -> " << pair.second << endl;

    // 1️⃣5️⃣ size() and empty()
    cout << "\nUnordered_map size: " << um.size() << endl;
    cout << "Is unordered_map empty? " << (um.empty() ? "Yes" : "No") << endl;

    // 1️⃣6️⃣ clear() - removes all elements
    um.clear();
    cout << "\nAfter clear(), unordered_map size: " << um.size() << endl;

    // 1️⃣7️⃣ swap() - exchange contents
    unordered_map<int, string> um1 = {{1, "A"}, {2, "B"}};
    unordered_map<int, string> um3 = {{10, "X"}, {20, "Y"}};
    
    cout << "\nBefore swap:\nUM1 size: " << um1.size() << ", UM3 size: " << um3.size() << endl;
    um1.swap(um3);
    cout << "After swap:\nUM1 size: " << um1.size() << ", UM3 size: " << um3.size() << endl;

    // 1️⃣8️⃣ Performance comparison note
    cout << "\nPerformance characteristics:\n";
    cout << "- Average case: O(1) for insert, find, erase\n";
    cout << "- Worst case: O(n) for insert, find, erase\n";
    cout << "- Memory: More than map due to hash table overhead\n";
    cout << "- Order: NOT maintained (unlike map)\n";

    // 1️⃣9️⃣ Iterate through buckets
    unordered_map<int, string> um_bucket = {{1, "One"}, {2, "Two"}, {3, "Three"}};
    cout << "\nIterating through buckets:\n";
    for (size_t i = 0; i < um_bucket.bucket_count(); ++i) {
        if (um_bucket.bucket_size(i) > 0) {
            cout << "Bucket " << i << ": ";
            for (auto it = um_bucket.begin(i); it != um_bucket.end(i); ++it) {
                cout << it->first << "->" << it->second << " ";
            }
            cout << endl;
        }
    }

    cout << "\nAll unordered_map functions demonstrated successfully ✅" << endl;
    return 0;
}

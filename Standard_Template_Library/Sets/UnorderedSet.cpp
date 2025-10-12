#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // 1️⃣ Create and initialize an unordered_set (hash table, unique elements)
    unordered_set<int> us;
    us.insert(3);
    us.insert(1);
    us.insert(4);
    us.insert(1); // Duplicate - will be ignored!
    us.insert(2);

    // 2️⃣ Print unordered_set (order is NOT guaranteed!)
    cout << "\nUnordered_set contents:\n";
    for (const auto& element : us)
        cout << element << " ";
    cout << endl;

    // 3️⃣ Another way to initialize
    unordered_set<string> us2 = {"apple", "banana", "cherry", "apple"}; // Duplicate ignored
    cout << "\nString unordered_set contents:\n";
    for (const auto& str : us2)
        cout << str << " ";
    cout << endl;

    // 4️⃣ find() - check if element exists (O(1) average)
    auto it = us.find(3);
    if (it != us.end())
        cout << "\nElement 3 found in unordered_set" << endl;
    else
        cout << "\nElement 3 not found" << endl;

    // 5️⃣ count() - returns 1 if element exists, else 0
    cout << "Does element 5 exist? " << (us.count(5) ? "Yes" : "No") << endl;
    cout << "Does element 1 exist? " << (us.count(1) ? "Yes" : "No") << endl;

    // 6️⃣ insert() with return value
    auto result = us.insert(6);
    if (result.second)
        cout << "\nElement 6 inserted successfully" << endl;
    else
        cout << "\nElement 6 already exists" << endl;

    // Try to insert duplicate
    result = us.insert(1);
    if (result.second)
        cout << "Element 1 inserted successfully" << endl;
    else
        cout << "Element 1 already exists (duplicate ignored)" << endl;

    // 7️⃣ emplace() - constructs element in-place
    us.emplace(7);
    us.emplace(8);

    cout << "\nAfter emplace operations:\n";
    for (const auto& element : us)
        cout << element << " ";
    cout << endl;

    // 8️⃣ erase() - by value or iterator
    us.erase(4); // erase by value
    it = us.find(2);
    if (it != us.end()) us.erase(it); // erase by iterator

    cout << "\nAfter erasures:\n";
    for (const auto& element : us)
        cout << element << " ";
    cout << endl;

    // 9️⃣ bucket_count() and bucket_size() - hash table info
    cout << "\nHash table info:\n";
    cout << "Number of buckets: " << us.bucket_count() << endl;
    cout << "Load factor: " << us.load_factor() << endl;
    cout << "Max load factor: " << us.max_load_factor() << endl;

    // 🔟 bucket() - which bucket contains the element
    cout << "\nElement 2 is in bucket: " << us.bucket(2) << endl;
    cout << "Element 5 is in bucket: " << us.bucket(5) << endl;

    // 1️⃣1️⃣ reserve() - pre-allocate buckets for better performance
    unordered_set<int> us3;
    us3.reserve(100); // Reserve space for 100 elements
    cout << "\nReserved buckets: " << us3.bucket_count() << endl;

    // 1️⃣2️⃣ rehash() - change number of buckets
    us3.rehash(50);
    cout << "After rehash, buckets: " << us3.bucket_count() << endl;

    // 1️⃣3️⃣ Custom hash function example
    unordered_set<string> us_string;
    us_string.insert("apple");
    us_string.insert("banana");
    us_string.insert("cherry");

    cout << "\nString unordered_set:\n";
    for (const auto& str : us_string)
        cout << str << " ";
    cout << endl;

    // 1️⃣4️⃣ size() and empty()
    cout << "\nUnordered_set size: " << us.size() << endl;
    cout << "Is unordered_set empty? " << (us.empty() ? "Yes" : "No") << endl;

    // 1️⃣5️⃣ clear() - removes all elements
    us.clear();
    cout << "\nAfter clear(), unordered_set size: " << us.size() << endl;

    // 1️⃣6️⃣ swap() - exchange contents
    unordered_set<int> us1 = {1, 2, 3};
    unordered_set<int> us4 = {10, 20, 30};
    
    cout << "\nBefore swap:\nUS1 size: " << us1.size() << ", US4 size: " << us4.size() << endl;
    us1.swap(us4);
    cout << "After swap:\nUS1 size: " << us1.size() << ", US4 size: " << us4.size() << endl;

    // 1️⃣7️⃣ Performance comparison note
    cout << "\nPerformance characteristics:\n";
    cout << "- Average case: O(1) for insert, find, erase\n";
    cout << "- Worst case: O(n) for insert, find, erase\n";
    cout << "- Memory: More than set due to hash table overhead\n";
    cout << "- Order: NOT maintained (unlike set)\n";
    cout << "- Duplicates: NOT allowed (like set)\n";

    // 1️⃣8️⃣ Iterate through buckets
    unordered_set<int> us_bucket = {1, 2, 3, 4, 5};
    cout << "\nIterating through buckets:\n";
    for (size_t i = 0; i < us_bucket.bucket_count(); ++i) {
        if (us_bucket.bucket_size(i) > 0) {
            cout << "Bucket " << i << ": ";
            for (auto it = us_bucket.begin(i); it != us_bucket.end(i); ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    // 1️⃣9️⃣ Set operations with unordered_set
    unordered_set<int> set1 = {1, 2, 3, 4, 5};
    unordered_set<int> set2 = {4, 5, 6, 7, 8};
    
    cout << "\nUnordered_set operations:\n";
    cout << "Set1: ";
    for (const auto& e : set1) cout << e << " ";
    cout << "\nSet2: ";
    for (const auto& e : set2) cout << e << " ";
    cout << endl;

    // 2️⃣0️⃣ includes() - check if one set is subset of another
    unordered_set<int> subset = {2, 3};
    if (includes(set1.begin(), set1.end(), subset.begin(), subset.end()))
        cout << "\n{2, 3} is a subset of Set1" << endl;

    // 2️⃣1️⃣ set_union, set_intersection, set_difference
    unordered_set<int> union_set, intersection_set, difference_set;
    
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

    // 2️⃣2️⃣ begin() and end() iterators
    cout << "\nFirst element: " << *set1.begin() << endl;
    // Note: unordered_set doesn't support -- operator, so we can't get "last" element
    cout << "Note: unordered_set doesn't have a concept of 'last' element due to hash table structure" << endl;

    // 2️⃣3️⃣ Custom hash function example (simple)
    struct CustomHash {
        size_t operator()(const int& x) const {
            return x % 10; // Simple hash function
        }
    };
    
    unordered_set<int, CustomHash> custom_us;
    custom_us.insert({1, 11, 21, 31}); // All will hash to bucket 1
    
    cout << "\nCustom hash unordered_set:\n";
    for (const auto& e : custom_us) cout << e << " ";
    cout << endl;

    // 2️⃣4️⃣ Comparison with regular set
    cout << "\nComparison with regular set:\n";
    cout << "- unordered_set: O(1) average, O(n) worst case\n";
    cout << "- set: O(log n) guaranteed\n";
    cout << "- unordered_set: No ordering, uses hash table\n";
    cout << "- set: Always sorted, uses balanced tree\n";
    cout << "- unordered_set: Faster for frequent lookups\n";
    cout << "- set: Better for range queries and ordered iteration\n";

    cout << "\nAll unordered_set functions demonstrated successfully ✅" << endl;
    return 0;
}

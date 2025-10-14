#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <deque>
#include <list>
using namespace std;

int main() {
    cout << "=== BASIC SORTING WITH DEFAULT COMPARATORS ===" << endl;

    // 1️⃣ VECTOR SORTING (Ascending - Default)
    vector<int> vec = {64, 34, 25, 12, 22, 11, 90};
    cout << "\n1️⃣ Vector Sorting (Ascending - Default):" << endl;
    cout << "Before: ";
    for (int x : vec) cout << x << " ";
    cout << endl;
    
    sort(vec.begin(), vec.end()); // Default: ascending order
    cout << "After:  ";
    for (int x : vec) cout << x << " ";
    cout << endl;

    // 2️⃣ VECTOR SORTING (Descending - Using greater<>)
    vector<int> vec2 = {64, 34, 25, 12, 22, 11, 90};
    cout << "\n2️⃣ Vector Sorting (Descending - greater<>):" << endl;
    cout << "Before: ";
    for (int x : vec2) cout << x << " ";
    cout << endl;
    
    sort(vec2.begin(), vec2.end(), greater<int>());
    cout << "After:  ";
    for (int x : vec2) cout << x << " ";
    cout << endl;

    // 3️⃣ STRING SORTING (Lexicographical - Default)
    vector<string> words = {"banana", "apple", "cherry", "date", "elderberry"};
    cout << "\n3️⃣ String Sorting (Lexicographical - Default):" << endl;
    cout << "Before: ";
    for (const string& w : words) cout << w << " ";
    cout << endl;
    
    sort(words.begin(), words.end());
    cout << "After:  ";
    for (const string& w : words) cout << w << " ";
    cout << endl;

    // 4️⃣ STRING SORTING (Reverse Lexicographical)
    vector<string> words2 = {"banana", "apple", "cherry", "date", "elderberry"};
    cout << "\n4️⃣ String Sorting (Reverse Lexicographical):" << endl;
    cout << "Before: ";
    for (const string& w : words2) cout << w << " ";
    cout << endl;
    
    sort(words2.begin(), words2.end(), greater<string>());
    cout << "After:  ";
    for (const string& w : words2) cout << w << " ";
    cout << endl;

    // 5️⃣ ARRAY SORTING
    array<int, 7> arr = {64, 34, 25, 12, 22, 11, 90};
    cout << "\n5️⃣ Array Sorting:" << endl;
    cout << "Before: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    sort(arr.begin(), arr.end());
    cout << "After:  ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // 6️⃣ DEQUE SORTING
    deque<int> dq = {64, 34, 25, 12, 22, 11, 90};
    cout << "\n6️⃣ Deque Sorting:" << endl;
    cout << "Before: ";
    for (int x : dq) cout << x << " ";
    cout << endl;
    
    sort(dq.begin(), dq.end());
    cout << "After:  ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    // 7️⃣ PARTIAL SORTING (First 3 elements)
    vector<int> partial_vec = {64, 34, 25, 12, 22, 11, 90};
    cout << "\n7️⃣ Partial Sorting (First 3 elements):" << endl;
    cout << "Before: ";
    for (int x : partial_vec) cout << x << " ";
    cout << endl;
    
    partial_sort(partial_vec.begin(), partial_vec.begin() + 3, partial_vec.end());
    cout << "After:  ";
    for (int x : partial_vec) cout << x << " ";
    cout << endl;

    // 8️⃣ NTH ELEMENT (Find nth smallest element)
    vector<int> nth_vec = {64, 34, 25, 12, 22, 11, 90};
    cout << "\n8️⃣ Nth Element (Find 3rd smallest):" << endl;
    cout << "Before: ";
    for (int x : nth_vec) cout << x << " ";
    cout << endl;
    
    nth_element(nth_vec.begin(), nth_vec.begin() + 2, nth_vec.end());
    cout << "After:  ";
    for (int x : nth_vec) cout << x << " ";
    cout << endl;
    cout << "3rd smallest element: " << nth_vec[2] << endl;

    // 9️⃣ HEAP OPERATIONS
    vector<int> heap_vec = {64, 34, 25, 12, 22, 11, 90};
    cout << "\n9️⃣ Heap Operations:" << endl;
    cout << "Before: ";
    for (int x : heap_vec) cout << x << " ";
    cout << endl;
    
    make_heap(heap_vec.begin(), heap_vec.end());
    cout << "Max heap: ";
    for (int x : heap_vec) cout << x << " ";
    cout << endl;
    
    sort_heap(heap_vec.begin(), heap_vec.end());
    cout << "Sorted:   ";
    for (int x : heap_vec) cout << x << " ";
    cout << endl;

    // 🔟 STABLE SORT (Maintains relative order of equal elements)
    vector<pair<int, string>> pairs = {{3, "third"}, {1, "first"}, {2, "second"}, {1, "first_dup"}};
    cout << "\n🔟 Stable Sort (Maintains relative order):" << endl;
    cout << "Before: ";
    for (const auto& p : pairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;
    
    stable_sort(pairs.begin(), pairs.end());
    cout << "After:  ";
    for (const auto& p : pairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;

    // 1️⃣1️⃣ IS SORTED CHECK
    vector<int> sorted_check = {1, 2, 3, 4, 5};
    vector<int> unsorted_check = {1, 3, 2, 4, 5};
    
    cout << "\n1️⃣1️⃣ Is Sorted Check:" << endl;
    cout << "{1,2,3,4,5} is sorted: " << (is_sorted(sorted_check.begin(), sorted_check.end()) ? "Yes" : "No") << endl;
    cout << "{1,3,2,4,5} is sorted: " << (is_sorted(unsorted_check.begin(), unsorted_check.end()) ? "Yes" : "No") << endl;

    // 1️⃣2️⃣ MERGE SORTED RANGES
    vector<int> merge1 = {1, 3, 5, 7};
    vector<int> merge2 = {2, 4, 6, 8};
    vector<int> merged(8);
    
    cout << "\n1️⃣2️⃣ Merge Sorted Ranges:" << endl;
    cout << "Array 1: ";
    for (int x : merge1) cout << x << " ";
    cout << "\nArray 2: ";
    for (int x : merge2) cout << x << " ";
    cout << endl;
    
    merge(merge1.begin(), merge1.end(), merge2.begin(), merge2.end(), merged.begin());
    cout << "Merged:  ";
    for (int x : merged) cout << x << " ";
    cout << endl;

    // 1️⃣3️⃣ INPLACE MERGE
    vector<int> inplace_vec = {1, 3, 5, 7, 2, 4, 6, 8};
    cout << "\n1️⃣3️⃣ Inplace Merge:" << endl;
    cout << "Before: ";
    for (int x : inplace_vec) cout << x << " ";
    cout << endl;
    
    inplace_merge(inplace_vec.begin(), inplace_vec.begin() + 4, inplace_vec.end());
    cout << "After:  ";
    for (int x : inplace_vec) cout << x << " ";
    cout << endl;

    // 1️⃣4️⃣ PERFORMANCE COMPARISON
    cout << "\n1️⃣4️⃣ Performance Characteristics:" << endl;
    cout << "- sort(): O(n log n) average, O(n²) worst case" << endl;
    cout << "- stable_sort(): O(n log n) average, O(n log² n) worst case" << endl;
    cout << "- partial_sort(): O(n log k) where k is number of elements to sort" << endl;
    cout << "- nth_element(): O(n) average, O(n²) worst case" << endl;
    cout << "- make_heap(): O(n)" << endl;
    cout << "- sort_heap(): O(n log n)" << endl;

    cout << "\n✅ All basic sorting operations demonstrated successfully!" << endl;
    return 0;
}

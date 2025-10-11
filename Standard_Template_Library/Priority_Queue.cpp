#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // 1. Default max-heap (largest element at top, like priority_queue<int>)
    priority_queue<int> pq;

    // 2. Push elements into the max-heap
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(30);

    cout << "Max-heap priority_queue (default):" << endl;
    cout << "Top element: " << pq.top() << endl; // 50

    // 3. Pop an element
    pq.pop(); // Removes 50
    cout << "After pop() - New top: " << pq.top() << endl; // 30

    // 4. Size and empty
    cout << "Size: " << pq.size() << endl; // 3
    cout << "Is empty? " << (pq.empty() ? "Yes" : "No") << endl;

    // 5. Print and empty the priority queue
    cout << "Elements in descending order (pop all): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl << endl;

    // 6. Min-heap using vector<int> and greater<int>
    priority_queue<int, vector<int>, greater<int>> min_pq;

    // Push elements into the min-heap
    min_pq.push(10);
    min_pq.push(50);
    min_pq.push(20);
    min_pq.push(30);

    cout << "Min-heap priority_queue (using vector<int>, greater<int>):" << endl;
    cout << "Top element: " << min_pq.top() << endl; // 10

    // Pop an element
    min_pq.pop(); // Removes 10
    cout << "After pop() - New top: " << min_pq.top() << endl; // 20

    // Size and empty
    cout << "Size: " << min_pq.size() << endl; // 3
    cout << "Is empty? " << (min_pq.empty() ? "Yes" : "No") << endl;

    // Print and empty the min-priority queue
    cout << "Elements in ascending order (pop all): ";
    while (!min_pq.empty()) {
        cout << min_pq.top() << " ";
        min_pq.pop();
    }
    cout << endl << endl;

    // 7. Custom comparator: Priority queue for pairs (sort by second element, ascending)
    struct CompareSecond {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second > b.second; // min-heap on second
        }
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, CompareSecond> pq_pairs;
    pq_pairs.push({1, 40});
    pq_pairs.push({2, 25});
    pq_pairs.push({3, 60});

    cout << "Priority queue of pairs (min-heap by .second):" << endl;
    while (!pq_pairs.empty()) {
        cout << "(" << pq_pairs.top().first << ", " << pq_pairs.top().second << ") ";
        pq_pairs.pop();
    }
    cout << endl;

    return 0;
}

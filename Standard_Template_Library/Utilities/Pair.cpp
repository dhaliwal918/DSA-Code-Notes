#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    // 1. Basic pair usage
    pair<int, string> p1 = make_pair(1, "apple");
    cout << "p1: (" << p1.first << ", " << p1.second << ")" << endl;

    // 2. Pair of pairs
    pair<int, pair<string, double>> p2 = make_pair(2, make_pair("banana", 3.14));
    cout << "p2: (" << p2.first << ", (" << p2.second.first << ", " << p2.second.second << "))" << endl;

    // 3. Pair of vectors
    vector<int> v1 = {1,2,3};
    vector<string> v2 = {"A", "B"};
    pair<vector<int>, vector<string>> p3 = make_pair(v1, v2);

    cout << "p3.first (vector<int>): ";
    for (int n : p3.first) cout << n << " ";
    cout << endl;
    cout << "p3.second (vector<string>): ";
    for (const auto& s : p3.second) cout << s << " ";
    cout << endl;

    // 4. Vector of pairs
    vector<pair<int, int>> vp = { {1,2}, {3,4}, {5,6} };
    cout << "Vector of pairs: ";
    for (const auto& pp : vp) {
        cout << "(" << pp.first << "," << pp.second << ") ";
    }
    cout << endl;

    // 5. Pair of pair of pairs (nested example)
    pair< pair<int,int>, pair<string, string> > p4 = make_pair(make_pair(7,8), make_pair("x","y"));
    cout << "p4: ((" << p4.first.first << "," << p4.first.second << "), (" << p4.second.first << "," << p4.second.second << "))" << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

// Custom structure for demonstration
struct Student {
    string name;
    int age;
    double gpa;
    
    Student(string n, int a, double g) : name(n), age(a), gpa(g) {}
    
    // For easy printing
    friend ostream& operator<<(ostream& os, const Student& s) {
        os << s.name << "(" << s.age << "," << s.gpa << ")";
        return os;
    }
};

int main() {
    cout << "=== CUSTOM COMPARATOR SORTING ===" << endl;

    // 1️⃣ LAMBDA COMPARATORS
    vector<int> nums = {64, 34, 25, 12, 22, 11, 90};
    cout << "\n1️⃣ Lambda Comparators:" << endl;
    cout << "Original: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    // Ascending order (explicit lambda)
    sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
    cout << "Ascending: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    // Descending order (lambda)
    sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
    cout << "Descending: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    // 2️⃣ CUSTOM STRUCTURE SORTING
    vector<Student> students = {
        {"Alice", 20, 3.8},
        {"Bob", 19, 3.5},
        {"Charlie", 21, 3.9},
        {"Diana", 20, 3.7},
        {"Eve", 19, 3.6}
    };
    
    cout << "\n2️⃣ Custom Structure Sorting:" << endl;
    cout << "Original: ";
    for (const auto& s : students) cout << s << " ";
    cout << endl;
    
    // Sort by age (ascending)
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.age < b.age;
    });
    cout << "By age:    ";
    for (const auto& s : students) cout << s << " ";
    cout << endl;
    
    // Sort by GPA (descending)
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.gpa > b.gpa;
    });
    cout << "By GPA:    ";
    for (const auto& s : students) cout << s << " ";
    cout << endl;
    
    // Sort by name (lexicographical)
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.name < b.name;
    });
    cout << "By name:   ";
    for (const auto& s : students) cout << s << " ";
    cout << endl;

    // 3️⃣ MULTIPLE CRITERIA SORTING
    vector<Student> multi_students = {
        {"Alice", 20, 3.8},
        {"Bob", 20, 3.5},
        {"Charlie", 19, 3.9},
        {"Diana", 19, 3.7},
        {"Eve", 21, 3.6}
    };
    
    cout << "\n3️⃣ Multiple Criteria Sorting:" << endl;
    cout << "Original: ";
    for (const auto& s : multi_students) cout << s << " ";
    cout << endl;
    
    // Sort by age first, then by GPA (descending)
    sort(multi_students.begin(), multi_students.end(), [](const Student& a, const Student& b) {
        if (a.age != b.age) return a.age < b.age;  // Primary: age ascending
        return a.gpa > b.gpa;  // Secondary: GPA descending
    });
    cout << "Age↑,GPA↓: ";
    for (const auto& s : multi_students) cout << s << " ";
    cout << endl;

    // 4️⃣ FUNCTION OBJECT COMPARATORS
    struct CompareByLength {
        bool operator()(const string& a, const string& b) const {
            return a.length() < b.length();
        }
    };
    
    vector<string> words = {"apple", "banana", "cherry", "date", "elderberry"};
    cout << "\n4️⃣ Function Object Comparators:" << endl;
    cout << "Original: ";
    for (const string& w : words) cout << w << " ";
    cout << endl;
    
    // Sort by string length
    sort(words.begin(), words.end(), CompareByLength());
    cout << "By length: ";
    for (const string& w : words) cout << w << " ";
    cout << endl;

    // 5️⃣ STL FUNCTION OBJECTS
    vector<int> stl_nums = {64, 34, 25, 12, 22, 11, 90};
    cout << "\n5️⃣ STL Function Objects:" << endl;
    cout << "Original: ";
    for (int x : stl_nums) cout << x << " ";
    cout << endl;
    
    // Using STL function objects
    sort(stl_nums.begin(), stl_nums.end(), less<int>());
    cout << "Less:     ";
    for (int x : stl_nums) cout << x << " ";
    cout << endl;
    
    sort(stl_nums.begin(), stl_nums.end(), greater<int>());
    cout << "Greater:  ";
    for (int x : stl_nums) cout << x << " ";
    cout << endl;

    // 6️⃣ CUSTOM COMPARATOR FOR PAIRS
    vector<pair<int, string>> pairs = {
        {3, "third"}, {1, "first"}, {2, "second"}, {1, "first_dup"}
    };
    
    cout << "\n6️⃣ Custom Comparator for Pairs:" << endl;
    cout << "Original: ";
    for (const auto& p : pairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;
    
    // Sort by first element descending, then by second element ascending
    sort(pairs.begin(), pairs.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first != b.first) return a.first > b.first;  // Primary: first descending
        return a.second < b.second;  // Secondary: second ascending
    });
    cout << "Custom:   ";
    for (const auto& p : pairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;

    // 7️⃣ ABSOLUTE VALUE COMPARATOR
    vector<int> abs_nums = {-5, 3, -1, 4, -2, 6, -3};
    cout << "\n7️⃣ Absolute Value Comparator:" << endl;
    cout << "Original: ";
    for (int x : abs_nums) cout << x << " ";
    cout << endl;
    
    // Sort by absolute value
    sort(abs_nums.begin(), abs_nums.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });
    cout << "By abs:   ";
    for (int x : abs_nums) cout << x << " ";
    cout << endl;

    // 8️⃣ CASE-INSENSITIVE STRING COMPARATOR
    vector<string> case_words = {"Apple", "banana", "Cherry", "date", "Elderberry"};
    cout << "\n8️⃣ Case-Insensitive String Comparator:" << endl;
    cout << "Original: ";
    for (const string& w : case_words) cout << w << " ";
    cout << endl;
    
    // Sort case-insensitively
    sort(case_words.begin(), case_words.end(), [](const string& a, const string& b) {
        string a_lower = a;
        string b_lower = b;
        transform(a_lower.begin(), a_lower.end(), a_lower.begin(), ::tolower);
        transform(b_lower.begin(), b_lower.end(), b_lower.begin(), ::tolower);
        return a_lower < b_lower;
    });
    cout << "Case-ins: ";
    for (const string& w : case_words) cout << w << " ";
    cout << endl;

    // 9️⃣ COMPLEX CUSTOM COMPARATOR
    vector<vector<int>> matrix = {
        {1, 2, 3}, {4, 5}, {6, 7, 8, 9}, {10}, {11, 12}
    };
    
    cout << "\n9️⃣ Complex Custom Comparator (Sort vectors by sum):" << endl;
    cout << "Original: ";
    for (const auto& row : matrix) {
        cout << "[";
        for (int x : row) cout << x << " ";
        cout << "] ";
    }
    cout << endl;
    
    // Sort by sum of elements in each vector
    sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b) {
        int sum_a = 0, sum_b = 0;
        for (int x : a) sum_a += x;
        for (int x : b) sum_b += x;
        return sum_a < sum_b;
    });
    
    cout << "By sum:    ";
    for (const auto& row : matrix) {
        cout << "[";
        for (int x : row) cout << x << " ";
        cout << "] ";
    }
    cout << endl;

    // 🔟 PERFORMANCE NOTES
    cout << "\n🔟 Performance Notes:" << endl;
    cout << "- Lambda functions: Inline, good performance" << endl;
    cout << "- Function objects: Can be inlined, good performance" << endl;
    cout << "- Function pointers: May not be inlined, slower" << endl;
    cout << "- Complex comparators: Can impact performance" << endl;
    cout << "- Use const references in comparators for large objects" << endl;

    cout << "\n✅ All custom comparator sorting operations demonstrated successfully!" << endl;
    return 0;
}

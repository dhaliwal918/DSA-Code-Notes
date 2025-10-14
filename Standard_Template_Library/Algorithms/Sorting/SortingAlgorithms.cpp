#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <string>
#include <functional>
using namespace std;

// ==================== UTILITY FUNCTIONS ====================

// Utility function to print vector
void printVector(const vector<int>& vec, const string& label) {
    cout << label << ": ";
    for (int x : vec) cout << x << " ";
    cout << endl;
}

// Utility function to generate random vector
vector<int> generateRandomVector(int size) {
    vector<int> vec(size);
    iota(vec.begin(), vec.end(), 1);
    random_device rd;
    mt19937 g(rd());
    shuffle(vec.begin(), vec.end(), g);
    return vec;
}

// Utility function to copy vector
vector<int> copyVector(const vector<int>& original) {
    return vector<int>(original.begin(), original.end());
}

// ==================== SORTING ALGORITHM FUNCTIONS ====================

// 1️⃣ BUBBLE SORT
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// 2️⃣ SELECTION SORT
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

// 3️⃣ INSERTION SORT
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 4️⃣ MERGE SORT
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

// 5️⃣ QUICK SORT
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSort(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

// 6️⃣ HEAP SORT
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 7️⃣ COUNTING SORT
void countingSort(vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    vector<int> count(max_val + 1, 0);
    
    // Count occurrences
    for (int x : arr) {
        count[x]++;
    }
    
    // Rebuild array
    int idx = 0;
    for (int i = 0; i <= max_val; i++) {
        while (count[i] > 0) {
            arr[idx++] = i;
            count[i]--;
        }
    }
}

// 8️⃣ RADIX SORT
void radixSort(vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        vector<int> output(arr.size());
        vector<int> count(10, 0);
        
        // Count occurrences
        for (int x : arr) {
            count[(x / exp) % 10]++;
        }
        
        // Change count[i] so that count[i] contains actual position
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        // Build output array
        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        
        // Copy output array to arr
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }
    }
}

// ==================== PERFORMANCE TESTING ====================

long long measureTime(function<void(vector<int>&)> sortFunc, vector<int> arr) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(arr);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

// ==================== DEMONSTRATION FUNCTIONS ====================

void demonstrateSortingAlgorithm(const string& name, function<void(vector<int>&)> sortFunc, 
                                const vector<int>& testData, const string& complexity) {
    cout << "\n" << name << ":" << endl;
    vector<int> arr = copyVector(testData);
    printVector(arr, "Before");
    
    sortFunc(arr);
    printVector(arr, "After ");
    cout << "Time Complexity: " << complexity << endl;
}

void demonstrateAllAlgorithms() {
    cout << "=== DIFFERENT SORTING ALGORITHMS COMPARISON ===" << endl;
    
    vector<int> testData = {64, 34, 25, 12, 22, 11, 90};
    
    // Demonstrate each sorting algorithm
    demonstrateSortingAlgorithm("1️⃣ Bubble Sort", bubbleSort, testData, "O(n²), Space: O(1)");
    demonstrateSortingAlgorithm("2️⃣ Selection Sort", selectionSort, testData, "O(n²), Space: O(1)");
    demonstrateSortingAlgorithm("3️⃣ Insertion Sort", insertionSort, testData, "O(n²), Space: O(1)");
    demonstrateSortingAlgorithm("4️⃣ Merge Sort", [](vector<int>& arr) { mergeSort(arr); }, testData, "O(n log n), Space: O(n)");
    demonstrateSortingAlgorithm("5️⃣ Quick Sort", [](vector<int>& arr) { quickSort(arr); }, testData, "O(n log n) avg, O(n²) worst, Space: O(log n)");
    demonstrateSortingAlgorithm("6️⃣ Heap Sort", heapSort, testData, "O(n log n), Space: O(1)");
    
    // Special test data for counting and radix sort
    vector<int> countingData = {4, 2, 2, 8, 3, 3, 1};
    demonstrateSortingAlgorithm("7️⃣ Counting Sort", countingSort, countingData, "O(n + k), Space: O(k) where k is range");
    
    vector<int> radixData = {170, 45, 75, 90, 2, 802, 24, 66};
    demonstrateSortingAlgorithm("8️⃣ Radix Sort", radixSort, radixData, "O(d(n + k)), Space: O(n + k)");
}

void performanceComparison() {
    cout << "\n9️⃣ Performance Comparison (1000 elements):" << endl;
    
    vector<int> test_vec = generateRandomVector(1000);
    
    cout << "Algorithm\t\tTime (microseconds)" << endl;
    cout << "----------------------------------------" << endl;
    
    cout << "Bubble Sort\t\t" << measureTime(bubbleSort, copyVector(test_vec)) << endl;
    cout << "Selection Sort\t\t" << measureTime(selectionSort, copyVector(test_vec)) << endl;
    cout << "Insertion Sort\t\t" << measureTime(insertionSort, copyVector(test_vec)) << endl;
    cout << "Merge Sort\t\t" << measureTime([](vector<int>& arr) { mergeSort(arr); }, copyVector(test_vec)) << endl;
    cout << "Quick Sort\t\t" << measureTime([](vector<int>& arr) { quickSort(arr); }, copyVector(test_vec)) << endl;
    cout << "Heap Sort\t\t" << measureTime(heapSort, copyVector(test_vec)) << endl;
    cout << "STL sort()\t\t" << measureTime([](vector<int>& arr) { sort(arr.begin(), arr.end()); }, copyVector(test_vec)) << endl;
}

void printAlgorithmCharacteristics() {
    cout << "\n🔟 Algorithm Characteristics:" << endl;
    cout << "┌─────────────────┬─────────────┬─────────────┬─────────────┐" << endl;
    cout << "│ Algorithm       │ Best Case   │ Avg Case    │ Worst Case  │" << endl;
    cout << "├─────────────────┼─────────────┼─────────────┼─────────────┤" << endl;
    cout << "│ Bubble Sort    │ O(n)        │ O(n²)       │ O(n²)       │" << endl;
    cout << "│ Selection Sort │ O(n²)       │ O(n²)       │ O(n²)       │" << endl;
    cout << "│ Insertion Sort │ O(n)        │ O(n²)       │ O(n²)       │" << endl;
    cout << "│ Merge Sort     │ O(n log n)  │ O(n log n)  │ O(n log n)  │" << endl;
    cout << "│ Quick Sort     │ O(n log n)  │ O(n log n)  │ O(n²)       │" << endl;
    cout << "│ Heap Sort      │ O(n log n)  │ O(n log n)  │ O(n log n)  │" << endl;
    cout << "│ Counting Sort  │ O(n + k)    │ O(n + k)    │ O(n + k)    │" << endl;
    cout << "│ Radix Sort     │ O(d(n + k)) │ O(d(n + k)) │ O(d(n + k)) │" << endl;
    cout << "└─────────────────┴─────────────┴─────────────┴─────────────┘" << endl;
}

void printUsageGuidelines() {
    cout << "\n1️⃣1️⃣ When to Use Which Algorithm:" << endl;
    cout << "• Bubble Sort: Educational purposes only" << endl;
    cout << "• Selection Sort: Small datasets, memory constraints" << endl;
    cout << "• Insertion Sort: Small datasets, nearly sorted data" << endl;
    cout << "• Merge Sort: Stable sort needed, guaranteed O(n log n)" << endl;
    cout << "• Quick Sort: General purpose, average case performance" << endl;
    cout << "• Heap Sort: Memory constraints, guaranteed O(n log n)" << endl;
    cout << "• Counting Sort: Small range of integers" << endl;
    cout << "• Radix Sort: Integers with fixed number of digits" << endl;
    cout << "• STL sort(): Most cases (hybrid algorithm)" << endl;
}

// ==================== MAIN FUNCTION ====================

int main() {
    demonstrateAllAlgorithms();
    performanceComparison();
    printAlgorithmCharacteristics();
    printUsageGuidelines();
    
    cout << "\n✅ All sorting algorithms demonstrated successfully!" << endl;
    return 0;
}

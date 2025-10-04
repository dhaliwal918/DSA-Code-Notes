#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int st = 0, end = arr.size() - 1;
    while (st < end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] < arr[mid + 1])
        { // then it is in increasing part
            st = mid + 1;
        }
        else
        { // then it is in decreasing part
            end = mid;
        }
    }
    return st;
}

int main()
{
    // vector<int> arr = {0, 3, 8, 9, 5, 2};
    vector<int> arr = {3, 5, 3, 2, 0};
    cout << peakIndexInMountainArray(arr) << endl;
}
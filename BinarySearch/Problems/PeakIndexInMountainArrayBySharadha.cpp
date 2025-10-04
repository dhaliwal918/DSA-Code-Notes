#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int st = 1, end = arr.size() -1;
    while(st<=end){
        int mid = st + (end - st)/2;
        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
            return mid;
        }else if(arr[mid] > arr[mid-1]){
            st = mid + 1;
        }else {
            end = mid - 1;
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
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

bool binarySearch(vector<int> arr, int target){
    int st = 0, end = arr.size() -1;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(target > arr[mid]){
            st = mid + 1;
        }else if(target < arr[mid]){
            end = mid - 1;
        }else {
            return true;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (int i = 0; i < matrix.size(); i++)
    {
        if(binarySearch(matrix[i] , target)){
            return true;
        }
    }

    return false;
    
}

int main(){
    
}
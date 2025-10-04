#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

int algorithm(vector<int> arr , int target){
    int start = 0, end = arr.size() -1;
    while(start<=end){
        int mid = start + (end - start)/2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            start = mid + 1;
        }else{
            end = mid -1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,12,13,14,15,16};
    cout << algorithm(arr, 1) << endl;//0
    cout << algorithm(arr, 3) << endl;//2
    cout << algorithm(arr, 4) << endl;//3
    cout << algorithm(arr, 0) << endl;//-1
    cout << algorithm(arr, 8) << endl;//7
    cout << algorithm(arr, 16) << endl;//14
}
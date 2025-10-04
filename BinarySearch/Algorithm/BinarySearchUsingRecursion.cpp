#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

int algorithm(vector<int> arr , int start , int end , int target){
    if(start>end){
        return -1;
    }
    int mid = start + (end - start)/2;
    if(arr[mid] < target){
        return algorithm(arr, mid+1, end , target);
    }else if(arr[mid] > target){
        return algorithm(arr, start , mid -1 , target);
    }else{
        return mid;
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,12,13,14,15,16};
    cout << algorithm(arr,0,arr.size()-1, 1) << endl;//0
    cout << algorithm(arr,0,arr.size()-1, 3) << endl;//2
    cout << algorithm(arr,0,arr.size()-1, 4) << endl;//3
    cout << algorithm(arr,0,arr.size()-1, 0) << endl;//-1
    cout << algorithm(arr,0,arr.size()-1, 8) << endl;//7
    cout << algorithm(arr,0,arr.size()-1, 16) << endl;//14
}
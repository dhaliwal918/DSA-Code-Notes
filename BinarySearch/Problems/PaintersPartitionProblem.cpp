#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

bool isValid(vector<int> arr, int k , int target){
    int painters = 1, time = 0;
    for(int i = 0;i<arr.size(); i++){
        
        if(arr[i] > target) return false;

        if((arr[i] + time) <= target){
            time += arr[i];
        }else if((arr[i] + time) > target ){
            painters++;
            time = arr[i];
            if(painters > k) return false;
        }
    }
    if(painters == target){
        return true;
    }
}

int minTime(vector<int>& arr, int k) {
    if(k > arr.size()){
        return -1;
    }
    int st = 0, end = 0, ans = 0;
    for(int i = 0;i<arr.size(); i++) end += arr[i];

    while(st <= end){
        int mid = st + (end - st)/2;
        if(isValid(arr , k, mid)){
            ans = mid;
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {40,30,10,20};
    int k = 2;
    cout << minTime(arr, k) << endl;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

int solution(vector<int> arr, int target){
    int start = 0, end = arr.size() -1;
    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] == target){
            return mid;
        }

        if(arr[start] <= arr[mid]){ // if this true that means left side of mid is sorted
            if(arr[start] <= target && target <= arr[mid]){
                end = mid -1;
            }else {
                start = mid +1;
            }
        }else{
            if(arr[mid] <= target && target <= arr[end]){
                start = mid + 1;
            }else{
                end = mid -1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {9,10,2,3,4,5,6,7,8};
    cout << solution(arr, 1) << endl;
    cout << solution(arr, 3) << endl;
    cout << solution(arr, 4) << endl;
    cout << solution(arr, 0) << endl;
    cout << solution(arr, 8) << endl;
    cout << solution(arr, 16) << endl;
}
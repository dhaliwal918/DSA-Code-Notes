#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

void solution(vector<int> arr, int target){
    int start = 0, end = 0;
    int ans = 0;

    for(end ; end < arr.size() ; end++){
        ans += arr[end];

        while(ans > target && start < end){
            ans -= arr[start];
            start++;
        }

        if(ans == target){
            cout << "Subarray is from " << start << " to " << end << endl;
            return;
        }
    }
    cout << "The subarray not exist in given array" << endl;
    return;
}

int main(){
    vector<int> arr = {6,3,5,10,1,6};
    solution(arr , 19);
}
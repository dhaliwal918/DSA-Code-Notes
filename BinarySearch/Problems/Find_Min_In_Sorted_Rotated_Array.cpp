#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

int findMin(vector<int>& nums) {
    int st = 0, end = nums.size() -1, ans = 0;
    while(st <= end){
        int mid = st + (end - st)/2;
        // if(nums[mid] > ans){
        //     ans = nums[mid];
        // }
        if(nums[st] < nums[mid]){
            if(nums[st] < ans){
                ans = nums[st];
            }
            st = mid + 1;
        }else{
            if(nums[mid] < ans){
                ans = nums[mid];
            }
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
    
}
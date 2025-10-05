#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

int solution(vector<int> nums){
    int st = 0, end = nums.size() -1;
    while(st<end){
        int mid = st + (end - st)/2;
        if(nums[mid] == nums[mid+1] && mid!=(nums.size()-1)){
            if((mid - st) % 2 == 0){
                st = mid + 2;
            }else {
                end = mid - 1;
            }
        }else if(nums[mid] == nums[mid-1] && mid!=0) {
            if((mid - st - 1) % 2 == 0){
                st = mid + 1;
            }else {
                end = mid - 2;
            }
        }else{
            return nums[mid];
        }
    }
    return st;
}

int main(){
    
}
#include <iostream>
#include <vector>

using namespace std;

int firstOne(vector<int> nums, int target){
    int st = 0, end = nums.size() - 1;
    int ans = -1;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(nums[mid] == target){
            ans = mid;
            end = mid - 1;
        }else if(target > nums[mid]){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
}
int lastOne(vector<int> nums, int target){
    int st = 0, end = nums.size() - 1;
    int ans = -1;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(nums[mid] == target){
            ans = mid;
            st = mid + 1;
        }else if(target > nums[mid]){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.empty()) return {-1, -1};
    if(nums.size() == 1){
        if(nums[0] == target){
            return {0, 0};
        }else{
            return {-1, -1};
        }
    }
    int first = firstOne(nums, target);
    int last = lastOne(nums, target);
    return {first, last};
}

int main(){
    vector<int> vec = {1,2,3,3,5,6,8,8,9,10,11,15};
    vector<int> ans(2);
    vec = searchRange(vec, 8);
    cout << vec[0] << " " << vec[1] << endl;
}
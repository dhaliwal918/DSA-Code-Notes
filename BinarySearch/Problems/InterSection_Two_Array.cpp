#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

int search(vector<int> nums, int target){
    int st = 0, end = nums.size() - 1;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(target > nums[mid]){
            st = mid + 1;
        }else if(nums[mid] > target){
            end = mid - 1;
        }else {
            return mid;
        }
    }
    return -1;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        int j = 0;
        while(j < nums2.size()){
            int k = search(nums1, nums2[j]);
            if(k != -1){
                ans.push_back(nums1[i]);
                nums1.erase(nums1.begin() + i);
                nums2.erase(nums2.begin() + k);
                break;
            }
            j++;
        }
        
    }
    return ans;
    
}


int main(){
    
}



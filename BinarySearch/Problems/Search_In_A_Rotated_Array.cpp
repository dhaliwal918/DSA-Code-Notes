#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;



bool search(vector<int>& nums, int target) {
    int st = 0, end = nums.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (nums[mid] == target)
            return true;

        // Handle duplicates
        if (nums[st] == nums[mid] && nums[mid] == nums[end]) {
            st++;
            end--;
        }
        // Left half is sorted
        else if (nums[st] <= nums[mid]) {
            if (nums[st] <= target && target < nums[mid])
                end = mid - 1;
            else
                st = mid + 1;
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[end])
                st = mid + 1;
            else
                end = mid - 1;
        }
    }
    return false;
}


int main(){
    vector<int> vec = {2,5,6,0,0,1,2};
    int target = 5;
    if(search(vec, target)){
        cout << "True" << endl;
    }else {
        cout << "False" << endl;
    }
}
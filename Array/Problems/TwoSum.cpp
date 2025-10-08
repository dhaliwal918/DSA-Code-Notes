#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

// Pending

vector<int> twoSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int x = 0, y = 1;
    for (int i = 1; i < nums.size(); i++)
    {   
        if(nums[x] + nums[y] < target){
            y++;
        }else if(nums[x] + nums[y] > target){
            x++;
        }else{
            return {x,y};
        }
    }
    
}

int main()
{
}
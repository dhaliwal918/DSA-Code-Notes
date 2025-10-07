#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

bool isValid(vector<int> nums, int k, int t)
{
    int N = 1, sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > t)
            return false;
        if ((sum + nums[i]) <= t)
        {
            sum += nums[i];
        }
        else
        {
            N++;
            sum = nums[i];
            if (N > k)
            {
                return false;
            }
        }
    }
    return true;
}

int splitArray(vector<int> &nums, int k)
{
    int st = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > st)
        {
            st = nums[i];
        }
    }
    int end = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        end += nums[i];
    }

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isValid(nums, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {7, 2, 5, 10, 8};
    int k = 2;
    cout << splitArray(arr, k) << endl;
}
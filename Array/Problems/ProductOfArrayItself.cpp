#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ans(nums.size());

    int suffix = 1;
    ans[0] = 1;
    ans[nums.size() - 1] = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        suffix *= nums[i + 1];
        ans[i] *= suffix;
    }

    return ans;
}

int main()
{
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int pivt = -1;

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivt = i;
            break;
        }
    }

    if (pivt == -1)
    {
        // reverse array
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = nums.size() - 1; i > pivt; i--)
    {
        if (nums[i] > nums[pivt])
        {
            swap(nums[i], nums[pivt]);
            break;
        }
    }

    int i = pivt + 1;
    int j = nums.size() - 1;

    while (i < j)
    {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

int main()
{
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> pair;
    for (int i = 0; i < nums.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            if (nums[i] + nums[j] == target)
            {
                pair.push_back(i);
                pair.push_back(j);
                found = true;
                break;
            }
        }
        if (found)
        {
            break;
        }
    }
    return pair;
}

int main()
{
}
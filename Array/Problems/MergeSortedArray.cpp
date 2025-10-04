#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = 0; i < n; i++)
    {
        nums1.pop_back();
    }
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            nums1.insert(nums1.begin() + i, nums2[j]);
            i++;
            j++;
        }
    }

    for (j; j < nums2.size(); j++)
    {
        nums1.push_back(nums2[j]);
    }
}

int main()
{
}
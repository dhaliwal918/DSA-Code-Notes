#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

bool isValid(vector<int> arr, int k, int target)
{
    int st = 1, pages = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > target)
            return false;

        if ((pages + arr[i]) > target){
            st++;
            pages = arr[i];
            if (st > k){
                return false;
            }
        }else{
            pages += arr[i];
        }
    }
    return true;
}

int findPages(vector<int> &arr, int k)
{
    if (k > arr.size())
    {
        return -1;
    }
    int min = 0, max = 0, ans = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        max += arr[i];
    }

    while (min <= max)
    {
        int mid = min + (max - min) / 2;
        if (isValid(arr, k, mid))
        {
            ans = mid;
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {12,34,67,90};
    cout << findPages(arr, 2) << endl;
}
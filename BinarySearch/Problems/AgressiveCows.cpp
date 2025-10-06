#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

bool isPossible(vector<int> arr, int k, int targetDistance)
{
    int lastPlacedCow = arr[0], noOfCowsPlaced = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if ((arr[i] - lastPlacedCow) >= targetDistance)
        {
            lastPlacedCow = arr[i];
            noOfCowsPlaced++;
        }
        if (noOfCowsPlaced == k)
        {
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int st = 1, ans = 0;

    sort(stalls.begin(), stalls.end());

    int end = stalls.back() - stalls.front();

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isPossible(stalls, k, mid))
        {
            st = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 4, 8, 9};
    cout << aggressiveCows(arr, 3) << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<int> freq(n * n + 1, 0);
    vector<int> ans(2, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            freq[grid[i][j]]++;
        }
    }
    for (int val = 1; val <= n * n; val++)
    {
        if (freq[val] == 2)
        {
            ans[0] = val;
        }
        if (freq[val] == 0)
        {
            ans[1] = val;
        }
    }

    return ans;
}

int main()
{
}
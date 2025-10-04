#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int maxArea(vector<int> &height)
{
    int lp = 0, rp = height.size() - 1, maxV = 0;
    while (lp < rp)
    {
        maxV = max(maxV, min(height[lp], height[rp]) * (rp - lp));
        if (height[rp] < height[lp])
        {
            rp--;
        }
        else
        {
            lp++;
        }
    }
    return maxV;
}

int main()
{
}
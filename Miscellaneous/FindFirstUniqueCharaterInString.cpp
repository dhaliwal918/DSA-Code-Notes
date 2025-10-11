#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int firstUniqChar(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        bool isRepeat = false;
        for (int j = 0; j < s.length(); j++)
        {
            if (i == j)
            {
                continue;
            }
            else if (s[i] == s[j])
            {
                isRepeat = true;
            }
        }
        if (!isRepeat)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
}
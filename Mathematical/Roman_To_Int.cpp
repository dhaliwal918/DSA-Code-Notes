#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> map;

    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    int previous = 0;
    int ans = 0;

    for(int i = s.length() -1; i >= 0; i--){
        if(map[s[i]] >= previous){
            ans += map[s[i]];
        }else{
            ans -= map[s[i]];
        }
        previous = map[s[i]];
    }
    return ans;
}

int main()
{
}
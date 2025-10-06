#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

bool isAnagram(string s, string t) {
    int asciiOfS = 0, asciiOfT = 0;
    for (int i = 0; i < s.length(); i++)
    {
        asciiOfS += s[i];
    }
    for (int i = 0; i < t.length(); i++)
    {
        asciiOfT += t[i];
    }
    if(asciiOfS == asciiOfT){
        return true;
    }else {
        return false;
    }
    
}

int main(){
    
}
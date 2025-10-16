#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s == t){
        return true;
    }
    return false;
}
int main(){
    
}
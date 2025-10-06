#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()){
        return "";
    }
    string cp = strs[0];
    for (int i = 1; i < strs.size(); i++)
    {
        if(cp == ""){
            return "";
        }
        int j = 0;
        while(j < strs[i].length() && j < cp.length() && strs[i][j] == cp[j]){
            j++;
        }
        cp.erase(j);
    }
    return cp;
    
}

int main(){
    vector<string> strs = {"ab", "a"};
    cout << longestCommonPrefix(strs);
}
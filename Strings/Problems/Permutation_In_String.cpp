#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

bool checkInclusion(string s1, string s2) {
    if(s1.length() > s2.length()){
        return false;
    }
    vector<int> freq (26, 0);
    for(int i = 0; i < s1.length(); i++){
        freq[s1[i] - 'a']++;
    }
    for(int i = 0; i <= s2.length() - s1.length(); i++){
        vector<int> freq2(26,0);
        for(int j = i; j < i + s1.length(); j++){
            freq2[s2[j] - 'a']++;
        }
        bool found = true;
        for(int k = 0; k < freq.size(); k++){
            if(freq[k] != freq2[k]){
                found = false;
                break;
            }
        }
        if(found){
            return true;
        }
    }
    return false;
}

int main(){
    cout << checkInclusion("eidoaooo", "ab") << endl;

}
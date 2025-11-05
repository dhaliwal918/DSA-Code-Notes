#include <bits/stdc++.h>

using namespace std;

int compress(vector<char>& chars){
    int n = chars.size();
    int idx = 0;

    for(int i = 0; i<n ; i++){
        int count = 0;
        char c = chars[i];
        while(i<n && chars[i] == c){
            count++;
            i++;
        }
        if(count == 1){
            chars[idx] = c;
            idx++;
        }else{
            chars[idx] = c;
            idx++;
            string countS = to_string(count);
            for(auto c : countS){
                chars[idx++] = c;
            }
        }
        i--;
    }
    chars.resize(idx);
    return chars.size();
}

int main(){
    vector<char> chars = {'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c', 'd'};
    cout << compress(chars) << endl;
}
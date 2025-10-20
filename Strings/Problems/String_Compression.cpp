#include <bits/stdc++.h>

using namespace std;

int compress(vector<char>& chars){
    for(int i = 0; i<chars.size(); i++){
        int freq = 0;
        int j = i;
        for(j = i; j < chars.size(); j++){
            if(chars[i] == chars[j]){
                freq++;
            }else{
                break;
            }
        }
        if(freq == 1){
            chars.insert(chars.begin() + i + 1, '1');
        }else if(freq == 2){
            chars[i + 1] = '2';
        }else{
            chars[i + 1] = freq + '0';
            chars.erase(chars.begin() + i + 2, chars.begin() + j - 1);
        }
        freq = 0;
    }
    return chars.size();
}

int main(){
    vector<char> chars = {'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c', 'd'};
    cout << compress(chars) << endl;
}
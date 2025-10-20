#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<sstream>
#include<string>

using namespace std;

string reverseWords(string s) {
    vector<string> words;
    stringstream ss(s);  // helps read words separated by spaces
    string word;

    while (ss >> word) { // skips extra spaces automatically
        words.push_back(word);
    }

    reverse(words.begin(), words.end());

    string ans = "";
    for(int i = 0; i < words.size(); i++){
        ans += words[i];
        if(i != words.size() -1){
            ans += " ";
        }
    }
    return ans;
}

int main(){
    cout << reverseWords("My name is sukhmeet singh dhaliwal") << endl;
}
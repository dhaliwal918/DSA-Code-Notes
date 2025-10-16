#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

int main(){
    string str;
    getline(cin,str);
    int st = 0, end = str.length() -1;
    bool palindromeOrNot = true;
    while(st < end){
        if(str[st] != str[end]){
            palindromeOrNot = false;
            break;
        }
        st++;end--;
    }
    palindromeOrNot? cout << "True" << endl : cout << "False" << endl;
}

#include <bits/stdc++.h>

using namespace std;

bool isHappy(int n){
    unordered_set<int> seen;

    while(n != 1 && !seen.count(n)){
        seen.insert(n);
        int sum = 0;
        while(n > 0){
            sum = (n%10) * (n%10);
            n /= 10;
        }
        n = sum;
    }
    return n == 1;
}

int main(){
    cout << isHappy(19) << endl;
}
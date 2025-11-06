#include <bits/stdc++.h>

using namespace std;

bool isHappy(int n){
    if(n == 1){
        return true;
    }
    int prev = 1;
    int present = 1;
    while(n != 0){
        present += (n%10 * n%10);
        n/=10;
    }
    if(present == prev){
        return false;
    }
    return isHappy(present);
}

int main(){
    cout << isHappy(2) << endl;
}
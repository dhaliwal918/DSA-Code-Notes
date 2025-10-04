#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

int solution(int x, int pow){
    long long ans = 1; 
    long long base = x;

    while(pow > 0 ){
        if(pow & 1){
            ans *= base;
        }
        base *= base;
        pow >>= 1;
    }
    return ans;

}

int main(){
    cout << solution(2,5) << endl;
}
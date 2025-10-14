#include <iostream>
#include <cmath>
using namespace std;

int mySqrt(int x) {
    if(x < 2) return x;
    int st = 1, end = x/2;
    int ans = 0;
    while(st<=end){
        int mid = st + (end - st)/2;
        long long sq = 1LL * mid * mid;
        if(sq == x) return mid;
        if(sq < x){
            ans = mid;
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
    
}
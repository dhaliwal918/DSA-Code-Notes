#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

int algorithm(vector<int> arr){
    int currentSum = arr[0], maxSum = arr[0];
    for(int i = 1; i < arr.size(); i++){
        currentSum = max(arr[i], currentSum+=arr[i]);
        maxSum = max(currentSum , maxSum);
    }
    return maxSum;
}

// this algorithm for all integers like negative values also

int main(){
    vector<int> arr = {-1,2,-3,4,-1,5,6,9,-10,11};
    cout << algorithm(arr) << endl;
}
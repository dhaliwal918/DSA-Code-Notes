#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

int algorithm(vector<int> arr){
    int freq = 0, ans = 0;
    for (int  i = 0; i < arr.size(); i++)
    {
        if(freq == 0){
            ans = arr[i];
        }
        if(ans == arr[i]){
            freq++;
        }else{
            freq--;
        }
    }

    return ans;
    
}// this algorithm is only applicable when majority element is present in array more than n/2;

int main(){
    vector<int> arr = {2,3,2,3,2,5,2,3,2,1};
    cout << algorithm(arr) << endl;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<string>

using namespace std;

void sort(vector<int>& arr, int n){
    bool isFound = false;
    int smallNoIndex = INT_MIN;
    for (int i = 0; i < n-1; i++){ 
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[smallNoIndex]){
                smallNoIndex = j;
                isFound = true;
            }
        }
        swap(arr[i], arr[smallNoIndex]);
        if(!isFound){
            return;
        }
    }
    
}

int main(){
    vector<int> arr = {7,2,5,10,8};
    sort(arr, arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;

    }
    
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

void sort(vector<int>& arr, int n){
    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev] > current){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev+1] = current;
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
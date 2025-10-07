#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

void sort(vector<int>& arr){
    bool isSwap = false;
    for(int i = 0; i<arr.size(); i++){
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if(arr[j] > arr[j + 1]){
                swap(arr[j] , arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            return;
        }
    }
}

int main(){
    vector<int> arr = {9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-89};
    sort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    
}
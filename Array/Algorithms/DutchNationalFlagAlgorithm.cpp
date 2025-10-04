#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

void algorithm(vector<int>& arr){
    int low = 0, med = 0, high = arr.size() -1;
    while(med<=high){
        if(arr[med] == 0){
            swap(arr[low] , arr[med]);
            low++;
            med++;
        }else if(arr[med] == 1){
            med++;
        }else{
            swap(arr[med], arr[high]);
            high--;
        }
    }
}

int main(){
    vector<int> arr = {2,1,0,2,1,1,0,0};
    algorithm(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    
}
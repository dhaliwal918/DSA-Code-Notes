#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

void solution(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int idx = m+n-1;
    m--;
    n--;
    while(n>=0&&m>=0){
        if(nums1[m] > nums2[n]){
            nums1[idx] = nums1[m];
            idx--;
            m--;
        }else{
            nums1[idx] = nums2[n];
            idx--;
            n--;
        }
    }
    while(n >= 0){
        nums1[idx] = nums2[n];
        idx--;
        n--;
    }
}

int main(){
    int m = 3, n = 3;
    vector<int> nums1 = {1,2,3,0,0,0}; 
    vector<int> nums2 = {2,5,6};
    solution(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << endl;

    }
    
}
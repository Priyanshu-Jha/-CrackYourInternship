#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

int distributeChocolate(vector<int> arr, int m){
    int l = 0,r = m-1,ans = INT_MAX;
    while(r<arr.size()){
        ans  = min(ans,abs(arr[r]-arr[l]));
        l++;
        r++;
    }
    return ans;
}

int main(){
    vector<int> arr {7, 3, 2, 4, 9, 12, 56} ;
    int m = 3;
    sort(arr.begin(),arr.end());
    cout<<distributeChocolate(arr,m);
}
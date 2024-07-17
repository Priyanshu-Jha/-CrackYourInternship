#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums) {
        int a = 0,b = 0,c = nums.size()-1;
        while(b<=c){
            if(nums[b] == 2){
                swap(nums[b],nums[c]);
                c--;
            }
            else if(nums[b] == 1)
                b++;
            else{
                swap(nums[a],nums[b]);
                a++;
                b++;
            }
        }
    }
int main(){
    vector<int> arr{2,0,2,1,1,0};
    sortColors(arr);
    for(auto it:arr)
        cout<<it<<" ";
}
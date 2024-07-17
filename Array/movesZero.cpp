#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int left = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] != 0)
        {
            swap(nums[right], nums[left]);
            left++;
        }
    }
}
int main(){
    vector<int> vec{0,0,0,0,11,3,2,0,2,1,0,0};
    moveZeroes(vec);
    for(auto it:vec)
        cout<<it<<" ";
}
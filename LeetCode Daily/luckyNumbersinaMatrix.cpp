#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int findminIndex(vector<int> arr)
{
    int temp = INT_MAX, index = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (temp > arr[i])
        {
            temp = arr[i];
            index = i;
        }
    }
    return index;
}

bool checkColMax(vector<vector<int>> arr, int j, int val)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i][j] > val)
            return false;
    }
    return true;
}

vector<int> luckyNumbers(vector<vector<int>> &matrix)
{
    vector<int> ans;
    for (int i = 0; i < matrix.size(); i++)
    {
        int j = findminIndex(matrix[i]);
        if (checkColMax(matrix, j, matrix[i][j]))
            ans.push_back(matrix[i][j]);
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr{{3,7,8},{9,11,13},{15,16,17}};
    vector<int>ans = luckyNumbers(arr);
    for(auto it:ans)
        cout<<it<<" ";
}

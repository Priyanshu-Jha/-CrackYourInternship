#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int buy = INT_MAX, profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < buy)
        {
            buy = prices[i];
        }
        else
            profit = max(profit, prices[i] - buy);
    }
    return profit;
}

int main()
{
    vector<int> arr{7, 1, 5, 3, 6, 4};
    cout << maxProfit(arr);
}
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    set<int> row, col;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                row.insert(i);
                col.insert(j);
            }
        }
    }

    for (auto it : row)
    {
        for (int i = 0; i < matrix[0].size(); i++)
            matrix[it][i] = 0;
    }
    for (auto it : col)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i][it] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes(matrix);
    for (auto it : matrix)
    {
        for (auto x : it)
            cout << x << " ";
        cout << "\n";
    }
}
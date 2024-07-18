#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
vector<int> solve(TreeNode *root, int d, int &ans)
{
    if (!root)
        return {0};
    if (root->left == NULL and root->right == NULL)
        return {1};
    auto l = solve(root->left, d, ans);
    auto r = solve(root->right, d, ans);

    for (auto a : l)
        for (auto b : r)
            if ((a and b) and a + b <= d)
                ans++;

    vector<int> ret;
    for (auto a : l)
        if (a and a + 1 < d)
            ret.push_back(a + 1);
    for (auto a : r)
        if (a and a + 1 < d)
            ret.push_back(a + 1);
    return ret;
}

int countPairs(TreeNode *root, int distance)
{
    int ans = 0;
    solve(root, distance, ans);
    return ans;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    int d = 4;
    cout<<countPairs(root,d);

}
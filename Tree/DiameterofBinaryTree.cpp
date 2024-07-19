#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<unordered_map>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int diameterOfBinaryTree(TreeNode* root) {
     if(!root)
        return 0;
     if(root->left == NULL and root->right == NULL)
        return 1;
    int l = diameterOfBinaryTree(root->left);
    int r = diameterOfBinaryTree(root->right);
    int ans = max(l,r);
    return ans+1;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    cout<<diameterOfBinaryTree(root);
}
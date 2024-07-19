#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

//  * Definition for a binary tree node.
struct Node
{
     int data;
     Node *left;
     Node *right;
     Node(int val)
     {
          data = val;
          left = NULL;
          right = NULL;
     }
};

int maxSumPath(Node* root,int &ans){
    if(root == NULL)
        return 0;
    int lsum = maxSumPath(root->left,ans);
    int rsum = maxSumPath(root->right,ans);

    if(root->data + lsum + rsum>ans)
        ans = root->data + lsum + rsum;
    return root->data + max(lsum,rsum);
}

int main()
{
    Node* root = new Node(-10);
    root->left= new Node(9);
    root->right= new Node(20);
    // root->left->left= new Node(4);
    // root->left->right= new Node(5);
    root->right->left= new Node(15);
    root->right->right= new Node(7);
    int ans =INT_MIN;
    maxSumPath(root,ans);
    cout<<ans;
}



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

int depth(Node*root){
    if(root == NULL)
        return 0;
    return 1+ max(depth(root->left),depth(root->right));
}

// T(n) = O(n*n)
// bool checkBalanced(Node*root){
//     if(root == NULL)
//         return true;
    
//     int left = depth(root->left);
//     int right = depth(root->right);

//     if(abs(left-right>1))
//         return false;
    
//     bool le = checkBalanced(root->left);
//     bool ri = checkBalanced(root->right);

//     if(!le or !ri)
//         return false;
//     return true;

// }

int checkBalanced(Node* root){
    if(root == NULL)
        return 0;
    int l = checkBalanced(root->left);
    int r = checkBalanced(root->right);

    if(l == -1 or r == -1)
        return -1;

    if(abs(l-r)>1)
        return -1;
    return 1+max(l,r);
}

int main()
{
    Node* root = new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    // root->left->left->left= new Node(6);
    // root->left->= new Node(7);
    int ans = checkBalanced(root);
    if(ans != -1)
        cout<<"Balanced Tree";
    else
        cout<<"Not Balanced Tree";
}



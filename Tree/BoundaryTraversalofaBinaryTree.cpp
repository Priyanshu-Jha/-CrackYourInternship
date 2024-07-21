#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include<queue>
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

bool isLeaf(Node * root){
    return !root->left and !root->right;
}

void addLeftBoundary(Node* root,vector<int>& ans){
    Node* root1 = root->left;
    while(root1){
        // cout<<root1->data<<" ";
        if(!isLeaf(root1)){
            ans.push_back(root1->data);
            // return;
        }

        if(root1->left)
            root1 = root1->left;
        else
            root1 = root1->right;

    }

}

void addLeaf(Node* root,vector<int>& ans){

    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    
    if(root->left)
        addLeaf(root->left,ans);
    if(root->right)
        addLeaf(root->right,ans);
}

void addRightBoundary(Node* root,vector<int>& ans){
    vector<int> temp;
    Node* root1 = root->right;
    while(root1){
        if(!isLeaf(root1))
            temp.push_back(root1->data);            
        if(root1->right)
            root1 = root1->right;
        else
            root1 = root1->left;
    }
    for(int i = temp.size()-1;i>=0;i--)
        ans.push_back(temp[i]);
}

vector<int> printBoundary(Node* root){
    vector<int> ans;
    if(!root)
        return ans;

    if(!isLeaf(root))
        ans.push_back(root->data);

    addLeftBoundary(root,ans);
    addLeaf(root,ans);
    addRightBoundary(root,ans);

    return ans;

}


int main()
{
    Node* root = new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    // cout<<"print";
    vector<int> ans;
    ans = printBoundary(root);
    // cout<<ans.size();
    for(auto it:ans)
        cout<<it<<" ";
}



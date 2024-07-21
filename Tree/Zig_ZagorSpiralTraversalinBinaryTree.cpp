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

vector<vector<int>> zigZag(Node* root){
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);
    bool check = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0;i<size;i++){
            Node* node = q.front();
            q.pop();
            level.push_back(node->data);
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
        }
        if(check){
            ans.push_back(level);
        }
        else{
            reverse(level.begin(),level.end());
            ans.push_back(level);
        }
        check = !check;
    }
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
    root->left->left->left = new Node(8);
    root->left->right->right= new Node(9);

    vector<vector<int>> ans = zigZag(root);

    for(auto it:ans){
        for(auto x:it)
            cout<<x<<" ";
        cout<<endl;
    }
}



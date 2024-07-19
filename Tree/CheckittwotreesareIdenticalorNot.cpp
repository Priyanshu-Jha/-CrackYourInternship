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

bool checkIdentical(Node*root1,Node*root2){
    if(root1 == NULL and root2 == NULL)
        return true;
    if(root1 == NULL or root2 == NULL)
        return false;
    bool ans1 = checkIdentical(root1->left,root2->left);
    bool ans2 = checkIdentical(root1->right,root2->right);

    if(root1->data != root2->data)
        return false;
    return ans1 and ans2;
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

    Node* root1 = new Node(1);
    root1->left= new Node(2);
    root1->right= new Node(3);
    root1->left->left= new Node(4);
    root1->left->right= new Node(5);
    root1->right->left= new Node(6);
    // root1->right->right= new Node(7);
    // root1->right->right->ir= new Node(7);

    if(checkIdentical(root,root1))
        cout<<"Identical";
    else
        cout<<"Not Identical";

}




#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;

//  * Definition for a binary tree node.
struct Node {
     int data;
     Node *left;
     Node *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preOrder(Node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";    
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL)
        return;
    postOrder(root->left);   
    postOrder(root->right);    
    cout<<root->data<<" "; 
} 

vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ans;
    if(root == NULL)
        return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0;i<size;i++){
            Node* node= q.front();
            q.pop();
            level.push_back(node->data);
            if(node->left!= NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
            
        }
        ans.push_back(level);
    } 
    return ans;
}

vector<int> iterativePreOrder(Node* root){
    vector<int> ans;
    if(root == NULL)
        return ans;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        if(node->right != NULL)
            st.push(node->right);
        if(node->left != NULL)
            st.push(node->left);
        ans.push_back(node->data);
    }
    return ans;
}

vector<int> iterativeInOrder(Node* root){
    vector<int> ans;
    stack<Node*> st;
    Node* node = root;
    while(true){
        if(node!= NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty())
                break;
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}

vector<int> postOrderUsing2Stack(Node*root){
    vector<int> ans;
    if(root == NULL)
        return ans;
    stack<Node*> st1,st2;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left !=NULL)
            st1.push(root->left);
        if(root->right != NULL)
            st1.push(root->right);
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;

}


int main(){
    Node* root = new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    preOrder(root);
    cout<<endl;
    vector<int> pre = iterativePreOrder(root);
    for(auto it:pre)
        cout<<it<<" ";
    cout<<endl;
    inOrder(root);
    cout<<endl;
    vector<int> inOr = iterativeInOrder(root);
    for(auto it:inOr)
        cout<<it<<" ";
    cout<<endl;
    postOrder(root);
    cout<<endl;
    vector<int> post = postOrderUsing2Stack(root);
    for(auto it:post)
        cout<<it<<" ";
    
    cout<<endl;
    vector<vector<int>> ans = levelOrder(root);
    for(auto it:ans){
        for(auto x:it)
            cout<<x<<" ";
        cout<<endl;
    }
}

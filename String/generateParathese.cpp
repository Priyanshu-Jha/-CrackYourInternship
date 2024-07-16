#include<iostream>
#include<vector>
using namespace std;


void solve(int l,int r,int n,string s,vector<string>& ans){
    if(l == r and (l+r) == 2*n){
        ans.push_back(s);
        return;
    }

    if(l>r)
        solve(l,r+1,n,s+")",ans);
    if(l<n)
        solve(l+1,r,n,s+"(",ans);
}

int main(){
    int n;
    cin>>n;
    string x  = "";
    vector<string>ans;
    solve(0,0,n,x,ans);
    for(auto it:ans)
        cout<<it<<"\n";
    // cout<<ans.size();
}
#include<iostream>
using namespace std;

string solve(string s,int i,string p,int j){
    if(j == p.length())
        return "";
    if(s[i++] == p[j++]){
        return
    }
}

string smallestWindow (string s, string p){
    return solve(s,0,p,0);
}

int main(){
    string s,p;
    cin>>s>>p;
    cout<<smallestWindow(s,p);
}
#include<iostream>
#include<unordered_map>
using namespace std;

void printDup(string str){
    unordered_map<char,int> mp;
    for(auto s: str)
        mp[s]++;
    for(auto it:mp){
        if(it.second>1)
            cout<<it.first<<" count = "<<it.second<<"\n";
    }
}

int main(){
    string str = "test string";
    // cin>>str;
    printDup(str);
}
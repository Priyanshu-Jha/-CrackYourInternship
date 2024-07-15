#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string ans = "";
        for(int i = 0;i<min(strs[0].length(),strs[strs.size()-1].length());i++){
            if(strs[0][i] == strs[strs.size()-1][i])
                ans += strs[strs.size()-1][i];
            else
                break;
        }
        return ans;
}

int main(){
    vector<string> arr = {"flower","flow","flight"};
    cout<<longestCommonPrefix(arr);
}
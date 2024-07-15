#include<iostream>
using namespace std;
int strStr(string haystack, string needle) {
        if(haystack.find(needle) == string::npos)
            return -1;
        return haystack.find(needle);
}
 
int main(){
    string str,str1;
    cin>>str>>str1;
    int ans = strStr(str,str1);
    if(ans)
        cout<<"found it at index: "<<ans;
    else
        cout<<"Not Found";
}
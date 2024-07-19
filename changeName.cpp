#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main()
{   
    string questionName,ans;
    getline(cin,questionName);
    // cout<<questionName;
    for(int i = 0;i<questionName.length();i++){
        if(questionName[i]!= ' '){
            ans+= questionName[i];
           
        }
        else if(questionName[i]>'a')
             questionName[i+1] -= 32;
            // ans+= questionName[i];
    }
    cout<<ans;

}



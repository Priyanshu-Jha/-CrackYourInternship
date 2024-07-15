#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
        stack<char> st;
        if(s.length()&1)
            return false;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(' or s[i] == '[' or s[i] == '{')
                st.push(s[i]);
            else if(st.empty())
                return false;
            else if(s[i] == ')' and st.top() == '(')
                st.pop();
            else if(s[i] == ']' and st.top() == '[')
                st.pop();
            else if(s[i] == '}' and st.top() == '{')
                st.pop();
            else
                return false;  
        }
        if(st.empty())
            return true;
        return false;
    }


int main(){
    string s;
    cin>>s;
    cout<<isValid(s);
}
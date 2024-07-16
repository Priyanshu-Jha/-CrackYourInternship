#include<iostream>
#include<stack>
using namespace std;

string reverseWords(string s) {
        stack<string> stack;
        string temp;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (temp.length() != 0) {
                    stack.push(temp);
                    temp = "";
                }
            }
             else
                temp += s[i];
        }
        if(temp.length()>0)
            stack.push(temp);
        temp = "";
        while (!stack.empty()) {
            // cout<<stack.top()<<endl;
            temp += stack.top() + " ";
            stack.pop();
        }
        temp.erase(temp.length() - 1);
        return temp;
}

int main(){
    string str = "MU CHu lee chooo    ooo";
    cout<<reverseWords(str);
}
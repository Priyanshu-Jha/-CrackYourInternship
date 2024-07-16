#include <iostream>
#include<stack>
using namespace std;

string simplifyPath(string path)
{
    stack<string> arr, arr1;
    string temp = "";
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '/')
        {
            if (temp.length() != 0 and temp != ".")
            {
                if (temp == ".." and !arr.empty())
                {
                    arr.pop();
                }
                else if (temp != "..")
                    arr.push("/" + temp);
            }
            temp = "";
        }
        else
            temp += path[i];
    }
    cout << "Printing " << temp << endl;
    if (temp == ".." and !arr.empty())
        arr.pop();
    else if (temp.length() >= 1 and temp != ".." and temp != ".")
        arr.push("/" + temp);

    temp = "";
    while (!arr.empty())
    {
        arr1.push(arr.top());
        arr.pop();
    }
    while (!arr1.empty())
    {
        temp += (arr1.top());
        arr1.pop();
    }

    if (temp.length() == 0)
        temp = "/";
    return temp;
}

int main()
{
    string str;
    cin>>str;
    cout << simplifyPath(str);
}
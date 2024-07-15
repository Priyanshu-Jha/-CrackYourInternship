#include <iostream>
using namespace std;

bool check(string s)
{
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        if (s[left++] != s[right--])
            return false;
    }
    return true;
}

bool validPalindrome(string s)
{
    if (check(s))
        return true;
    int left = 0, right = s.length() - 1, n = s.length();
    while (left < right)
    {
        if (s[left] != s[right])
            break;
        left++;
        right--;
    }
    string s1 = "", s2 = "";
    for (int i = 0; i < left; i++)
        s1 += s[i];
    for (int i = left + 1; i < n; i++)
        s1 += s[i];
    for (int i = 0; i < right; i++)
        s2 += s[i];
    for (int i = right + 1; i < n; i++)
        s2 += s[i];
    if (check(s1) or check(s2))
        return true;
    return false;
}

int main(){
    string str;
    cin>>str;
    cout<<validPalindrome(str);
}
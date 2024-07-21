#include<iostream>
using namespace std;


 bool bin(unsigned n,unsigned k) {
        if(n == 0 or n == 0)
            return true;
        /* step 1 */
        if (n > 1 or k>1)
             return bin(n / 2,k/2);
        if(n%2 == 0 and k%2 == 1)
            return false;
        return true;
    }

    // int minChanges(int n, int k) {
    //     string s1,s2; 
    //     bin(n,k);
    //     cout<<s1;
    //     return 0;
    // }
int main(){
    // int n = 1;
    cout<<bin(14,13);
}
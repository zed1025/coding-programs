/**
    Problem Link: https://leetcode.com/problems/power-of-four/
    Date: 13/01/2023
    Level: Easy
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//functions
//try 1 -> accepted -> https://leetcode.com/problems/power-of-four/submissions/877220209/
bool isPowerOfFour(int n) {
    if(n<=0) return false;
    if(n==1) return true;
    double x = (double)n/4;
    int y = x;
    if(x > y) return false; 
    return isPowerOfFour(y);
}

//try 2 -> https://leetcode.com/problems/power-of-four/solutions/2976057/compact-and-fast-and-actual-bit-manipulation/
bool isPowerOfFour2(int n) {
    ll x=1;
    while(x<n) x = x<<2;
    return x==n?true:false;
}

//try 3 -> accepted
bool isPowerOfFour3(int n) {
    if(n <= 0) return false;
    return ceil(log(n)/log(4))==floor(log(n)/log(4));
}

//solution 1 -> https://leetcode.com/problems/power-of-four/solutions/2461582/c-one-liner-easy-code/
bool isPowerOfFour4(int n) {
    return n>0 && (n&(n-1))==0 && (n&0x55555555);
    // n>0, n should be positive
    // n&(n-1) ensure it is power of 2
    // 5 is "0101" so n&0x55555... ensure that set bit is at the even position.
    // soo if n is power of 2 and set bit is at even position -> n is power of 4
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    
    if(isPowerOfFour2(n)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
    return 0;
}
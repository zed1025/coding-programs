/**
https://leetcode.com/problems/power-of-two/
*/

#include<bits/stdc++.h>
using namespace std;

//functions
//brute force -> Working
bool powerOfTwo(int n) {
    int x;
    for(int i=0; i<n; i++) {
        x = pow(2, i);
        if(x == n) {
            return true;
        }
        if(x > n) {
            return false;
        }
    }
    return false;
}

//Try 1 -> accepted
//https://leetcode.com/problems/power-of-two/submissions/877200988/
bool powerOfTwo2(int n) {
    //base cases
    if(n==1) {
        return true;
    }
    if(n==0) {
        return false;
    }
    double x = double(n)/2;
    int y = x;
    cout << "x=" << x << "\ty=" << y << endl;
    if(x > y) {
        return false;
    }

    //recursive case
    return powerOfTwo2(y);
}

//solution 1 -> https://leetcode.com/problems/power-of-two/solutions/1638707/python-c-java-detailly-explain-why-n-n-1-works-1-line-100-faster-easy/
bool powerOfTwo3(int n) {
    //return (n > 0) && not(n & (n-1)); //one liner

    if(n<=0) return false;
    return ((n&(n-1))==0);
}

//solution 2 -> https://leetcode.com/problems/power-of-two/solutions/1638704/c-easy-to-solve-all-interview-approaches-with-detailed-explanations/
bool powerOfTwo4(int n) {
    if(n <= 0) return false;
    return ceil(log2(n)) == floor(log2(n));
}
int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    
    if(powerOfTwo4(n)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
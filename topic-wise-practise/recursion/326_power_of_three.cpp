/**
    Problem Link: https://leetcode.com/problems/power-of-three/
    Level: Easy
    Date: 13/01/2023
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//functions
//brute force -> accepted
bool isPowerOfThree(int n) {
    int x;
    for(int i=0; i<n; i++) {
        x = pow(3, i);
        if(x == n) {
            return true;
        }
        if(x > n) {
            return false;
        }
    }
    return false;
}

//try 1 -> recursion -> accepted
bool isPowerOfThree2(int n) {
    if(n<=0) return false;
    if(n==1) return true;
    double x = (double)n/3;
    int y = x;
    if(x > y) return false;
    return isPowerOfThree2(y);
}

//solution 1 -> https://leetcode.com/problems/power-of-three/solutions/2471285/python-c-one-liner-o-1-easy-solution-with-detailed-explanation-beginner-friendly/
bool isPowerOfThree(int n){
    //Because 3^19(1,162,261,467) is the largest power of three under 2^31 - 1 (solution by exploiting constraints)
    //So we just neet to check if n > 0 and whether 3^19 % n is 0
    return (n > 0) && (1162261467 % n == 0);
}

int main() {
    
    return 0;
}
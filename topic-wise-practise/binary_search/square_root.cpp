/**
https://www.youtube.com/watch?v=6z2HK4o8qcU&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=15
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//functions
double morePrecision(int n, int precision, int integerPart) {
    double factor = 1;
    double ans = integerPart;

    for(int i=0; i<precision; i++) {
        factor = factor/10;
        for(double j=ans; j*j < n; j+=factor) {
            ans = j;
        }
    }
    return ans;
}

ll squareRoot(int num) {
    int s = 0;
    int e = num-1;

    ll mid = s + (e-s)/2;
    int ans=-1;

    while(s<=e) {
        // int square = mid*mid; // will cause problem if mid*mid doesnt fit inside an int value
        ll square = mid*mid;
        if(mid*mid == num) {
            return mid;
        }
        if(mid*mid > num) {
            e = mid-1;
        } else { // mid*mid < num
            ans = mid;
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {
    cout << "Enter Number: ";
    int n;
    cin >> n;

    int precision = 3;

    cout << "Square root of " << n << " is: " << morePrecision(n, precision, squareRoot(n)) << endl;
    return 0;
}
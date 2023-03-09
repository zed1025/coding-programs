/**
    Fibonacci Series Iterative
    OKAY
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cout << "Enter Number: ";
    int n;
    cin >> n;

    int a=0, b=1, temp;

    for(int i=0; i<n; i++) {
        cout << a << " ";
        temp = a;
        a = b;
        b = temp+b;
    }
    return 0;
}
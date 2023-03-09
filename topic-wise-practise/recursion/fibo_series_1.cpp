#include<iostream>

using namespace std;

int fib(int n) {
    //base case
    if (n==0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    //recursive call
    int out = fib(n-1) + fib(n-2);
    return out;
}

int main() {
    cout << "Enter Number: ";
    int n;
    cin >> n;

    //recursive call
    int x = fib(n); // x contains the nth fibonacci number
    cout << "\n" << n << "th fibonacci number is: " << x << endl;
}
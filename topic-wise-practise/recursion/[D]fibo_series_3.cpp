/**
    Fibonacci Series, Memoization Solution
*/

#include<iostream>

using namespace std;

int fibo(int n, int *arr) {
    //base case
    if(n==0) return 0;
    if(n==1) return 1;
    
    cout << n << endl;  

    if(arr[n]) return arr[n];
    int out = fibo(n-1, arr)+fibo(n-2, arr);
    // cout << out << endl;
    arr[n] = out;

    return out;
} 


int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    fill_n(arr, n, 0);

    if(n>=1) {
        arr[0] = 0;
        arr[1] = 1;
    }

    int x = fibo(n, arr);

    cout << x << endl;
}
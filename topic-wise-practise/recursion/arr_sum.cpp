#include<bits/stdc++.h>
using namespace std;

int findSum(int *arr, int size) {
    
    //base case
    if(size==1) {
        return arr[0];
    }
    if(size==0) {
        return 0;
    }

    //processing

    //recursive case
    return arr[0]+findSum(arr+1, size-1);
}

int main() {
    int arr[] = {3, 2, 1, 5, 6, 3}; //5

    int sum = findSum(arr, 6);
    cout << "Sum = " << sum << endl;
}
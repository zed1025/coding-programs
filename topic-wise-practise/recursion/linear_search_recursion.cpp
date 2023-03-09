#include<bits/stdc++.h>
using namespace std;

bool linearSearchRecursive(int arr[], int size, int key) {

    // base case 
    if(size == 0) {
        return false;
    }

    //recursive case
    if(arr[0] == key) {
        return true;
    } 
    return linearSearchRecursive(arr+1, size-1, key);
}

int main() {

    int arr[] = {4, 6, 7, 1, 34, 89, 100};
    int size = 7;
    int key = 4;

    bool result = linearSearchRecursive(arr, size, key);

    if(result) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }

    return 0;
}
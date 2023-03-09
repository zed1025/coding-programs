#include<bits/stdc++.h>
using namespace std;

void print(int *arr, int start, int end) {
    for(int i=start; i<end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool binarySearch(int *arr, int start, int end, int key) {
    print(arr, start, end);

    //base case
    // if(end-start == 0) { //empty array
    if(start > end) { //empty array
        return false;
    }
    int mid = start + (end-start)/2;

    cout << "Value of array mid is " << arr[mid] << endl;

    if(arr[mid] == key) { //key found, return true
        return true;
    }

    //recursive case
    if(arr[mid] < key) {
        return binarySearch(arr, mid+1, end, key);
    }
    return binarySearch(arr, start, mid-1, key);
}

int main() {
    int arr[] = {1, 4, 6, 7, 34, 89, 100};
    int size = 7;
    int start=0, end=size;
    int key = 4;

    bool result = binarySearch(arr, start, end, key);
    // cout << result;
    if(result) {
        cout << "\n\nFound\n";
    } else {
        cout << "\n\nNot Found\n";
    }

    return 0;
}
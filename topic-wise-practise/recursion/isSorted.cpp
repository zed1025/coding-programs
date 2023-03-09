#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int index, int size) {

    // base case
    if(index+1 == size) { //only one element
        return true;
    }
    if(arr[index] > arr[index+1]) {
        return false;
    } 

    //recursive call
    return isSorted(arr, index+1, size);
}

int main() {
    // given an array check if its sorted using recursion
    int arr1[] = {1, 4, 5, 6, 7, 8, 99}; //7
    int arr2[] = {3, 5, 6, 8, 1, 8, 6, 2}; //8

    bool result = isSorted(arr2, 0, 8);
    if(result) {
        cout << "Sorted\n";
    } else {
        cout << "Not Sorted\n";
    }
    
}
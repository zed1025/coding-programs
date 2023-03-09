/**
https://leetcode.com/problems/peak-index-in-a-mountain-array/
*/

#include<bits/stdc++.h>
using namespace std;

int findPeak(int *arr, int s, int e) {

    int mid = s + (e-s)/2;
    // while(s<=e) { //error -> do numerical on paper to understand, it will get stuck, when both e and s point to the same element
    while(s < e) {
        if(arr[mid] < arr[mid+1]) {
            s = mid+1;
        } else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int main() {
    // int arr[] = {1,2,4,6,9,20,99,77,65,33,9,7};
    // int size = 12;
    int arr[] = {8,6,4,2};
    int size=4;

    int peakIndex = findPeak(arr, 0, size-1);

    cout << peakIndex << endl;
    return 0;
}
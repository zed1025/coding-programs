#include<bits/stdc++.h>
using namespace std;

int findPeak(int *arr, int s, int e) {
    //base case 
    if(s > e) {
        return -1;
    }

    int mid = s + (e-s)/2;
    int temp=-1;
    
    // if(arr[mid] > arr[mid+1] && arr[mid]>arr[mid-1]) { //doesnt work if the first element of the array is the peak
    //     return mid;
    // }

    //recursive case
    if(arr[mid] < arr[mid+1]) {
        temp = findPeak(arr, mid+1, e);
    } else {
        temp = findPeak(arr, s, mid);
        /**
        Here we only reduce end to mid and not mid-1 because 
        peak can be anywhere to the right of the mid or the mid itself
        */
    }
    return temp;
}

int main() {

    // int arr[] = {1,2,4,6,9,20,99,77,65,33,9,7};
    int arr[] = {8, 6, 4 ,2};
    // int size = 12;
    int size=4;

    int peakIndex = findPeak(arr, 0, size-1);

    cout << peakIndex << endl;
    return 0;
}
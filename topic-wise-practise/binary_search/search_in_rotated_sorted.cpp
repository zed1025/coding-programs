#include<bits/stdc++.h>
using namespace std;

int findPivot(int *arr, int s, int e) {
    int mid = s+(e-s)/2;

    while(s<e) {
        if(arr[mid] >= arr[0]) { //mid lies on line 1
            s = mid+1;
        } else {
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return s;
}

int binarySearch(int *arr, int s, int e, int key) {
    int mid = s + (e-s)/2;

    while(s<=e) {
        if(arr[mid]==key) {
            return mid;
        }
        if(arr[mid] < key) {
            s = mid+1;
        } else {
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int main() {
    int arr[] = {7,9,1,2,3};
    int key = 1;
    int n = sizeof(arr)/sizeof(arr[0]);
    int pivot = findPivot(arr, 0, 4);

    int index=-1;
    if(arr[n-1] >= key && arr[pivot] <= key) {
        index = binarySearch(arr, pivot, n-1, key);
    } else {
        index = binarySearch(arr, 0, pivot-1, key);
    }

    cout << index << ": " << arr[index] << endl;

    if(index != -1) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }

    return 0;
}
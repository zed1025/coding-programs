#include<bits/stdc++.h>
using namespace std;

void merge(int *, int , int );

void mergeSort(int *arr, int s, int e) {

    //base case
    if(s >= e) {
        return ;
    }

    // //recursive case
    int mid = (e+s)/2;
    //sort left half
    mergeSort(arr, s, mid);
    //sort right half
    mergeSort(arr, mid+1, e);
    //merge two sorted arrays
    merge(arr, s, e);


    // if(s <= e) {
    //     int mid = (e+s)/2;
    //     mergeSort(arr, s, mid);
    //     mergeSort(arr, mid+1, e);
    //     merge(arr, s, e);
    // }
}   

void merge(int *arr, int s, int e) {
    int mid = (s+e)/2;
    int l = mid-s+1;
    int r = e-mid;

    // int L[l];
    // int R[r];
    int *L = new int[l];
    int *R = new int[r];

    int k=s;
    for(int i=0; i<l; i++) {
        L[i] = arr[k++];
    }
    k = mid+1;
    for(int i=0; i<r; i++) {
        R[i] = arr[k++];
    }

    int index1=0, index2=0;
    int mainArrayIndex = s;    
    while(index1 < l && index2 < r) {
        if(L[index1] <= R[index2]) {
            arr[mainArrayIndex++] = L[index1++];
        } else {
            arr[mainArrayIndex++] = R[index2++];
        }
    }

    //handle remaining elements
    while(index1 < l) {
        arr[mainArrayIndex++] = L[index1++];
    }
    while(index2 < r) {
        arr[mainArrayIndex++] = R[index2++];
    }
    delete []L;
    delete []R;
}

int main() {
    int arr[] = {2,5,1,6,9};
    int n=5;
    cout << "Unsorted: ";
    for(int i=0; i<n; i++) {cout << arr[i] << " ";} cout << endl;
    
    mergeSort(arr, 0, n-1);

    cout << "Sorted: ";
    for(int i=0; i<n; i++) {cout << arr[i] << " ";} cout << endl;
    
    return 0;
}
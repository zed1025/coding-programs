/**
WRONG -> TRY TO IMPROVE
WRONG


https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549

Find first and last occurence of an element k in the given array arr, Array can have duplicate elements
If the element does not exist return -1 -1
*/

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int s, int e, int key) {

    //base case
    if(s > e) {
        return -1;
    }
    int mid = s + (e-s)/2;
    if(arr[mid] == key) {
        return mid;
    }

    //recursive case
    if(arr[mid] < key) {
        return binarySearch(arr, mid+1, e, key);
    }
    return binarySearch(arr, s, mid-1, key);
}

pair<int, int> firstLastOccurence(int *arr, int size, int key) {

    // base cases -> covers the case where the element is not present in the array
    int idx = binarySearch(arr, 0, size, key);
    if(idx == -1) {
        return make_pair(-1, -1);
    }

    //for left half
    int temp = binarySearch(arr, 0, size, key); 
    int left = binarySearch(arr, 0, temp-1, key);

    //for right half

}

int main() {
    int arr[] = {0, 0, 1, 1, 2, 2, 2, 2};
    int size = 8;
    int key = 2;

    pair<int, int> ans = firstLastOccurence(arr, size, key);

}
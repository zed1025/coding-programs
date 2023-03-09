#include<bits/stdc++.h>
using namespace std;

int findPivot(int *arr, int size) {

    int s=0, e=size-1;
    int mid = s + (e-s)/2;

    while(s<e) {
        if(arr[mid] >= arr[0]) { //mid lies on line 1 -> push s to mid+1
            s = mid+1;
        } else {
            e = mid; // why not mid-1, same reason as peak_in_mountain question
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int main() {
    int arr[] = {3,8,10,17,1};
    int size = 5;

    int pivot = findPivot(arr, size);

    cout << "Pivot is: " << pivot << endl;
}
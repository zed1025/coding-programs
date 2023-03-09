//https://youtu.be/sNaHN4tZmRk
//inplace? => yes
//stable? => default implementation not stale
//3 way quick sort, if array contains duplicate entried for multiple elements
//iterative quick sort possible? => yes
//quick sort for linked lists => https://www.geeksforgeeks.org/quick-sort/


#include<bits/stdc++.h>
using namespace std;

//functions
int partition(int *arr, int s, int e) {
    int pivot = arr[s];
    int count=0;
    for(int i=s+1; i<=e; i++) {
        if(arr[i] < pivot) {
            count++;
        }
    }

    //place pivot at its correct position
    int pivotIndex = s+count;
    swap(arr[pivotIndex], arr[s]);

    int i = s;
    int j = e;
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] < pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int *arr, int s, int e) {
    //base case
    if(s>=e) {
        return ;
    }

    int p = partition(arr, s, e);

    //recursive calls
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main() {
    int arr[] = {2, 4, 1, 6, 9};
    int n=5;

    cout << "Unsorted: ";
    for(int i=0; i<n; i++) {cout << arr[i] << " ";} cout << endl;
    
    quickSort(arr, 0, n-1);

    cout << "Sorted: ";
    for(int i=0; i<n; i++) {cout << arr[i] << " ";} cout << endl;
    return 0;
}